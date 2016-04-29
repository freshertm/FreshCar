#ifndef RENDERER_H
#define RENDERER_H

#include "v2renderer.h"
#include "v2eventhandler.h"
#include <QObject>

class WorldObject;
class V2Camera;
class Renderer: public V2Renderer
{
    Q_OBJECT
public:
    Renderer();
    virtual ~Renderer(){}

private slots:
    void windowPaintReady();
    void resizeEvent(int width, int height);

protected:
    virtual void initObjectData(WorldObject * object);
    virtual void processObject(WorldObject*obj);
private slots:
    void onCameraChanged(const V2Camera& newCamera);
private:

    V2Camera *_camera;
};

#endif // RENDERER_H
