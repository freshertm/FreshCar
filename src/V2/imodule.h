#ifndef IMODULE_H
#define IMODULE_H

#include <QList>

class ObjectData;
class WorldObject;

class ModuleData{};
class V2Engine;
class IModule
{
public:
    IModule(){}
    virtual ~IModule(){}

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

    /** Add reference to module to prevent unloading. */
    void addRef();

    /** release reference. */
    void release();

    /** get current reference counter. **/
    quint32 refs();

    void addObject(WorldObject*);
    void removeObject(WorldObject*);

private:
    virtual void initObjectData(WorldObject *){}

protected:
    QList<WorldObject*> _objects;
private:
    quint32 _refs;
};

#endif // IMODULE_H

