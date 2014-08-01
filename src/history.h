#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include "world.h"
#include <QVector>

class History : public QObject
{
    Q_OBJECT
public:
    explicit History(World * world, QObject *parent = 0);

    struct HistoryRecord
    {
        double worldTopRecord;
        double worldCurrentRecord;
        double avgWheelsCount;
        double avgTriangles;
    };

    typedef QVector<HistoryRecord> HistoryStore;

    const HistoryStore history() const;

private:
    HistoryStore historyPool;

    World * _world;

private slots:
    void onNewGeneration();
};


typedef QVector<double> HistoryData;

#endif // HISTORYGRAPH_H
