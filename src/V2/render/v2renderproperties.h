#ifndef RENDERPROPERTIES_H
#define RENDERPROPERTIES_H
#include "v2resource.h"
#include "v2color.h"

class V2RenderProperties : public V2Resource
{
public:
    bool isWireframe();
    void setWireframe(bool isWireframe);

    V2Color color();
    void setColor(V2Color color);

    bool isLightingEnabled();
    void setLighting(bool enabled);

    bool isShowNormals();
    void setShowNormals(bool enabled);

    V2RenderProperties();
    virtual ~V2RenderProperties(){}

private:
    bool _wireframe;
    V2Color _color;
    bool _lighting;
    bool _showNormals;
};

#endif // RENDERPROPERTIES_H
