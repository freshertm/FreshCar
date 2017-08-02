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
    void mousePressSignal(const QMouseEvent *);
    void mouseReleaseSignal(const QMouseEvent *);
    void paintReadySignal();
protected:
    virtual void initializeGL(){emit showSignal();}
    virtual void resizeGL(int w, int h){ emit resizeSignal(w,h); }
    virtual void paintGL(){
        emit paintReadySignal();
        QTimer::singleShot(10, this, &QGLWidget::updateGL);
        //updateGL();
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

private:
    v2appGLWindowImpl *pImpl;
};

#endif // V2APPGLWINDOW_H
