#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QTimer>

class GameLogic: public QObject
{
    Q_OBJECT
public:
    GameLogic();

private:
    QTimer updateTimer;


};

#endif // GAMELOGIC_H
