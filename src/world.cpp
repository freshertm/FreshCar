#include "world.h"
#include "cargenome.h"
#include "car.h"
#include "contactfilter.h"
#include <QElapsedTimer>
#include <QTime>
#include "carbodycreator.h" //for createRandomGenome

#include "Serializer"
#include "Parser"
#include <QFile>

#include "imodule.h"

const quint16 wheelGenomes = 4;

World::World(long seed):properties("settings.ini"),
    _generationNumber(0),
    _generationNumberTopRecord(0),
    _topRecord(0)
{
    world = new b2World(b2Vec2(0,-10));

    qsrand(seed);


    for (int i =0; i< properties.population(); i++)
    {
        addRandomCar();
    }
    createRandomGround();
    timer.start();
}

void World::step()
{

    QElapsedTimer t;

    t.start();

    const int32 velocityIterations = 50;
    const int32 positionIterations = 50;

    double sec = ((double)timer.elapsed() * properties.timeMultiplier()) / 1000.0f;
    timer.start();


    world->Step(sec,velocityIterations,positionIterations);

    _physicTime = t.elapsed();
    t.start();

    for (CarList::Iterator i = _carList.begin();
         i!=_carList.end();
         i++)
    {
        Car *car = *i;
        if (car->topDistance() > _topRecord)
        {
            _topRecord = car->topDistance();
            _generationNumberTopRecord = car->generation();
        }
        if (car->shouldKillMe(sec))
        {
            if (car->topDistance() > 40.0)
                addToTopList(car->topDistance(),car->genome());
            if (fabs(car->topDistance() - absoluteMaxDistance()) < 0.00001)
                _generationNumberTopRecord = car->generation();
            delete car;
            _carList.erase(i);

            int populationInsuff = properties.population() - _carList.count();

            if ( populationInsuff >= properties.mixCarsCount() )
                sex();
            break;

        }
    }

    _worldTime = t.elapsed();
}

World::CarList World::carList()
{
    return _carList;
}

b2World *World::b2world()
{
    return world;
}

const WorldProperties *World::worldProperties() const
{
    return &properties;
}

WorldProperties *World::worldPropertiesForChange()
{
    return &properties;
}

double World::currentTopCarPosition()
{
    double top=_carList.at(0)->currentDistance();
    foreach (Car* car, _carList)
    {
        if (car->currentDistance() > top) top = car->currentDistance();
    }

    return top;
}

double World::absoluteMaxDistance()
{
    return _topRecord;
}

void World::addRandomCar()
{
    CarGenome genome = createRandomGenome();
    addCarFromGenome(genome);
}

void World::saveState(const QString &filename)
{

    QVariantMap map;
    map["generation"] = _generationNumber;
    map["generation_top_rec"] = _generationNumberTopRecord;
    map["world_top_rec"] = _topRecord;

    map["world_properties"] = properties.serialize();

    QVariantList carGenomes;

    foreach (Car * c, _carList) {
        CarGenome g = c->genome();
        QVariantList genome;
        foreach (QVariant v, g) genome.push_back(v);
        carGenomes.push_back(genome);
    }

    QVariantList topList;
    foreach (GenomeTopListRecord record, _topList) {
        QVariantMap topListRecord;
        topListRecord["achievement"] = record.first;
        QVariantList genomeV;
        foreach (QVariant g, record.second) genomeV.push_back(g);
        topListRecord["genome"] = genomeV;
        topList.push_back(topListRecord);
    }

    map["current_cars"] = carGenomes;
    QFile f(filename);
    if (!f.open(QIODevice::WriteOnly))
    {
        return;
    };

    bool ok;
    QJson::Serializer serializer;
    serializer.serialize(map,&f,&ok);
    f.close();
}

void World::loadState(const QString &filename)
{

}

void World::addToTopList(double result, const CarGenome &genome)
{
    GenomeTopListRecord rec;
    rec.first = result;
    rec.second = genome;
    _topList.push_back(rec);
    qSort(_topList.begin(),_topList.end(),topListRecordLessThan);
    if (_topList.length() >= properties.mixCarsCount() * 2)
        _topList.removeLast();
}

