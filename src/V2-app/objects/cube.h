#ifndef CUBE_H
#define CUBE_H

#include "v2object.h"

class Cube: public V2Object
{
public:
    Cube(const glm::vec2& position, float angle, float size);
};

#endif // CUBE_H
