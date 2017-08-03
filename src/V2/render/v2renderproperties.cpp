#include "v2renderproperties.h"

bool V2RenderProperties::isWireframe()
{
    return _wireframe;
}

void V2RenderProperties::setWireframe(bool isWireframe)
{
    _wireframe = isWireframe;
}

V2Color V2RenderProperties::color()
{
    return _color;
}

void V2RenderProperties::setColor(V2Color color)
{
    _color = color;
}

bool V2RenderProperties::isLightingEnabled()
{
    return _lighting;
}

void V2RenderProperties::setLighting(bool enabled)
{
    _lighting = enabled;
}

bool V2RenderProperties::isShowNormals()
{
    return _showNormals;
}

void V2RenderProperties::setShowNormals(bool enabled)
{
    _showNormals = enabled;
}

V2RenderProperties::V2RenderProperties():
   _wireframe(false), _lighting(true)
{

}
