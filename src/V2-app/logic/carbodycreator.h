#ifndef CARBODYCREATOR_H
#define CARBODYCREATOR_H

#include "cargenome.h"
#include "Box2D.h"
#include <QList>
#include <QVector>
#include "geometry.h"
#include "worldproperties.h"

class CarBodyCreator
{
public:
    typedef QVector<b2Vec2> VerticeList;
    typedef QVector<Triangle> TriangleList;
    typedef QList<quint32> FreeEdgeList;

    CarBodyCreator(const CarGenome& , const WorldProperties& properties);

    inline const VerticeList& verticeList(){return vertices;}
    inline const TriangleList& triangleList(){return triangles;}
    inline const FreeEdgeList& freeEdgeList(){return freeEdges;}
    Geometry* createGeometry();

private:
    QList<Edge> edges;
    FreeEdgeList freeEdges;
    VerticeList vertices;
    TriangleList triangles;


private:
    void putEdge(const Edge &edge);
    bool hasVertice(const b2Vec2&, int * id = NULL) const;
    bool hasEdge(const Edge& edge, int * id = NULL) const;
    bool hasTriangle(const Triangle &);
};

#endif // CARBODYCREATOR_H
