#ifndef BRICK_H
#define BRICK_H
#include "glm.hpp"
#include "worldobject.h"

class Brick : public V2Object
{
public:
    Brick(const glm::vec2& position, float angle, float width, float height);

    ~Brick();
};

#endif // BRICK_H
