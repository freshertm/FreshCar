#ifndef GLTHREAD_H
#define GLTHREAD_H

#include <QThread>
#include <QSize>


class RenderWidget;

class GLThread : public QThread
    {
    public:
        GLThread(RenderWidget *glWidget);
        void resizeViewport(const QSize &size);
        void run();
        void stop();

    private:
        bool doRendering;
        bool doResize;
        int w;
        int h;
        int rotAngle;
        RenderWidget *glw;
    };

#endif // GLTHREAD_H
