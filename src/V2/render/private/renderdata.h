#ifndef RENDERDATA_H
#define RENDERDATA_H

#include <QOpenGLFunctions>
#include "v2geometry.h"
#include "v2object.h"

class RenderData: public V2Resource
{
public:
    RenderData(const QSharedPointer<Geometry>& geometry);
    ~RenderData();
    virtual void process();

private:
    GLuint _indicesCount;
    GLuint _indicesBufferId;
    GLuint _vertexBufferId;
    GLuint _textcoordBufferId;
    GLuint _normalsBufferId;

    bool _hasNormals;
    bool _hasTexCoords;

    typedef QVector<quint16> Indices;
    typedef QVector<glm::vec3> Vertexes;

    Indices *getIndices(Geometry::Triangles triangles);
    Indices *getNormals(Geometry::Triangles triangles);

    bool _useIndices = false;
    uint32_t _verticesCount = 0;

};


#endif // RENDERDATA_H
