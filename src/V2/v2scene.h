#ifndef V2SCENE_H
#define V2SCENE_H

#include <QList>
#include <QObject>


class WorldObject;
class V2Scene: public QObject
{
    Q_OBJECT
public:
    V2Scene();
    ~V2Scene();

    void addObject(WorldObject *);
    const QList<WorldObject*> objects();

signals:
    void objectAdded(WorldObject*);
    //void objectRemoved(WorldObject*);

private:
    QList<WorldObject*> _objects;
};

#endif // V2SCENE_H
