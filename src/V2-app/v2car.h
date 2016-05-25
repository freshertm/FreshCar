#ifndef V2CAR_H
#define V2CAR_H

#include "worldobject.h"
#include "V1/cargenome.h"
#include "V1/worldproperties.h"

class V2Car : public WorldObject
{
public:
    V2Car(const CarGenome &, const WorldProperties &);
    virtual ~V2Car();
};

#endif // V2CAR_H
