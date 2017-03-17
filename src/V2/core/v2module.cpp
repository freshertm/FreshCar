#include "v2module.h"

V2Module::V2Module(): _initialized(false), _enabled(false), _refs(1)
{
    blockSignals(true);
}

QList<std::type_index> V2Module::dependencies() const
{
    return QList<std::type_index>();
}

bool V2Module::init(QSharedPointer<V2Engine> &engine)
{
    if (_initialized) {
        return true;
    }
    _initialized = initModule(engine);
    return _initialized;
}

bool V2Module::stop(QSharedPointer<V2Engine> &engine)
{
    if (!_initialized) {
        return true;
    }
    if (_enabled) {
        return false;
    }

    _initialized = !stopModule(engine);
    return !_initialized;
}

bool V2Module::enable(QSharedPointer<V2Engine> &engine)
{
    if (!initialized()) {
        return false;
    }

    if (enabled()) {
        return true;
    }
    if (enableModule(engine)) {
        _enabled = true;
        blockSignals(false);
        return true;
    }
    return false;
}

bool V2Module::disable(QSharedPointer<V2Engine> &engine)
{
    if (!enabled()) {
        return true;
    }

    if (disableModule(engine)) {
        _enabled = false;
        blockSignals(true);
        return true;
    }
    return false;
}

bool V2Module::enabled()
{
    return _enabled;
}

void V2Module::addRef()
{
    ++_refs;
}

void V2Module::release()
{
    if (_refs) {
        --_refs;
    }
}

quint32 V2Module::refs()
{
    return _refs;
}
