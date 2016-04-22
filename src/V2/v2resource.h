#ifndef V2RESOURCE
#define V2RESOURCE

#include <QMap>

typedef int V2ResourceClass;
class V2Resource{
public:
    V2Resource(V2ResourceClass type):_type(type){}
    virtual ~V2Resource(){}
    V2ResourceClass type(){return _type;}
private:
    V2ResourceClass _type;
};


class V2ResourceContainer{
public:

    void setResource(V2ResourceClass resourceType, V2Resource* res) { _resources[resourceType] = res; }
    V2Resource  * resource(V2ResourceClass resourceType){return _resources[resourceType];}
    //void destroyResource(V2ResourceType resourceType){}
private:
    QMap<V2ResourceClass, V2Resource*> _resources;
};


enum V2CommonResources{
    V2Geometry = 0,
    V2OutputWindow,

    V2UserResource=1000
};


#endif // V2RESOURCE

