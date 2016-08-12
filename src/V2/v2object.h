#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include <QList>
#include "geometry.h"
#include "v2resource.h"
#include <QObject>
#include <glm.hpp>

class IModule;
class V2Object: public QObject, public V2ResourceContainer
{
    Q_OBJECT
public:
    V2Object();
    ~V2Object();

    const Geometry * geometry();

    void setPosition(const glm::vec3& newPosition);
    void setRotation(const glm::vec3& newRotation);
    void setScale(const glm::vec3& newScale);
    const glm::vec3& position();
    const glm::vec3& rotation();
    const glm::vec3& scale();
signals:
    void positionChanged(const glm::vec3 & newPosition);
    void rotationChanged(const glm::vec3 & newRotation);
    void scaleChanged(const glm::vec3 & newScale);

private:   
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
};

#endif // WORLDOBJECT_H
