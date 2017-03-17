#ifndef IMODULE_H
#define IMODULE_H

#include <QList>
#include <QObject>
#include <typeindex>

class ObjectData;
class V2Object;

class ModuleData{};
class V2Engine;

class V2Module: public QObject
{
    Q_OBJECT
public:
    V2Module();
    virtual ~V2Module(){}

    virtual QList<std::type_index> dependencies() const;

    /**
     * Tries to initialize module.
     * @returns true if successfully initialized.
     * */
    bool init(QSharedPointer<V2Engine> &);
    /**
     * Tries to stop module.
     * @returns true if module successfully deactivated.
     * */
    bool stop(QSharedPointer<V2Engine> &);

    bool initialized() { return _initialized;}

    bool enable(QSharedPointer<V2Engine> &);
    bool disable(QSharedPointer<V2Engine> &);
    bool enabled();

    /** Add reference to module to prevent unloading. */
    void addRef();

    /** release reference. */
    void release();

    /** get current reference counter. **/
    quint32 refs();
protected:
    virtual bool initModule(QSharedPointer<V2Engine>&) {return true;}
    virtual bool stopModule(QSharedPointer<V2Engine>&) {return true;}
    virtual bool enableModule(QSharedPointer<V2Engine>&){return true;}
    virtual bool disableModule(QSharedPointer<V2Engine>&){return true;}
private:
    quint32 _refs;
    bool _enabled;
    bool _initialized;
};

#endif // IMODULE_H

