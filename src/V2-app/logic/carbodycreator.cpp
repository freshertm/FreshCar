#include "carbodycreator.h"
#include <QDebug>
#include <QList>
#include <glm/glm.hpp>

CarBodyCreator::CarBodyCreator(const CarGenome& carGenome, const WorldProperties &properties)
{
    int genomeLength = properties.genomeBodyLength();
    //const int genomeLength = 50;
    double edgeLength = properties.bodyEdgeLength();

    /*int *testGenome; //[]={1,1,1,4,5, 3,4,7,4,1};
    testGenome = new int[genomeLength];
    for (int i=0; i< genomeLength; i++)
    {
        testGenome[i] = qrand() % genomeLength;
    }*/


    const double cos60 = 0.5f;
    const double sin60 = 0.86602540378443864676372317075294f;


    //Create initial triangle
    vertices.push_back(b2Vec2(0,0));
    vertices.push_back(b2Vec2(edgeLength,0));    
    vertices.push_back(b2Vec2(edgeLength *cos60,edgeLength * sin60));

    Triangle triangle(0,1,2);
    triangles.push_back(triangle);

    putEdge(triangle.edgeA());
    putEdge(triangle.edgeB());
    putEdge(triangle.edgeC());

    for (int i=0; i< genomeLength; ++i)
    {
        //int genome = carGenome[i];
        QVariant varGenome = carGenome[i];
        if (!varGenome.isValid())
        {
            qDebug() << "invalid variant!";
            continue;
        }
        bool ok;
        int genome = varGenome.toUInt(&ok);
        if (!ok)
        {
            qDebug() << "cannot convert variant to uint!";
            continue;
        }

        if (genome == 0)
        {
            continue;
        }

        genome -= 1;

        if (genome >= freeEdges.count())
            genome = genome % freeEdges.count();

        int edgeId = freeEdges[genome];
        Edge edge = edges[ edgeId ].swapped();
        freeEdges.removeAt(genome);

        b2Vec2 a = vertices[edge.verticeA];
        b2Vec2 b = vertices[edge.verticeB];
        b2Vec2 c(cos60 * (a.x - b.x) + sin60 * (a.y - b.y) + b.x,
                 cos60 * (a.y - b.y) - sin60 * (a.x - b.x) + b.y);

        //Проверяем что такой вершины нет в конструкции.
        int verticeId;
        if (!hasVertice(c, &verticeId))
        {
            verticeId = vertices.count();
            vertices.push_back(c);
        }

        //Проверяем что такого треугольника нет в конструкции.

        Triangle triangle(edge.verticeA, edge.verticeB,verticeId);
        if (!hasTriangle(triangle))
        {
            triangles.push_back(triangle);
            putEdge(triangle.edgeB());
            putEdge(triangle.edgeC());
        }
    }
}

Geometry *CarBodyCreator::createGeometry()
{
    Geometry::Vertexes vertexes;
    vertexes.reserve(verticeList().size());
    foreach(b2Vec2 b2vec, verticeList()){
        glm::vec3 v3(b2vec.x, b2vec.y, 0);
        vertexes.append(v3);
    }

    return new Geometry(vertexes, Geometry::Vertexes(), triangleList(), Geometry::TexCoords());
}

void CarBodyCreator::putEdge(const Edge &edge)
{
    int id;
    if (hasEdge(edge, &id))
    {
        for (FreeEdgeList::Iterator i = freeEdges.begin();
             i!= freeEdges.end();
             i++)
        {
            if (*i == id)
            {
                freeEdges.erase(i);
                return;
            }

        }
        return;
    }
    freeEdges.push_back(edges.count());
    edges.push_back(edge);
}

bool CarBodyCreator::hasVertice(const b2Vec2 &v, int * id) const
{
    const double gamma = 0.000001;
    for(int i=0; i<vertices.count(); ++i)
    {
        b2Vec2 vertice = vertices.at(i);
        if ((fabs(vertice.x - v.x) < gamma) &&
            (fabs(vertice.y - v.y) <gamma))
        {
            if (id) *id = i;
            return true;
        }
    }
    return false;
}

bool CarBodyCreator::hasEdge(const Edge &e, int *id) const
{
    //foreach(Edge edge, edges)
    for (int i=0; i<edges.count(); ++i)
    {
        Edge edge = edges[i];
        if ( ((edge.verticeA == e.verticeA) &&
                (edge.verticeB == e.verticeB)) ||
             ((edge.verticeA == e.verticeB) &&
                (edge.verticeB == e.verticeA)) )
        {
            if (id) *id = i;
            return true;
        }
    }
    return false;
}

bool CarBodyCreator::hasTriangle(const Triangle &triangle)
{
    foreach(Triangle t, triangles)
    {
        if ( ( (t.verticeA == triangle.verticeA) &&
               (t.verticeB == triangle.verticeB) &&
               (t.verticeC == triangle.verticeC)) ||

             ( (t.verticeA == triangle.verticeA) &&
               (t.verticeB == triangle.verticeC) &&
               (t.verticeC == triangle.verticeB)) ||


             ( (t.verticeA == triangle.verticeB) &&
               (t.verticeB == triangle.verticeA) &&
               (t.verticeC == triangle.verticeC)) ||

             ( (t.verticeA == triangle.verticeB) &&
               (t.verticeB == triangle.verticeC) &&
               (t.verticeC == triangle.verticeA)) ||


             ( (t.verticeA == triangle.verticeC) &&
               (t.verticeB == triangle.verticeB) &&
               (t.verticeC == triangle.verticeA)) ||

             ( (t.verticeA == triangle.verticeC) &&
               (t.verticeB == triangle.verticeA) &&
               (t.verticeC == triangle.verticeB)))return true;
    }
    return false;
}
