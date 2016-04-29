#ifndef RENDERER_H
#define RENDERER_H

#include "imodule.h"
#include "v2eventhandler.h"
#include <QObject>

class WorldObject;
class V2Camera;
class Renderer:  public QObject, public IModule
{
    Q_OBJECT
public:
    Renderer();

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
