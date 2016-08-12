#ifndef V2SCENE_H
#define V2SCENE_H

#include <QList>
#include <QObject>


class V2Object;
class V2Scene: public QObject
{
    Q_OBJECT
public:
    V2Scene();
    ~V2Scene();

    void addObject(V2Object *);
    const QList<V2Object*> objects();

signals:
    void objectAdded(V2Object*);
    //void objectRemoved(WorldObject*);

private:
    QList<V2Object*> _objects;
};

#endif // V2SCENE_H
