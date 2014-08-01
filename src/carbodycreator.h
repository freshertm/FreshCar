#ifndef CARBODYCREATOR_H
#define CARBODYCREATOR_H

#include "cargenome.h"
#include "Box2D.h"
#include "world.h"
#include <QList>
#include <QVector>



class CarBodyCreator
{
public:

    struct Edge
    {
        quint32 verticeA;
        quint32 verticeB;
        Edge(quint32 verticeA, quint32 verticeB): verticeA(verticeA), verticeB(verticeB){}
        Edge():verticeA(0),verticeB(0){}
        Edge swapped() const;
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

    typedef QVector<b2Vec2> VerticeList;
    typedef QVector<Triangle> TriangleList;
    typedef QList<quint32> FreeEdgeList;

    CarBodyCreator(const CarGenome& , const World * world);

    inline const VerticeList& verticeList(){return vertices;}
    inline const TriangleList& triangleList(){return triangles;}
    inline const FreeEdgeList& freeEdgeList(){return freeEdges;}

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
