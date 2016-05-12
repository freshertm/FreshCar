#ifndef RENDERER_H
#define RENDERER_H

#include "v2renderer.h"
#include <QObject>
#include <QHash>

class V2Window;

class WorldObject;
class V2Camera;
class V2Scene;
class RenderData;
class Renderer: public V2Renderer
{
    Q_OBJECT
public:
    Renderer();
    virtual ~Renderer(){}
    virtual bool init(V2Engine*);
    virtual bool stop(V2Engine *);

private slots:
    void windowPaintReady();
    void resizeEvent(int width, int height);

private slots:   
    void onSceneChanged(V2Scene *);
    void onObjectAddedToScene(WorldObject *);

    void onCameraChanged(const V2Camera* newCamera);
    void onCameraMove();

private:
    V2Window * _window;
    V2Camera *_camera;

    QHash<WorldObject*, RenderData *> _cachedObjectData;

private:
    void processObject(WorldObject *);

    V2Camera* _currentCamera;
};

#endif // RENDERER_H
