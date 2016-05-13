#ifndef V2WINDOW_H
#define V2WINDOW_H

#include "imodule.h"
#include "qdebug.h"

class QMouseEvent;
class QWheelEvent;
class V2Window: public IModule
{
    Q_OBJECT
public:
    V2Window();
    virtual ~V2Window();

    virtual void init(){}
    virtual void finalize(){}
    virtual void swapBuffers(){}

    virtual int width()=0;
    virtual int height()=0;

signals:
    void resizeSignal(int width, int height);
    void closeSignal();
    void showSignal();
    void mouseMoveSignal(const QMouseEvent*);
    void wheelSignal(const QWheelEvent*);
    void paintReadySignal();
};

#endif // V2WINDOW_H
