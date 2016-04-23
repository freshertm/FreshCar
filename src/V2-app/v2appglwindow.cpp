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
    V2EventSystem::sendEvent(new V2Event(V2WindowInitializedType));
}

void v2appGLWindow::resizeGL(int w, int h)
{
    V2EventSystem::sendEvent(new V2WindowResizeEvent(w,h));
}

void v2appGLWindow::paintGL()
{
    V2EventSystem::sendEvent(new V2Event(V2WindowPaintReadyType));
}

void v2appGLWindow::wheelEvent(QWheelEvent * w)
{
    V2EventSystem::sendEvent(new V2WheelEvent(w->delta()));
}

void v2appGLWindow::mousePressEvent(QMouseEvent *)
{

}

void v2appGLWindow::mouseMoveEvent(QMouseEvent *)
{

}

void v2appGLWindow::mouseReleaseEvent(QMouseEvent *)
{

}

