#ifndef RENDERDATA_H
#define RENDERDATA_H

#include <QOpenGLFunctions>
#include "geometry.h"
#include "worldobject.h"

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
    QOpenGLFunctions gl;

    typedef QVector<quint16> Indices;
    Indices *getIndices(Geometry::Triangles triangles);
};


#endif // RENDERDATA_H
