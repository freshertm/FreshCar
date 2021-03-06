#ifndef V2RIGIDBODY2D_H
#define V2RIGIDBODY2D_H

#include <QObject>
#include "v2object.h"
class V2RigidBody2D: public QObject, public V2ObjectAgent {
    Q_OBJECT
public:

    /// The body type.
    /// static: zero mass, zero velocity, may be manually moved
    /// kinematic: zero mass, non-zero velocity set by user, moved by solver
    /// dynamic: positive mass, non-zero velocity determined by forces, moved by solver
    enum BodyType {
        StaticBody,
        KinematicBody,
        DynamicBody
    };

    V2RigidBody2D(BodyType bodyType):_bodyType(bodyType) {}

    float density(){ return _density;}
    void setDensity(float density);


    BodyType bodyType(){return _bodyType;}

signals:
    void changed();

private:
    float _density;
    BodyType _bodyType;
};

#endif // V2RIGIDBODY2D_H
