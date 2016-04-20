#include "carfactory.h"

CarFactory::CarFactory()
{

}

CarFactory::~CarFactory()
{

}

void CarFactory::registerModule(IModule *m)
{
    iModuleList.append(m);
}

Car *CarFactory::createCar(const CarGenome & genome)
{
    return nullptr;
}