void World::createRandomGround()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body * groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(100.0f, 10.0f);
    b2FixtureDef groundFixtureDef;
    groundFixtureDef.shape = &groundBox;
    groundFixtureDef.density = 0.0f;
    groundFixtureDef.friction = properties.groundFriction();
    groundFixtureDef.filter.categoryBits = 2;
    groundFixtureDef.filter.maskBits = 1;
    groundBody->CreateFixture(&groundFixtureDef);

    double x=100.0;
    double y=0.0;
    double width =  properties.groundPlateLength();
    double angle =0.0;

    for (int i=0; i<500; ++i) {
        b2BodyDef bodyDef1;
        bodyDef1.position.Set(x, y);
        b2Body* body1 = world->CreateBody(&bodyDef1);
        b2PolygonShape box1;
        double halfWidth = width / 2.0;
        box1.SetAsBox(halfWidth, 0.2f);


        b2FixtureDef gfd;
        gfd.shape = &box1;
        gfd.density = 1.0f;
        gfd.friction = properties.groundFriction();
        gfd.filter.categoryBits = 2;
        gfd.filter.maskBits = 1;

        body1->CreateFixture(&gfd);
        int step = (int)(30*pow((double)i*0.05f+1, 0.6));
        angle = 0.02f*(qrand()%step - step/2);
        body1->SetTransform(body1->GetPosition() + b2Vec2(halfWidth*cos(angle), halfWidth*sin(angle)), angle);

        x += width * cos(angle);
        y += width * sin(angle);

        width *= properties.groundMultiplier();
    }
}


void World::sex()
{
    const int divider = 10;
    if ((_topList.length() + carList().count()) <= properties.mixCarsCount() )
    {
        for (int i =0; i< properties.population(); ++i)
            addRandomCar();
        return;
    }

    ++_generationNumber;
    emit newGeneration();


    GenomeTopList currentTopList;

    foreach(GenomeTopListRecord gr, _topList)
    {
        currentTopList.push_back(gr);
    }

    foreach(Car * car, _carList)
    {
        GenomeTopListRecord gr;
        gr.first = car->topDistance();
        gr.second = car->genome();

        currentTopList.push_back(gr);
    }

    qSort(currentTopList.begin(),currentTopList.end(),topListRecordLessThan);

    QVector<qint16> sexCarList;
    for (qint16 i=0; i< properties.mixCarsCount(); ++i)
    {
        for (quint16 j=0; j<(quint16)(currentTopList[i].first / divider); ++j)
            sexCarList.push_back(i);
    }

    if (sexCarList.count() == 0) return;

    while(currentPopulation() < properties.population())
    {
        CarGenome parentA = currentTopList[ sexCarList[qrand() % sexCarList.count() ] ].second;
        CarGenome parentB = currentTopList[ sexCarList[qrand() % sexCarList.count() ] ].second;
        //CarGenome childA;
        CarGenome child = makeChild(parentA, parentB);

        //mixGenome(parentA,parentB,childA, childB);
        mutateGenome(child);
        mutateGenome(parentA);
        mutateGenome(parentB);
        //mutateGenome(childB);
        addCarFromGenome(child);
        addCarFromGenome(parentA);
        addCarFromGenome(parentB);
        //addCarFromGenome(childB);

        mutateGenome(parentA);
        mutateGenome(parentB);

        addCarFromGenome(parentA);
        addCarFromGenome(parentB);
    }

    _topList.clear();
}

void World::addCarFromGenome(const CarGenome &genome)
{
    CarGenome gen = validateGenome(genome);
    float x = (qrand() % 50 - 25) * 1.5;
    float y = (qrand() % 10 + properties.bodyEdgeLength()*10);

    Car * car = new Car(gen,this,b2Vec2(x,y),
                        (rand() % 3600) / 10.0,_generationNumber);
    _carList.push_back(car);
    emit newCar(car);
}

double World::createRandomDouble(double min, double max)
{
    double range = max - min;
    double value = ((double)(qrand()) * range) / ((double)RAND_MAX);
    return value + min;
}

double World::validateDouble(double value, double min, double max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

double World::mutateDouble(double value, double min, double max, double rate)
{
    double range = (max - min) * rate;
    double increment = createRandomDouble(0,range) - range / 2.0;
    value += increment;
    if (value < min) value = min;
    if (value > max) value = max;
    return value;
}



CarGenome World::createRandomGenome()
{
    CarGenome genome;

    genome.resize(fullGenomeLength());

    int triangles = qrand() % 10; //1 + qrand() % properties.genomeBodyLength();

    for (int i=0; i< properties.genomeBodyLength(); ++i)
    {
        if (i<triangles)
            genome[i] = 1 + qrand() % (properties.genomeBodyLength() + 1);
        else genome[i] = 0;
    }

    CarBodyCreator creator(genome,this);


    int carWheels = qrand() % (properties.genomeMaxWheels()+1);

    for (int i=0; i< properties.genomeMaxWheels(); ++i)
    {
        if (i<carWheels)
        {
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelVertice    ] = qrand() % creator.verticeList().count();
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelRadius     ] = createRandomDouble(properties.wheelMinRadius(),properties.wheelMinRadius() / properties.genomeMutateRate());
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelSpeed      ] = createRandomDouble(properties.wheelMinSpeed(),properties.wheelMinSpeed() / properties.genomeMutateRate());
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelTorqueCoeff] = createRandomDouble(0,1); //torque coeff
        }
        else
        {
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelVertice    ] = 0;
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelRadius     ] = properties.wheelMinRadius();
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelSpeed      ] = properties.wheelMinSpeed();
            genome[properties.genomeBodyLength() + i * wheelGenomes + WheelTorqueCoeff] = createRandomDouble(0,1);
        }
    }


    return genome;
}

