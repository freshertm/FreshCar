#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QGLWidget>
#include "World.h"
#include "Box2D.h"
#include "historygraph.h"
#include "glthread.h"

class Renderer;

class RenderWidget : public QGLWidget, public b2Draw
{
    Q_OBJECT
public:
    explicit RenderWidget(World * world, QWidget *parent = 0);



    /// Draw a closed polygon provided in CCW order.
    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    /// Draw a solid closed polygon provided in CCW order.
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);

    /// Draw a circle.
    virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);

    /// Draw a solid circle.
    virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);

    /// Draw a line segment.
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);

    /// Draw a transform. Choose your own length scale.
    /// @param xf a transform.
    virtual void DrawTransform(const b2Transform& xf);

    World *world();


    void drawGL();
    bool drawHistoryGraphs();

public slots:
    void setDrawGraphs(bool enabled);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void wheelEvent(QWheelEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void resizeEvent(QResizeEvent *);

private:
    World* _world;
    Renderer * renderer;
    bool _drawHistoryGraph;
    double xShift;
    double yShift;
    double scale;
    void setProjectionMatrix();
    void setProjectionMatrix(double xShift, double yShift);
    void paintHistory();
    void drawLine(double x1, double y1, double x2, double y2);
    void drawRectangle(double x1, double y1, double x2, double y2);

   // void drawHistoryBox(const QRect position, const QList<HistoryData &> &data, QString desc);
    int screenWidth;
    int screenHeight;
    QPoint mousePress;
    QPoint mouseShift;

    History * _history;

    double _screenLeft;
    double _screenRight;
    double _screenTop;
    double _screenBottom;

    bool isInScreen(double x, double y);

    //GLThread glt;
};

#endif // RENDERWIDGET_H
