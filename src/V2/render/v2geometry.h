#ifndef GEOMETRY
#define GEOMETRY

#include <QtCore/qtypeinfo.h>
#include <QVector>
#include "v2object.h"
#include <glm/glm.hpp>

struct TexCoord
{
    qreal x,y;
    TexCoord(qreal x, qreal y):x(x), y(y){}
    TexCoord():x(0), y(0){}
};

struct Edge
{
    quint32 verticeA;
    quint32 verticeB;

    Edge(quint32 verticeA, quint32 verticeB): verticeA(verticeA), verticeB(verticeB){}
    Edge():verticeA(0),verticeB(0){}
    Edge swapped() const { return Edge(verticeB, verticeA);}
};

struct Triangle
{
    union{
        struct{
            quint32 verticeA;
            quint32 verticeB;
            quint32 verticeC;
        };
        quint32 verticesID[3];
    };

    Edge edgeA() const {return Edge(verticeA, verticeB);}
    Edge edgeB() const {return Edge(verticeB, verticeC);}
    Edge edgeC() const {return Edge(verticeC, verticeA);}

    Triangle(quint32 va, quint32 vb, quint32 vc): verticeA(va), verticeB(vb),verticeC(vc){}
    Triangle():verticeA(0),verticeB(0),verticeC(0){}
};

struct texcoord_t
{
    qint32 u,v;
};

class Geometry: public V2ObjectAgent
{
public:
    Geometry(){}
    enum Style{Indices, TriangleStrip };

    Geometry(const QVector<glm::vec3> &vertexes,
             const QVector<glm::vec3> &normals,
             const QVector<Triangle> &triangles,
             const QVector<TexCoord> &texture_coords):
        _vertexes(vertexes),
        _normals(normals),
        _triangles(triangles),
        _texcoords(texture_coords),
        _style(Indices)
    {}

    Geometry(const QVector<glm::vec3> &vertexes,
             const QVector<glm::vec3> &normals,
             const QVector<TexCoord> &texture_coords):
        _vertexes(vertexes),
        _normals(normals),
        _texcoords(texture_coords),
        _style(TriangleStrip)
    {}

    typedef QVector<glm::vec3> Vertexes;
    typedef QVector<Triangle> Triangles;
    typedef QVector<TexCoord> TexCoords;



    const Vertexes& vertexes() const {
        return _vertexes;
    }

    const Vertexes& normals() const {
        return _normals;
    }

    const Triangles& triangles() const {
        return _triangles;
    }

    const TexCoords& texcoords() const {
        return _texcoords;
    }

    Style style() const {
        return _style;
    }


private:
    Vertexes _vertexes;
    Vertexes _normals;
    Triangles _triangles;
    TexCoords _texcoords;
    Style     _style;
};

#endif // GEOMETRY

