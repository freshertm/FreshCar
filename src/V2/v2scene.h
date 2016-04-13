#ifndef V2SCENE_H
#define V2SCENE_H

#include <QList>

class WorldObject;
class V2Scene
{
public:
    V2Scene();
    ~V2Scene();

    void addObject(WorldObject *);
    const QList<WorldObject*> objects();

private:
    QList<WorldObject*> _objects;
};

#endif // V2SCENE_H
