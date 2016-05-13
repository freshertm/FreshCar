#ifndef V2APPGLWINDOW_H
#define V2APPGLWINDOW_H

#include "v2window.h"
#include <QGLWidget>

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
    //void mouseMoveSignal(const QMouseEvent*);
    //void wheelSignal(const QWheelEvent*);
    void paintReadySignal();
protected:
    virtual void initializeGL(){emit showSignal();}
    virtual void resizeGL(int w, int h){ emit resizeSignal(w,h); }
    virtual void paintGL(){emit paintReadySignal();}
};

class v2appGLWindow :public V2Window
{
    Q_OBJECT
public:
    v2appGLWindow();
    virtual ~v2appGLWindow();

    virtual int width();
    virtual int height();

  /*  virtual void init();
    virtual void finalize();
    virtual void swapBuffers();*/

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
