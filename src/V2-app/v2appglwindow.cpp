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

int v2appGLWindow::width()
{
    return pImpl->width();
}

int v2appGLWindow::height()
{
    return pImpl->height();
}

QWidget *v2appGLWindow::widget()
{
    return pImpl;
}



void v2appGLWindowImpl::wheelEvent(QWheelEvent * ev)
{
    emit wheelSignal(ev);
    ev->accept();
}

void v2appGLWindowImpl::mouseMoveEvent(QMouseEvent * event)
{
    emit mouseMoveSignal(event);
    event->accept();
}

void v2appGLWindowImpl::mousePressEvent(QMouseEvent * ev)
{
    emit mousePressSignal(ev);
    ev->accept();
}

void v2appGLWindowImpl::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseReleaseEvent(ev);
    ev->accept();
}
