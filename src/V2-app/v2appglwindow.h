#ifndef V2APPGLWINDOW_H
#define V2APPGLWINDOW_H

#include "v2window.h"
#include <QGLWidget>
#include <QTimer>

class v2appGLWindowImpl: public QGLWidget
{
    Q_OBJECT
public:
    //int width();
    //int height();
signals:
    void resizeSignal(int width, int height);
    //void closeSignal();
    void showSignal();
    void mouseMoveSignal(const QMouseEvent*);
    void wheelSignal(const QWheelEvent*);
    void mousePressSignal(QMouseEvent *);
    void mouseMoveSignal(QMouseEvent *);
    void mouseReleaseSignal(QMouseEvent *);
    void paintReadySignal();
protected:
    virtual void initializeGL(){emit showSignal();}
    virtual void resizeGL(int w, int h){ emit resizeSignal(w,h); }
    virtual void paintGL(){
        emit paintReadySignal();
        QTimer::singleShot(1, this, &v2appGLWindowImpl::updateGL);
    }

    virtual void wheelEvent(QWheelEvent * ev);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

};

class v2appGLWindow :public V2Window
{
    Q_OBJECT
public:
    v2appGLWindow();
    virtual ~v2appGLWindow();

    virtual int width();
    virtual int height();

    QWidget * widget();

protected:
   /* virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void wheelEvent(QWheelEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);   */

private:
    v2appGLWindowImpl *pImpl;
};

#endif // V2APPGLWINDOW_H
