#ifndef RENDERDATA_H
#define RENDERDATA_H

#include <QOpenGLFunctions>
#include "geometry.h"
#include "v2object.h"

class RenderData: public V2Resource
{
public:
    RenderData(const Geometry * geometry);
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
    Indices *getIndices(Geometry::Triangles triangles);
};


#endif // RENDERDATA_H
