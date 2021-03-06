#ifndef V2WINDOW_H
#define V2WINDOW_H

#include "v2module.h"
#include "qdebug.h"

class QMouseEvent;
class QWheelEvent;
class V2Window: public V2Module
{
    Q_OBJECT
public:
    V2Window();
    virtual ~V2Window();

    virtual void swapBuffers(){}

    virtual int width()=0;
    virtual int height()=0;

signals:
    void resizeSignal(int width, int height);
    void closeSignal();
    void showSignal();
    void mouseMoveSignal(const QMouseEvent*);
    void mousePressSignal(const QMouseEvent*);
    void mouseReleaseSignal(const QMouseEvent*);
    void wheelSignal(const QWheelEvent*);
    void paintReadySignal();
};

#endif // V2WINDOW_H
