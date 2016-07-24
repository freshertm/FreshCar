#include "renderproperties.h"

bool RenderProperties::isWireframe()
{
    return _wireframe;
}

void RenderProperties::setWireframe(bool isWireframe)
{
    _wireframe = isWireframe;
}

RenderProperties::RenderProperties():
   _wireframe(false)
{

}
