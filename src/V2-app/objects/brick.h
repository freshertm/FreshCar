#ifndef BRICK_H
#define BRICK_H
#include <glm/glm.hpp>
#include "v2object.h"
#include <memory>
#include "v2renderproperties.h"
const float brickDepth=10;


class Brick : public V2Object
{
public:
    Brick(const glm::vec2& position, float angle, float width, float height);

    ~Brick();
private:
    //std::shared_ptr<V2RenderProperties> _prop;
};

#endif // BRICK_H
