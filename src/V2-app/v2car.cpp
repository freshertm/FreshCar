#include "v2car.h"
#include "V1/carbodycreator.h"

V2Car::V2Car(const CarGenome & genome, const WorldProperties& properties)
{
    CarBodyCreator creator(genome, properties);
    //setResource<Geometry>(creator.createGeometry());
    //setResource<CarGenome>(&genome);
}

V2Car::~V2Car()
{

}