CarGenome World::validateGenome(const CarGenome & in)
{
    CarGenome genome;
    genome.resize(fullGenomeLength());
    for (int i=0; i<properties.genomeBodyLength(); ++i)
    {
        bool ok;
        int edge = in[i].toInt(&ok);
        if (!ok) edge = 0;
        else
        {
            if (edge >= properties.genomeBodyLength()) edge = properties.genomeBodyLength() -1;
            if (edge < 0) edge = 0;
        }
        genome[i] = edge;
    }

    for (int i=0; i<properties.genomeMaxWheels(); ++i)
    {
        bool ok;
        int vertice = in[properties.genomeBodyLength() + i * wheelGenomes + 0].toInt(&ok);
        if (!ok) vertice = 0;
        else
        {
            if (vertice > properties.genomeBodyLength() + 3) vertice = 0;
            if (vertice < 0) vertice = 0;
        }

        double radius = in[properties.genomeBodyLength() + i * wheelGenomes + 1].toDouble(&ok);
        if (!ok) radius = properties.wheelMinRadius();
        radius = validateDouble(radius, properties.wheelMinRadius(), properties.wheelMaxRadius());

        double wheelSpeed = in[properties.genomeBodyLength() + i * wheelGenomes + 2].toDouble(&ok);
        if (!ok) wheelSpeed = properties.wheelMinSpeed();
        wheelSpeed = validateDouble(wheelSpeed, properties.wheelMinSpeed(), properties.wheelMaxSpeed());

        double wheelTorqueCoeff = in[properties.genomeBodyLength() + i * wheelGenomes + 3].toDouble(&ok);
        if (!ok) wheelTorqueCoeff = 0;
        wheelTorqueCoeff = validateDouble(wheelTorqueCoeff, 0, 1);

        genome[properties.genomeBodyLength() + i * wheelGenomes + WheelVertice    ] = vertice;
        genome[properties.genomeBodyLength() + i * wheelGenomes + WheelRadius     ] = radius;
        genome[properties.genomeBodyLength() + i * wheelGenomes + WheelSpeed      ] = wheelSpeed;
        genome[properties.genomeBodyLength() + i * wheelGenomes + WheelTorqueCoeff] = wheelTorqueCoeff;
    }
    return genome;
}

void World::mixGenome(const CarGenome &parentA, const CarGenome &parentB, CarGenome &childA, CarGenome &childB)
{


    int partCount = 1 + qrand() % properties.genomeMixPart();

    QVector<quint16> parts;

    int i=0;
    do
    {
        quint16 slice = qrand() % fullGenomeLength();

        bool found = false;
        foreach(quint16 v, parts)
            if (v == slice)
            {
                found = true;
                break;
            }
        if (found) continue;
        parts.push_back(slice);
        ++i;
    } while (i< partCount);

    qSort(parts);


    childA.resize(fullGenomeLength());
    childB.resize(fullGenomeLength());

    int posInPartsArray = 0;
    bool fromParentA = true;
    for (int i=0; i<fullGenomeLength(); ++i)
    {
        if (fromParentA)
        {
            childA[i] = parentA[i];
            childB[i] = parentB[i];
        }
        else
        {
            childA[i] = parentB[i];
            childB[i] = parentA[i];
        }
        if (posInPartsArray < parts.count() )
            if (i == parts[posInPartsArray])
            {
                ++posInPartsArray;
                fromParentA = !fromParentA;
            }
       /* ++counter;
        if (counter >= properties.genomeMixPart())
        {
            counter =0;
            fromParentA = !fromParentA;
        }*/
    }
}

