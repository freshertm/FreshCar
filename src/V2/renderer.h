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

protected:
    //virtual void initObjectData(WorldObject * object);
    //void processObject(WorldObject*obj);

private slots:
    void onCameraChanged(const V2Camera& newCamera);
    void onSceneChanged(V2Scene *);
    void onObjectAddedToScene(WorldObject *);

private:
    V2Window * _window;
    V2Camera *_camera;

    QMetaObject::Connection _sceneConnection;

    QHash<WorldObject*, RenderData *> _cachedObjectData;

private:
    void processObject(WorldObject *);
};

#endif // RENDERER_H
