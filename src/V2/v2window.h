#ifndef V2WINDOW_H
#define V2WINDOW_H

#include "imodule.h"
#include "qdebug.h"
#include <QObject>

class QMouseEvent;
class QWheelEvent;
class V2Window: public QObject, public IModule
{
    Q_OBJECT
public:
    V2Window();
    virtual ~V2Window();

    virtual void init(){}
    virtual void finalize(){}
    virtual void swapBuffers(){}
    virtual void setSize(int width, int height);

signals:
    void resizeSignal(int width, int height);
    void closeSignal();
    void showSignal();
    void mouseMoveSignal(const QMouseEvent*);
    void wheelSignal(const QWheelEvent*);
    void paintReadySignal();
};

#endif // V2WINDOW_H
