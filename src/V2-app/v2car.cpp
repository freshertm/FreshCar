#include "v2car.h"
#include "carbodycreator.h"
#include "geometry.h"
#include "cargenome.h"

V2Car::V2Car(const CarGenome & genome, const WorldProperties& properties)
{
    CarBodyCreator creator(genome, properties);
    setResource(creator.createGeometry());
    //setResource(&genome);
}

V2Car::~V2Car()
{

}
