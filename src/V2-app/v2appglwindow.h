#ifndef V2APPGLWINDOW_H
#define V2APPGLWINDOW_H

#include "v2window.h"
#include <QGLWidget>

class v2appGLWindow : public V2Window, public QGLWidget
{
    Q_OBJECT
public:
    v2appGLWindow();
    virtual ~v2appGLWindow();

    virtual void init();
    virtual void finalize();
    virtual void swapBuffers();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void wheelEvent(QWheelEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void resizeEvent(QResizeEvent *);
};

#endif // V2APPGLWINDOW_H
