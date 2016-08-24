#ifndef WORLD_H
#define WORLD_H

#include <QObject>

class V2Engine;
class World : public QObject
{
    Q_OBJECT
public:
    explicit World(V2Engine* engine, QObject *parent = 0);

signals:

public slots:

private:
    V2Engine *_engine;
};

#endif // WORLD_H
