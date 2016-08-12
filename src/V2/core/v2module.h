#ifndef IMODULE_H
#define IMODULE_H

#include <QList>
#include <QObject>

class ObjectData;
class V2Object;

class ModuleData{};
class V2Engine;
class V2Module: public QObject
{
    Q_OBJECT
public:
    V2Module(){}
    virtual ~V2Module(){}

    /**
     * Tries to initialize module.
     * @returns true if successfully initialized.
     * */
    virtual bool init(V2Engine*){return true;}
    /**
     * Tries to stop module.
     * @returns true if module successfully deactivated.
     * */
    virtual bool stop(V2Engine*){return true;}

    bool enable(V2Engine*);
    bool disable(V2Engine*);
    bool enabled();

    /** Add reference to module to prevent unloading. */
    void addRef();

    /** release reference. */
    void release();

    /** get current reference counter. **/
    quint32 refs();
protected:
    virtual bool enableModule(V2Engine*){return true;}
    virtual bool disableModule(V2Engine*){return true;}
private:
    quint32 _refs;
    bool _enabled;
};

#endif // IMODULE_H

