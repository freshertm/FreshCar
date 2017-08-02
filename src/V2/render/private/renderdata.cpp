#include "renderdata.h"


RenderData::RenderData(const QSharedPointer<Geometry> &geometry): _hasNormals(false), _hasTexCoords(false), _useIndices(false){
    QOpenGLContext * context = QOpenGLContext::currentContext();
    QOpenGLFunctions *gl = context->functions();

    if (geometry->style() == Geometry::Indices){
        _useIndices = true;
        // push indices
        gl->glGenBuffers(1, &_indicesBufferId);
        gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferId);

        Indices* indices = getIndices(geometry->triangles());
        _indicesCount = indices->size();
        gl->glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof (quint32) * _indicesCount,
                        indices->data(), GL_STATIC_DRAW);
        gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        delete indices;
    }


    // push vertexes
    gl->glGenBuffers(1, &_vertexBufferId);
    gl->glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
    gl->glBufferData(GL_ARRAY_BUFFER,sizeof (glm::vec3) * geometry->vertexes().size(),
                    geometry->vertexes().data(), GL_STATIC_DRAW);
    gl->glBindBuffer(GL_ARRAY_BUFFER,0);
    _verticesCount = geometry->vertexes().size();

    if (geometry->texcoords().size() > 0){
        _hasTexCoords = true;
        // push texcoords
        gl->glGenBuffers(1, &_textcoordBufferId);
        gl->glBindBuffer(GL_ARRAY_BUFFER, _textcoordBufferId);
        gl->glBufferData(GL_ARRAY_BUFFER, sizeof (TexCoord) * geometry->texcoords().size(),
                        geometry->texcoords().data(), GL_STATIC_DRAW);
        gl->glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    if (geometry->normals().size()>0){
        _hasNormals = true;

        // push normals
        gl->glGenBuffers(1, &_normalsBufferId);
        gl->glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferId);
        gl->glBufferData(GL_ARRAY_BUFFER, sizeof (glm::vec3) * geometry->normals().size(),
                        geometry->normals().data(), GL_STATIC_DRAW);
        gl->glBindBuffer(GL_ARRAY_BUFFER,0);
    }
}

RenderData::~RenderData()
{
    QOpenGLFunctions *gl = QOpenGLContext::currentContext()->functions();
    gl->glDeleteBuffers(1, &_indicesBufferId);
    gl->glDeleteBuffers(1, &_vertexBufferId);
    if (_hasNormals) {
        gl->glDeleteBuffers(1, &_normalsBufferId);
    }
    if (_hasTexCoords) {
        gl->glDeleteBuffers(1, &_textcoordBufferId);
    }
}

void RenderData::process()
{
    QOpenGLFunctions *gl = QOpenGLContext::currentContext()->functions();
    glEnableClientState(GL_VERTEX_ARRAY);
    gl->glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);

    if (_hasNormals) {
        glEnableClientState(GL_NORMAL_ARRAY);
        gl->glBindBuffer(GL_ARRAY_BUFFER, _normalsBufferId);
        glNormalPointer(GL_FLOAT, 0, nullptr);
    }

    if (_hasTexCoords) {
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        gl->glBindBuffer(GL_ARRAY_BUFFER, _textcoordBufferId);
        glTexCoordPointer(2, GL_FLOAT, 0, nullptr);
    }
    if (_useIndices){
        gl->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBufferId);
        gl->glDrawElements(GL_TRIANGLES, _indicesCount, GL_UNSIGNED_SHORT, nullptr);
    } else {
        gl->glDrawArrays(GL_TRIANGLES,0,_verticesCount);
    }
    glDisableClientState(GL_VERTEX_ARRAY);
    if (_hasTexCoords){
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    if (_hasNormals) {
        glDisableClientState(GL_NORMAL_ARRAY);
    }
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

