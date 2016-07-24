#include "ground.h"

Ground::Ground()
{

}


/*
void World::createRandomGround()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body * groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(100.0f, 10.0f);
    b2FixtureDef groundFixtureDef;
    groundFixtureDef.shape = &groundBox;
    groundFixtureDef.density = 0.0f;
    groundFixtureDef.friction = properties.groundFriction();
    groundFixtureDef.filter.categoryBits = 2;
    groundFixtureDef.filter.maskBits = 1;
    groundBody->CreateFixture(&groundFixtureDef);

    double x=100.0;
    double y=0.0;
    double width =  properties.groundPlateLength();
    double angle =0.0;

    for (int i=0; i<500; ++i) {
        b2BodyDef bodyDef1;
        bodyDef1.position.Set(x, y);
        b2Body* body1 = world->CreateBody(&bodyDef1);
        b2PolygonShape box1;
        double halfWidth = width / 2.0;
        box1.SetAsBox(halfWidth, 0.2f);


        b2FixtureDef gfd;
        gfd.shape = &box1;
        gfd.density = 1.0f;
        gfd.friction = properties.groundFriction();
        gfd.filter.categoryBits = 2;
        gfd.filter.maskBits = 1;

        body1->CreateFixture(&gfd);
        int step = (int)(30*pow((double)i*0.05f+1, 0.6));
        angle = 0.02f*(qrand()%step - step/2);
        body1->SetTransform(body1->GetPosition() + b2Vec2(halfWidth*cos(angle), halfWidth*sin(angle)), angle);

        x += width * cos(angle);
        y += width * sin(angle);

        width *= properties.groundMultiplier();
    }
}


*/
