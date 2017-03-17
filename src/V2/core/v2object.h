#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include <QList>
#include "v2geometry.h"
#include "v2resource.h"
#include <QObject>
#include <glm/glm.hpp>
#include <QSharedPointer>

class V2Module;

class V2ObjectAgent{
public:
    virtual ~V2ObjectAgent(){}
};

class V2Object: public QObject
{
    Q_OBJECT
public:
    V2Object();
    ~V2Object();

    const Geometry * geometry();

    void setPosition(const glm::vec3& newPosition);
    void setRotation(const glm::vec3& newRotation);
    void setScale(const glm::vec3& newScale);
    const glm::vec3& position() const;
    const glm::vec3& rotation() const;
    const glm::vec3& scale() const;

    template <class T> QSharedPointer<T>& agent() const;
    template <class T> void addAgent(QSharedPointer<T>&);

signals:
    void positionChanged(const glm::vec3 & newPosition);
    void rotationChanged(const glm::vec3 & newRotation);
    void scaleChanged(const glm::vec3 & newScale);

private:   
    glm::vec3 _position;
    glm::vec3 _rotation;
    glm::vec3 _scale;
    QMap<std::type_index, QSharedPointer<V2ObjectAgent>> _agentMap;
};



template <class T> QSharedPointer<T>& V2Object::agent() const{
    if ( _agentMap.find(typeid(T)) != _agentMap.end() ) {
        return qSharedPointerDynamicCast<T>(_agentMap[typeid(T)]);
    }
    return QSharedPointer<T>();
}

template <class T> void V2Object::addAgent(QSharedPointer<T>& agent){
    _agentMap[typeid(T)] = qSharedPointerDynamicCast<V2ObjectAgent>(agent);
}

#endif // WORLDOBJECT_H
