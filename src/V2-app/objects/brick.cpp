#include "brick.h"
#include "v2geometry.h"

#include "v2rigidbody2d.h"

Brick::Brick(const glm::vec2 &position, float angle, float width, float height)
{
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = brickDepth / 2.0f;

    QVector<glm::vec3> vertices;
    QVector<glm::vec3> normals;

    glm::vec3  v0(-halfWidth, -halfHeight, halfDepth);
    glm::vec3  v1( halfWidth, -halfHeight, halfDepth);
    glm::vec3  v2( halfWidth,  halfHeight, halfDepth);
    glm::vec3  v3(-halfWidth,  halfHeight, halfDepth);

    glm::vec3  v4(-halfWidth, -halfHeight, -halfDepth);
    glm::vec3  v5( halfWidth, -halfHeight, -halfDepth);
    glm::vec3  v6( halfWidth,  halfHeight, -halfDepth);
    glm::vec3  v7(-halfWidth,  halfHeight, -halfDepth);

    //front

    QVector<glm::vec3> vert = {
        v0,v1,v2, v0,v3,v2,  //front
        v1,v5,v6, v6,v2,v1,  //top
       /* v7,v6,v5, v5,v4,v7,  //back
        v4,v0,v3, v3,v7,v4,  //bottom
        v4,v5,v1, v1,v0,v4,  //left
        v3,v2,v6, v6,v7,v3 */ };

    vertices.append(vert);

    glm::vec3 normFront (0,0, 1);
    glm::vec3 normBack  (0,0, -1);

    glm::vec3 normTop   (0,1,0);
    glm::vec3 normBottom(0,-1,0);
    glm::vec3 normLeft  (-1,0,0);
    glm::vec3 normRight(1,0,0);

    QVector<glm::vec3> norm = { normFront, normFront, normFront, normFront, normFront, normFront,
                                normTop, normTop,normTop, normTop,normTop,normTop,
                                normBack,normBack,normBack, normBack,normBack,normBack,
                                normBottom,normBottom,normBottom,normBottom,normBottom,normBottom,
                                normLeft, normLeft, normLeft, normLeft, normLeft, normLeft,
                                normRight,normRight, normRight, normRight, normRight, normRight };
    normals.append(norm);

    //vertices.append(); //2

    //vertices.push_back(); //3

   /* normals.push_back(glm::vec3(0,0,1));
    normals.push_back(glm::vec3(0,0,1));
    normals.push_back(glm::vec3(0,0,1));
    //normals.push_back(glm::vec3(0,0,1));

    //back
    normals.push_back(glm::vec3(0,0,-1));
    normals.push_back(glm::vec3(0,0,-1));
    normals.push_back(glm::vec3(0,0,-1));
    //normals.push_back(glm::vec3(0,0,-1));

    //left
   /* vertices.push_back(glm::vec3(-halfWidth, -halfHeight, -halfDepth)); // 8
    vertices.push_back(glm::vec3(-halfWidth,  halfHeight, -halfDepth)); // 9
    vertices.push_back(glm::vec3(-halfWidth,  halfHeight,  halfDepth)); //10
    vertices.push_back(glm::vec3(-halfWidth, -halfHeight,  halfDepth)); //11

    normals.push_back(glm::vec3(-1,0,0));
    normals.push_back(glm::vec3(-1,0,0));
    normals.push_back(glm::vec3(-1,0,0));
    normals.push_back(glm::vec3(-1,0,0));

    //right
    vertices.push_back(glm::vec3(halfWidth, -halfHeight, -halfDepth)); // 8
    vertices.push_back(glm::vec3(halfWidth,  halfHeight, -halfDepth)); // 9
    vertices.push_back(glm::vec3(halfWidth,  halfHeight,  halfDepth)); //10
    vertices.push_back(glm::vec3(halfWidth, -halfHeight,  halfDepth)); //11


    normals.push_back(glm::vec3(1,0,0));
    normals.push_back(glm::vec3(1,0,0));
    normals.push_back(glm::vec3(1,0,0));
    normals.push_back(glm::vec3(1,0,0));



    normals.push_back(glm::vec3(0,1,0));
    normals.push_back(glm::vec3(0,1,0));
    normals.push_back(glm::vec3(0,1,0));
    normals.push_back(glm::vec3(0,1,0));

    normals.push_back(glm::vec3(0,0,0));
    normals.push_back(glm::vec3(0,0,0));
    normals.push_back(glm::vec3(0,0,0));
    normals.push_back(glm::vec3(0,0,0));*/

    /*QVector<Triangle> triangles;
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
    triangles.push_back(Triangle(6,7,3));*/

    QVector<TexCoord> texcoords;

    auto geometry = QSharedPointer<Geometry>::create(vertices, normals, texcoords);
    addAgent(geometry);
    setRotation(glm::vec3(0,0,angle));
    setPosition(glm::vec3(position.x, position.y, 0));
    auto prop = QSharedPointer<V2RenderProperties>::create();
    prop->setLighting(true);
    prop->setColor(V2Color(0,255,0));
    //prop->setWireframe(true);
    addAgent(prop);
    auto ag = QSharedPointer<V2RigidBody2D>::create(V2RigidBody2D::StaticBody);
    addAgent(ag);
}

Brick::~Brick()
{
}
