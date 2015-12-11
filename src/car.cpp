#include "car.h"
#include "carbodycreator.h"
#include "world.h"


struct CarWheel
{
    int verticeId;
    double wheelRadius;
    double wheelTorqueCoeff;
    double wheelSpeed;
};


Car::Car(const CarGenome& genome,World * world, const b2Vec2 &position, double angle, quint32 generation):
    body(NULL),
    carGenome(genome),
    world(world),
    waitTime(0),
    maxPosition(position.x),
    _generation(generation)
{
    Q_ASSERT(world !=0);

    CarBodyCreator creator(genome,world);
    _vertices = creator.verticeList().count();

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x,position.y);
    bodyDef.angle = 0.0f; //angle;

    body = world->b2world()->CreateBody(&bodyDef);

    Q_ASSERT(body !=0);

    bodyList.push_back(body);
    _triangles = creator.triangleList().count();
    foreach(CarBodyCreator::Triangle triangle, creator.triangleList())
    {
        b2PolygonShape dynamicBox;
        //dynamicBox.SetAsBox(genome[0].toDouble(),genome[1].toDouble());

        b2Vec2 triVertices[3];
        for (int i=0; i< 3; ++i){
            triVertices[i] = creator.verticeList()[triangle.verticesID[i] ];
        }

        dynamicBox.Set(triVertices,3);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = world->worldProperties()->bodyFriction();
        fixtureDef.restitution = 0.0f;
        fixtureDef.filter.categoryBits =1;
        fixtureDef.filter.maskBits = 2;
        body->CreateFixture(&fixtureDef);
    }



    QVector<CarWheel> wheelsArray;
    _wheels = 0;
    for (int i=0; i< world->worldProperties()->genomeMaxWheels(); ++i)
    {
        int verticeId = genome[world->worldProperties()->genomeBodyLength() + i * 4 + 0].toUInt();
        if (verticeId == 0) continue;
        --verticeId;
        if (verticeId >= creator.verticeList().count()) continue;
        ++_wheels;

        CarWheel w;
        w.verticeId = verticeId;
        w.wheelRadius = genome[world->worldProperties()->genomeBodyLength() + i * 4 + 1].toDouble();

        w.wheelSpeed = genome[world->worldProperties()->genomeBodyLength() + i * 4 + 2].toDouble();
        w.wheelTorqueCoeff = genome[world->worldProperties()->genomeBodyLength() + i * 4 + 3].toDouble();
        wheelsArray.push_back(w);
    }

    double carCoeffSum=0;
    foreach(CarWheel w, wheelsArray)
    {
        carCoeffSum += w.wheelTorqueCoeff;
    }

    double carTorqueMultiplier = 1.0;
    if (carCoeffSum > 1.0) carTorqueMultiplier = 1.0 / carCoeffSum;
    double carPower = _triangles * world->worldProperties()->trianglePower()*carTorqueMultiplier;
    foreach(CarWheel w, wheelsArray)
    {
        b2BodyDef wheelDef;
        wheelDef.type = b2_dynamicBody;
        b2Vec2 vert = creator.verticeList()[w.verticeId]; /* + position */;
       /* b2Vec2 b;
        b.SetZero();
        double angleRad = angle * 3.1415926 / 180.0f;
        b2Vec2 wheelPosition(cos(angleRad) * (vert.x - b.x) + sin(angleRad) * (vert.y - b.y) + b.x,
                 cos(angleRad) * (vert.y - b.y) - sin(angleRad) * (vert.x - b.x) + b.y);*/
        b2Vec2 wheelPosition = vert + position;
        wheelDef.position.Set(wheelPosition.x,wheelPosition.y);

        //wheelDef.position.Set(vert.x,vert.y);
        b2Body * wheelBody = world->b2world()->CreateBody(&wheelDef);
        bodyList.push_back(wheelBody);

        Q_ASSERT(wheelBody !=0);


        b2CircleShape wheelShape;
        wheelShape.m_radius = w.wheelRadius;
        //wheelShape.m_p.SetZero();

        b2FixtureDef wheelFixtureDef;
        wheelFixtureDef.shape = &wheelShape;
        wheelFixtureDef.density = 0.5;
        wheelFixtureDef.friction = world->worldProperties()->wheelFriction();
        wheelFixtureDef.restitution = 0.0f;
        wheelFixtureDef.filter.maskBits = 2;
        wheelFixtureDef.filter.categoryBits = 1;

        wheelBody->CreateFixture(&wheelFixtureDef);

        //b2WheelJointDef wheelJoint;
        b2RevoluteJointDef wheelJoint;
        //wheelJoint.bodyA = body;
        //wheelJoint.bodyB = wheelBody;
        /*b2Vec2 axis(0.0f, 1.0f);
        wheelJoint.Initialize(body,wheelBody,wheelPosition,axis);
        wheelJoint.enableMotor = true;
        wheelJoint.motorSpeed = world->worldProperties()->wheelSpeed();
        wheelJoint.maxMotorTorque = world->worldProperties()->wheelTorque();
        wheelJoint.frequencyHz = 4.0; //- world->worldProperties()->wheelSpeed();
        wheelJoint.dampingRatio=0.0f;
        /*wheelJoint.localAnchorA=wheelPosition;*/
        //wheelJoint.localAnchorB=wheelPosition;*/
        //b2Vec2 axis =
        //wheelJoint.localAxisA=b2Vec2_zero;

        wheelJoint.Initialize(body,wheelBody,wheelPosition);
        wheelJoint.enableMotor = true;
        wheelJoint.lowerAngle = 0.0f;
        wheelJoint.upperAngle = 360.0f;
        wheelJoint.referenceAngle = 0.0f;
        wheelJoint.maxMotorTorque = w.wheelTorqueCoeff * carPower;
        wheelJoint.motorSpeed = -w.wheelSpeed;
        //wheelJoint.collideConnected =0;

        b2Joint * joint =  world->b2world()->CreateJoint(&wheelJoint);
        jointList.push_back(joint);
    }   
    //lastPosition = body->GetPosition();

    //b2Vec2 vecZero;
    //body->SetTransform(angle);

}

Car::~Car()
{
    foreach(b2Body * b, bodyList)
    {
        world->b2world()->DestroyBody(b);
    }
}

const CarGenome &Car::genome() const
{
    return carGenome;
}

bool Car::shouldKillMe(double time)
{
    waitTime += time;
    if (hasMoveForward()) waitTime = 0;
    if (waitTime < world->worldProperties()->carDieTime()) return false;
    return true;
}

double Car::currentDistance()
{
    return body->GetPosition().x;
}

double Car::topDistance()
{
    return maxPosition;
}

quint32 Car::generation()
{
    return _generation;
}

quint16 Car::triangles()
{
    return _triangles;
}

quint16 Car::wheels()
{
    return _wheels;
}

quint16 Car::vertices()
{
    return _vertices;
}

b2Vec2 Car::position()
{
    return body->GetPosition();
}

double Car::mass()
{
    return body->GetMass();
}

bool Car::hasMoveForward()
{
    b2Vec2 pos = body->GetPosition();

    double lastPosition = maxPosition;
    if (pos.x > maxPosition) maxPosition = pos.x;
    if (maxPosition > (lastPosition + 0.1)) return true;
    return false;
}

