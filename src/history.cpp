#include "history.h"

History::History(World * world, QObject *parent) :
    QObject(parent), _world(world)
{
    connect(_world,SIGNAL(newGeneration()), this,SLOT(onNewGeneration()));
}

const History::HistoryStore History::history() const
{
    return historyPool;
}

void History::onNewGeneration()
{
    HistoryRecord rec;
    if (_world->topList().isEmpty())
    {
        if (_world->carList().isEmpty()) return;
        double pos = -1000;
        foreach (Car * car, _world->carList())
        {
            if (car->topDistance() > pos) pos = car->topDistance();
        }
        rec.worldCurrentRecord = pos;
    }
    else
        rec.worldCurrentRecord = _world->topList()[0].first;
    rec.worldTopRecord = _world->absoluteMaxDistance();
    rec.avgWheelsCount = _world->averageWheelsInCar();
    rec.avgTriangles = _world->averageTrianglesInCar();
    historyPool.push_back(rec);
}
