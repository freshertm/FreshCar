#ifndef V2SCENE_H
#define V2SCENE_H

#include <QList>
#include <QObject>
#include "v2object.h"

class V2Scene: public QObject
{
    Q_OBJECT
public:
    V2Scene();
    ~V2Scene();

    void addObject(QSharedPointer<V2Object>&);
    const QList<QSharedPointer<V2Object>> objects();

signals:
    void objectAdded(QSharedPointer<V2Object>&);
    //void objectRemoved(WorldObject*);

private:
    QList<QSharedPointer<V2Object>> _objects;
};

#endif // V2SCENE_H
