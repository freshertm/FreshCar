#include "renderwidget.h"
#include "renderer.h"
#include <QTimer>
#include <QWheelEvent>
#include <QMouseEvent>


RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(parent),
    xShift(0),
    yShift(0),
    scale(1.0),
    _world(new World())
{
    /*
        enum
        {
                e_shapeBit				= 0x0001,	///< draw shapes
                e_jointBit				= 0x0002,	///< draw joint connections
                e_aabbBit				= 0x0004,	///< draw axis aligned bounding boxes
                e_pairBit				= 0x0008,	///< draw broad-phase pairs
                e_centerOfMassBit		= 0x0010	///< draw center of mass frame

       };
*/
    SetFlags(e_shapeBit);
    _history = new History(_world);

    //setAutoBufferSwap(false);
    //glt.start();
}

void RenderWidget::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < vertexCount; ++i)
    {
        glVertex2f(vertices[i].x, vertices[i].y);
    }
    glEnd();
}

void RenderWidget::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color)
{
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int32 i = 0; i < vertexCount; ++i)
    {
        glVertex2f(vertices[i].x, vertices[i].y);
    }
    glEnd();
    glDisable(GL_BLEND);

    glColor4f(color.r, color.g, color.b, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < vertexCount; ++i)
    {
        glVertex2f(vertices[i].x, vertices[i].y);
    }
    glEnd();
}

void RenderWidget::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color)
{
    const float32 k_segments = 16.0f;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x, v.y);
        theta += k_increment;
    }
    glEnd();
}

void RenderWidget::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color)
{
    const float32 k_segments = 16.0f;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    glEnable(GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f * color.r, 0.5f * color.g, 0.5f * color.b, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int32 i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x, v.y);
        theta += k_increment;
    }
    glEnd();
    glDisable(GL_BLEND);

    theta = 0.0f;
    glColor4f(color.r, color.g, color.b, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int32 i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertex2f(v.x, v.y);
        theta += k_increment;
    }
    glEnd();

    b2Vec2 p = center + radius * axis;
    glBegin(GL_LINES);
    glVertex2f(center.x, center.y);
    glVertex2f(p.x, p.y);
    glEnd();
}

void RenderWidget::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color)
{
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
}

void RenderWidget::DrawTransform(const b2Transform &xf)
{
    b2Vec2 p1 = xf.p, p2;
    const float32 k_axisScale = 0.4f;
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(p1.x, p1.y);
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    glVertex2f(p2.x, p2.y);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(p1.x, p1.y);
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    glVertex2f(p2.x, p2.y);

    glEnd();
}

World *RenderWidget::world()
{
    return _world;
}

void RenderWidget::drawGL()
{

}

void RenderWidget::initializeGL()
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    _world->b2world()->SetDebugDraw(this);
}

void RenderWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    screenWidth = w;
    screenHeight = h;
    setProjectionMatrix();
}

void RenderWidget::resizeEvent(QResizeEvent *evt)
{
       //glt.resizeViewport(evt->size());
    QGLWidget::resizeEvent(evt);
}

void RenderWidget::paintGL()
{

    _world->step();

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    _world->b2world()->DrawDebugData();

    renderText(10,15,"World top record: "+QString::number(_world->absoluteMaxDistance(),'f',1));

    renderText(10,30,"World current record: "+QString::number(_world->currentTopCarPosition(),'f',1));

    renderText(10,45,"Population: "+ QString::number(_world->currentPopulation()));

    renderText(10,60,"Generation: "+ QString::number(_world->generationNumber()));
    renderText(10,75,"Generation of top car: "+ QString::number(_world->generationNumberTopRecord()));
    renderText(10,90,"Average triangle count: "+ QString::number(_world->averageTrianglesInCar(),'f',1));
    renderText(10,105,"Average wheel count: "+ QString::number(_world->averageWheelsInCar(),'f',1));

    renderText(1000,0,0,"1000");
    renderText(2000,0,0,"2000");
    renderText(3000,0,0,"3000");
    renderText(4000,0,0,"4000");

    /*foreach(Car * car, _world->carList())
    {
        //renderText(car->position().x, car->position().y-10,0,QString::number(car->currentDistance(),'f',1));
        renderText(car->position().x, car->position().y-10,0,QString::number(car->triangles()));
    }*/

    paintHistory();

    glFinish();
    glFlush();

    //QTimer::singleShot(50,this,SLOT(updateGL()));
    QTimer::singleShot(50,this,SLOT(update()));
}

void RenderWidget::wheelEvent(QWheelEvent * ev)
{
    const double step = 0.2;
    QGLWidget::wheelEvent(ev);
    double delta = (ev->delta() > 0)?1.0+step:1.0-step;
    scale *= delta;
    setProjectionMatrix();
}

void RenderWidget::mousePressEvent(QMouseEvent * ev)
{
    mousePress = QPoint(ev->x(), ev->y());
}

