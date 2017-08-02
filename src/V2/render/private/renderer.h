#ifndef RENDERER_H
#define RENDERER_H

#include "v2renderer.h"
#include <QObject>
#include <QHash>
#include "v2window.h"
#include "v2Camera.h"
#include "v2lightmanager.h"


class V2Object;
class V2Scene;
class RenderData;
class Renderer: public V2Renderer
{
    Q_OBJECT
public:
    Renderer();
    virtual ~Renderer(){}

    //virtual QList<std::type_index> dependencies() const;

protected:
    virtual bool initModule(QSharedPointer<V2Engine>&);
    virtual bool stopModule(QSharedPointer<V2Engine> &);

    virtual bool enableModule(QSharedPointer<V2Engine>&);
    virtual bool disableModule(QSharedPointer<V2Engine>&);

private slots:
    void windowPaintReady();
    void resizeEvent(int width, int height);

private slots:   
    void onSceneChanged(QSharedPointer<V2Scene> &);
    void onObjectAddedToScene(const QSharedPointer<V2Object> &);

    void onCameraChanged(const QSharedPointer<V2Camera> &newCamera);
    void onCameraMove(const QSharedPointer<V2Camera>&);

    void onLightSettingsChanged();

private:
    QSharedPointer<V2Window> _window;
    QSharedPointer<V2Camera> _camera;

    QMap<QSharedPointer<V2Object>, QSharedPointer<RenderData>> _cachedObjectData;

private:
    void processObject(const QSharedPointer<V2Object> &);
    void updateLightSettings();

    QSharedPointer<V2Camera> _currentCamera;
    QSharedPointer<V2LightManager> _lightManager;

    bool _lightManagerSettingsChanged = true;
    bool _globalLightingEnable = false;
};

#endif // RENDERER_H
