#include "renderdata.h"


RenderData::RenderData(const Geometry *geometry): ObjectData(){
    gl.initializeOpenGLFunctions();

    // push indices
    gl.glGenBuffers(1, &_indicesBufferId);
    gl.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferId);

    Indices* indices = getIndices(geometry->triangles());
    _indicesCount = indices->size();
    gl.glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof (quint32) * _indicesCount,
                    indices->data(), GL_STATIC_DRAW);
    gl.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
    delete indices;


    // push vertexes
    gl.glGenBuffers(1, &_vertexBufferId);
    gl.glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
    gl.glBufferData(GL_ARRAY_BUFFER,sizeof (Vector3) * geometry->vertexes().size(),
                    geometry->vertexes().data(), GL_STATIC_DRAW);
    gl.glBindBuffer(GL_ARRAY_BUFFER,0);


    // push texcoords
    gl.glGenBuffers(1, &_textcoordBufferId);
    gl.glBindBuffer(GL_ARRAY_BUFFER, _textcoordBufferId);
    gl.glBufferData(GL_ARRAY_BUFFER, sizeof (TexCoord) * geometry->texcoords().size(),
                    geometry->texcoords().data(), GL_STATIC_DRAW);
    gl.glBindBuffer(GL_ARRAY_BUFFER,0);


    // push normals
    gl.glGenBuffers(1, &_normalsBufferId);
    gl.glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferId);
    gl.glBufferData(GL_ARRAY_BUFFER, sizeof (Vector3) * geometry->normals().size(),
                    geometry->normals().data(), GL_STATIC_DRAW);
    gl.glBindBuffer(GL_ARRAY_BUFFER,0);
}

RenderData::~RenderData()
{
    gl.glDeleteBuffers(1, &_indicesBufferId);
    gl.glDeleteBuffers(1, &_vertexBufferId);
    gl.glDeleteBuffers(1, &_normalsBufferId);
    gl.glDeleteBuffers(1, &_textcoordBufferId);
}

void RenderData::process()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    gl.glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);

    gl.glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferId);
    glNormalPointer(GL_FLOAT, 0, nullptr);

    gl.glBindBuffer(GL_ARRAY_BUFFER, _textcoordBufferId);
    glTexCoordPointer(2, GL_FLOAT, 0, nullptr);

    gl.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferId);
    gl.glDrawElements(GL_TRIANGLES, _indicesCount, GL_UNSIGNED_SHORT, nullptr);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}

RenderData::Indices *RenderData::getIndices(Geometry::Triangles triangles)
{
    Indices* result = new Indices;
    result->reserve(triangles.size() * 3);
    foreach(Triangle triangle, triangles) {
        result->append(triangle.verticeA);
        result->append(triangle.verticeB);
        result->append(triangle.verticeC);
    }
    return result;
}

