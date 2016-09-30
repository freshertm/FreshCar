#ifndef RENDERER_H
#define RENDERER_H

#include "v2renderer.h"
#include <QObject>
#include <QHash>

class V2Window;

class V2Object;
class V2Camera;
class V2Scene;
class RenderData;
class Renderer: public V2Renderer
{
    Q_OBJECT
public:
    Renderer();
    virtual ~Renderer(){}

    virtual QList<std::type_index> dependencies() const;

protected:
    virtual bool initModule(V2Engine*);
    virtual bool stopModule(V2Engine *);

    virtual bool enableModule(V2Engine *);
    virtual bool disableModule(V2Engine *);

private slots:
    void windowPaintReady();
    void resizeEvent(int width, int height);

private slots:   
    void onSceneChanged(V2Scene *);
    void onObjectAddedToScene(V2Object *);

    void onCameraChanged(V2Camera *newCamera);
    void onCameraMove(V2Camera *);

private:
    V2Window * _window;
    V2Camera *_camera;

    QHash<V2Object*, RenderData *> _cachedObjectData;

private:
    void processObject(V2Object *);

    V2Camera* _currentCamera;
};

#endif // RENDERER_H
