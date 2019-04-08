#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include <QObject>

#include "gameobject.h"

class GameObjectFactory : public QObject
{
    Q_OBJECT
public:
    explicit GameObjectFactory(QObject *parent = nullptr);

    GameObject* create


signals:

public slots:
};

#endif // GAMEOBJECTFACTORY_H
