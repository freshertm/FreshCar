#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include <QObject>
#include "v2scene.h"
#include <typeindex>
#include <QMap>

class V2Engine: public QObject, public QEnableSharedFromThis<V2Engine>
{
    Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    template <class T> QSharedPointer<T> module();

    QSharedPointer<V2Module> moduleByType(const std::type_index & ti);

    template <class T> bool initModule();

    bool initModule(QSharedPointer<V2Module>& module);

    template <class T> bool stopModule(){}

    template <class T> bool enableModule();
    template <class T> bool disableModule();

    QSharedPointer<V2Scene> scene();

    template <class T>void addModule(QSharedPointer<T>&);

public slots:
    void setScene(QSharedPointer<V2Scene> &);
    //void addModule(V2Module*);

    bool unregisterModule(std::type_index &t);
signals:
    void sceneChanged(QSharedPointer<V2Scene>&);
    void moduleAdded(QSharedPointer<V2Module>&);
    void moduleInitialized(QSharedPointer<V2Module>&);

private:
    QMap<std::type_index, QSharedPointer<V2Module> > _modulesMap;
    //QList<V2Module*> _modules;
    QSharedPointer<V2Scene> _scene;
};

template <class T>
QSharedPointer<T> V2Engine::module()
{
    auto module = moduleByType(typeid(T));
    if (!module.isNull()) {
        return qSharedPointerDynamicCast<T>(module);
    }

    for(auto &k : _modulesMap) {
        auto &module = qSharedPointerDynamicCast<T>(k);
        if (!module.isNull()) {
            return module;
        }
    }
    return QSharedPointer<T>();
}


template <class T> bool V2Engine::initModule()
{
    auto m = this->module<T>();
    auto module = qSharedPointerDynamicCast<V2Module>(m);
    return initModule(module);
}


template <class T> bool V2Engine::enableModule()
{
    auto m = this->module<T>();
    if (!m.isNull()) {
        return m->enable(sharedFromThis());
    }
    return false;
}

template <class T> bool V2Engine::disableModule()
{
    auto m = this->module<T>();
    if (m.isNull()) {
        return m->disable(sharedFromThis());
    }
    return false;
}

template <class T> void V2Engine::addModule(QSharedPointer<T>& module)
{
    if (module.isNull()) return;
    QSharedPointer<V2Module> genericModule = qSharedPointerDynamicCast<V2Module>(module);

    _modulesMap[typeid(T)] = genericModule;
    emit moduleAdded(genericModule);
}

#endif // ENGINE_H
