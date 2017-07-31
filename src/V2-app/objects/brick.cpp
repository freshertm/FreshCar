#include "brick.h"
#include "v2geometry.h"

#include "v2rigidbody2d.h"

Brick::Brick(const glm::vec2 &position, float angle, float width, float height)
{
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = brickDepth / 2.0f;

    QVector<glm::vec3> vertices;
    vertices.push_back(glm::vec3(-halfWidth, -halfHeight, halfDepth)); //0
    vertices.push_back(glm::vec3( halfWidth, -halfHeight, halfDepth)); //1
    vertices.push_back(glm::vec3( halfWidth,  halfHeight, halfDepth)); //2
    vertices.push_back(glm::vec3(-halfWidth,  halfHeight, halfDepth)); //3

    vertices.push_back(glm::vec3(-halfWidth, -halfHeight, -halfDepth)); //4
    vertices.push_back(glm::vec3( halfWidth, -halfHeight, -halfDepth)); //5
    vertices.push_back(glm::vec3( halfWidth,  halfHeight, -halfDepth)); //6
    vertices.push_back(glm::vec3(-halfWidth,  halfHeight, -halfDepth)); //7


    QVector<glm::vec3> normals;

    QVector<Triangle> triangles;
    //front
    triangles.push_back(Triangle(0,1,2));
    triangles.push_back(Triangle(2,3,0));

    //top
    triangles.push_back(Triangle(1,5,6));
    triangles.push_back(Triangle(6,2,1));

    //back
    triangles.push_back(Triangle(7,6,5));
    triangles.push_back(Triangle(5,4,7));

    //bottom
    triangles.push_back(Triangle(4,0,3));
    triangles.push_back(Triangle(3,7,4));

    //left
    triangles.push_back(Triangle(4,5,1));
    triangles.push_back(Triangle(1,0,4));

    //right
    triangles.push_back(Triangle(3,2,6));
    triangles.push_back(Triangle(6,7,3));

    QVector<TexCoord> texcoords;

    auto geometry = QSharedPointer<Geometry>::create(vertices, normals,triangles, texcoords);
    addAgent(geometry);
    setRotation(glm::vec3(0,0,angle));
    setPosition(glm::vec3(position.x, position.y, 0));
    auto prop = QSharedPointer<V2RenderProperties>::create();
    prop->setLighting(false);
    prop->setColor(V2Color(0,255,0));
    //prop->setWireframe(true);
    addAgent(prop);
    auto ag = QSharedPointer<V2RigidBody2D>::create(V2RigidBody2D::StaticBody);
    addAgent(ag);
}

Brick::~Brick()
{
}
