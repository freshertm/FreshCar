#ifndef CARFACTORY_H
#define CARFACTORY_H

#include <QList>
#include "cargenome.h"
#include "car.h"

class IModule;
class CarFactory
{
public:
    CarFactory();
    ~CarFactory();

    void registerModule(IModule*);
    Car* createCar(const CarGenome&);

private:
    QList<IModule*> iModuleList;
};

#endif // CARFACTORY_H