CarGenome World::makeChild(const CarGenome &parentA, const CarGenome &parentB)
{
    CarGenome child;
    int partCount = 1 + qrand() % properties.genomeMixPart();
    QVector<quint16> parts;
    int i=0;
    do
    {
        quint16 slice = qrand() % fullGenomeLength();

        bool found = false;
        foreach(quint16 v, parts)
            if (v == slice)
            {
                found = true;
                break;
            }
        if (found) continue;
        parts.push_back(slice);
        ++i;
    } while (i< partCount);

    qSort(parts);


    child.resize(fullGenomeLength());

    int posInPartsArray = 0;
    bool fromParentA = true;
    for (int i=0; i<fullGenomeLength(); ++i)
    {
        if (fromParentA)
        {
            child[i] = parentA[i];
        }
        else
        {
            child[i] = parentB[i];
        }
        if (posInPartsArray < parts.count() )
            if (i == parts[posInPartsArray])
            {
                ++posInPartsArray;
                fromParentA = !fromParentA;
            }
    }

    return child;
}

quint16 World::fullGenomeLength()
{
    return properties.genomeBodyLength() + properties.genomeMaxWheels() *wheelGenomes;
}

quint16 World::currentPopulation()
{
    return _carList.count();
}

quint32 World::generationNumber()
{
    return _generationNumber;
}

quint32 World::generationNumberTopRecord()
{
    return _generationNumberTopRecord;
}

double World::averageTrianglesInCar()
{
    quint32 triangles =0;
    foreach(Car* car, _carList)
        triangles+= car->triangles();
    return ((double)triangles) / ((double)_carList.count());
}

double World::averageWheelsInCar()
{
    quint32 wheels =0;
    foreach(Car* car, _carList)
        wheels+= car->wheels();
    return ((double)wheels) / ((double)_carList.count());
}

CarGenome World::topGenome()
{
    if (_topList.count() > 0)
        return _topList[0].second;
    CarGenome g;
    g.resize(fullGenomeLength());
    return g;
}

const World::GenomeTopList World::topList() const
{
    return _topList;
}

qint64 World::physicTime()
{
    return _physicTime;
}

qint64 World::worldTime()
{
    return _worldTime;
}

void World::mutateGenome(CarGenome &genome)
{
    int mutateCount = 1 + qrand() % properties.genomeMutateMaxCount();
    for (int i=0; i<mutateCount;++i)
    {
        int position = qrand() % fullGenomeLength();
        if (position < properties.genomeBodyLength()) //geometry
        {
            //меняем ген формы тела. изменение может быть только на 1.
            int current =  genome[position].toInt();

            /*if (current == 0)
            {
                if (qrand() %2 !=0)
                {
                    current = qrand() % (properties.genomeBodyLength()+1);
                }
            }
            else
            {
                current += (qrand() % 3) - 1;
            }*/

            int range = ((double)properties.genomeBodyLength()) * properties.genomeMutateRate();

            int increment = (qrand() % range) - (range / 2);
            current += increment;

            genome[position] = current;
            continue;
        }

        if ((position - properties.genomeBodyLength()) %wheelGenomes == WheelVertice) //wheel position
        {
            int current = genome[position].toDouble();
            int range = properties.genomeMutateRate() * (double)properties.genomeBodyLength();

            if (current == 0)
            {
                genome[position+1] = mutateDouble(genome[position+1].toDouble(),properties.wheelMinRadius(), properties.wheelMaxRadius(),properties.genomeMutateRate());
                genome[position+2] = mutateDouble(genome[position+2].toDouble(),properties.wheelMinSpeed(), properties.wheelMaxSpeed(),properties.genomeMutateRate());
                genome[position+3] = mutateDouble(genome[position+3].toDouble(),0, 1,properties.genomeMutateRate());
            }

            int increment = (qrand() % range) - (range / 2);

            current += increment;

            genome[position] = current;

            continue;
        }
        if ((position - properties.genomeBodyLength()) % wheelGenomes == WheelRadius) //wheel radius
        {
            //изменяем диаметр колеса
            genome[position] = mutateDouble(genome[position].toDouble(),properties.wheelMinRadius(), properties.wheelMaxRadius(),properties.genomeMutateRate());
            continue;
        }
        if ((position - properties.genomeBodyLength()) % wheelGenomes == WheelSpeed) //wheel speed
        {
            genome[position] = mutateDouble(genome[position].toDouble(),properties.wheelMinSpeed(), properties.wheelMaxSpeed(),properties.genomeMutateRate());
            continue;
        }

        if ((position - properties.genomeBodyLength()) % wheelGenomes == WheelTorqueCoeff) //wheel torque
        {
            genome[position] = mutateDouble(genome[position].toDouble(),0, 1,properties.genomeMutateRate());
            continue;
        }

    }
}

bool World::topListRecordLessThan(const World::GenomeTopListRecord & a, const World::GenomeTopListRecord & b)
{
    return a.first > b.first;
}
