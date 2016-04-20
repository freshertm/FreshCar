#ifndef HISTORYGRAPH_H
#define HISTORYGRAPH_H

#include "history.h"
#include <QColor>

class HistoryGraph
{
public:
    HistoryGraph(History * history);


public:
    void paint(double x, double y, double width, double height);

private:
    History * _history;

    void drawLine(double x1, double y1, double x2, double y2);
};

#endif // HISTORYGRAPH_H
