#ifndef GEOMETRY
#define GEOMETRY

#include <QtCore/qtypeinfo.h>
#include <QVector>

struct Vector3
{
    qreal x,y,z;
};

struct TexCoord
{
    qreal x,y;
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
};

struct texcoord_t
{
    qint32 u,v;
};

struct Geometry
{
    QVector<Vector3> vertices;
    QVector<Triangle> triangles;
    QVector<TexCoord> texcoord_t;
};

#endif // GEOMETRY

