#include "v2appglwindow.h"
#include "v2event.h"
#include "v2event_classes.h"
#include <QWheelEvent>

v2appGLWindow::v2appGLWindow()
{

}

v2appGLWindow::~v2appGLWindow()
{

}

void v2appGLWindow::init()
{
}

void v2appGLWindow::finalize()
{
}

void v2appGLWindow::swapBuffers()
{
    QGLWidget::swapBuffers();
}

void v2appGLWindow::initializeGL()
{
    emit showSignal();
}

void v2appGLWindow::resizeGL(int w, int h)
{
    emit resizeSignal(w,h);
}

void v2appGLWindow::paintGL()
{
    emit paintReadySignal();
}

void v2appGLWindow::wheelEvent(QWheelEvent * w)
{
    emit wheelSignal(w);
}

void v2appGLWindow::mousePressEvent(QMouseEvent *)
{   
}

void v2appGLWindow::mouseMoveEvent(QMouseEvent * event)
{
    emit mouseMoveEvent(event);
}

void v2appGLWindow::mouseReleaseEvent(QMouseEvent *)
{
}

