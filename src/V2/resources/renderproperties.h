#ifndef RENDERPROPERTIES_H
#define RENDERPROPERTIES_H

#include "v2resource.h"
class RenderProperties : public V2Resource
{
public:
    bool isWireframe();
    void setWireframe(bool isWireframe);

    RenderProperties();

private:
    bool _wireframe;
};

#endif // RENDERPROPERTIES_H