void RenderWidget::mouseMoveEvent(QMouseEvent * ev)
{
    QPoint mousePos = QPoint(ev->x(), ev->y());
    mouseShift = (mousePress - mousePos) * scale;
    setProjectionMatrix(mouseShift.x() + xShift,
                        -mouseShift.y() + yShift);
}

void RenderWidget::mouseReleaseEvent(QMouseEvent * ev)
{
    QPoint mousePos = QPoint(ev->x(), ev->y());
    mouseShift = (mousePress - mousePos) * scale;
    xShift += mouseShift.x();
    yShift += - mouseShift.y();
    setProjectionMatrix();
}

void RenderWidget::setProjectionMatrix()
{
    setProjectionMatrix(xShift,yShift);
}

void RenderWidget::setProjectionMatrix(double xShift, double yShift)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-100+xShift,100+xShift,-100+yShift,100+yShift,-1,1);
    /*glOrtho((-screenWidth+xShift) * scale, (screenWidth+xShift) * scale,
            (-screenHeight+yShift) * scale, (screenHeight+yShift) * scale,
            -1,1);*/
    _screenLeft = xShift - screenWidth  * scale;
    _screenRight = xShift + screenWidth  * scale;
    _screenBottom = yShift - screenHeight * scale;
    _screenTop = yShift + screenHeight * scale;

    glOrtho(_screenLeft,  _screenRight,
            _screenBottom, _screenTop,
                -1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderWidget::drawLine(double x1, double y1, double x2, double y2)
{

    glBegin(GL_LINES);
        glVertex3f(x1, y1,0);
        glVertex3f(x2, y2,0);
        glEnd();
}

void RenderWidget::drawRectangle(double x1, double y1, double x2, double y2)
{
    glBegin(GL_LINE_STRIP);
        glVertex2f(x1,y1);
        glVertex2f(x2,y1);
        glVertex2f(x2,y2);
        glVertex2f(x1,y2);
        glVertex2f(x1,y1);
        glEnd();
}
/*
void RenderWidget::drawHistoryBox(const QRect position, const QList<HistoryData &> &data, QString desc)
{
    if (data.isEmpty()) return;
}
*/
bool RenderWidget::isInScreen(double x, double y)
{
    if (    (x > _screenLeft) &&
            (x < _screenRight) &&
            (y < _screenTop) &&
            (y > _screenBottom)) return true;
    return false;
}



void RenderWidget::paintHistory()
{
    if (_history->history().count() < 2) return;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,screenWidth,0,screenHeight,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glDisable(GL_DEPTH_TEST);

    const double graphWidth = screenWidth / 3.0;
    double step = graphWidth /( (double)(_history->history().count()-1.0));

    const int graphHeight = 200;

    const double topRecordMultiplier = ((double) graphHeight) / _world->absoluteMaxDistance();
    const double trianglesMultiplier = ((double)graphHeight) / ((double)_world->worldProperties()->genomeBodyLength());
    const double wheelsMultiplier = ((double) graphHeight) / ((double) _world->worldProperties()->genomeMaxWheels());


    //double topRecordsPoint[_history->history().count()];

    glColor3f(1,1,1);
    drawRectangle(1,1,graphWidth,graphHeight);
    drawRectangle(graphWidth,1,
                  graphWidth*2,graphHeight);
    drawRectangle(graphWidth*2,1,
                  graphWidth*3,graphHeight);

    // descriptions
    glColor3f(1,0,0);
    renderText(1, 1, 0, "WorldTop");

    glColor3f(1,1,0);
    renderText(1, 20, 0, "WorldCurrent");

    glColor3f(1,1,1);
    renderText(graphWidth, 1, 0, "avgTriangles");

    glColor3f(1,0,1);
    renderText(graphWidth + graphWidth, 1, 0, "avgWheels");

    //graphs
    for (int i=0; i<_history->history().count() - 1; ++i)
    {
        History::HistoryRecord rec = _history->history()[i];
        History::HistoryRecord recNext = _history->history()[i+1];

        glColor3f(1,0,0);
        drawLine(((double)i) * step, rec.worldTopRecord * topRecordMultiplier,
                 ((double)i+1.0) * step, recNext.worldTopRecord * topRecordMultiplier);

        glColor3f(1,1,0);
        drawLine(((double)i) * step, rec.worldCurrentRecord * topRecordMultiplier,
                 ((double)i+1.0) * step, recNext.worldCurrentRecord * topRecordMultiplier);

        glColor3f(1,1,1);
        drawLine(((double)i) * step + graphWidth, rec.avgTriangles * trianglesMultiplier,
                 ((double)i+1.0) * step + graphWidth, recNext.avgTriangles * trianglesMultiplier);

        glColor3f(1,0,1);
        drawLine(((double)i) * step + graphWidth *2, rec.avgWheelsCount * wheelsMultiplier,
                 ((double)i+1.0) * step + graphWidth *2, recNext.avgWheelsCount * wheelsMultiplier);
    }

    //glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
