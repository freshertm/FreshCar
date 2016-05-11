#include "v2appglwindow.h"
#include <QWheelEvent>



v2appGLWindow::v2appGLWindow(): pImpl(new v2appGLWindowImpl())
{
    connect(pImpl, &v2appGLWindowImpl::showSignal, this, &V2Window::showSignal);
    connect(pImpl, &v2appGLWindowImpl::resizeSignal, this, &V2Window::resizeSignal);
    connect(pImpl, &v2appGLWindowImpl::paintReadySignal, this, &V2Window::paintReadySignal);
}

v2appGLWindow::~v2appGLWindow()
{

}

QWidget *v2appGLWindow::widget()
{
    return pImpl;
}
/*
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

}

void v2appGLWindow::paintGL()
{

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
}*/

