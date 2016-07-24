#include "renderproperties.h"

bool RenderProperties::isWireframe()
{
    return _wireframe;
}

void RenderProperties::setWireframe(bool isWireframe)
{
    _wireframe = isWireframe;
}

V2Color RenderProperties::color()
{
    return _color;
}

void RenderProperties::setColor(V2Color color)
{
    _color = color;
}

bool RenderProperties::isLightingEnabled()
{
    return _lighting;
}

void RenderProperties::setLighting(bool enabled)
{
    _lighting = enabled;
}

RenderProperties::RenderProperties():
   _wireframe(false), _lighting(true)
{

}
