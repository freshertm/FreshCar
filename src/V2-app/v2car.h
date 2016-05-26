#ifndef V2CAR_H
#define V2CAR_H

#include "worldobject.h"
#include "cargenome.h"
#include "worldproperties.h"

class V2Car : public V2Object
{
public:
    V2Car(const CarGenome &, const WorldProperties &);
    virtual ~V2Car();
};

#endif // V2CAR_H
