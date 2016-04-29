#ifndef V2RESOURCE
#define V2RESOURCE

#include <QMap>
#include <QDebug>
#include <typeinfo>

typedef int V2ResourceClass;

class V2Resource{
public:
    virtual ~V2Resource(){}
};


class V2ResourceContainer{
public:
    virtual ~V2ResourceContainer(){}

    void setResource(V2Resource* res) {
        _resources[typeid(*res).hash_code()] = res;
    }

    template <class T>
    T* resource();
private:
    QHash<size_t, V2Resource*> _resources;
};


template <class T>
T* V2ResourceContainer::resource()
{
    size_t hashCode = typeid(T).hash_code();
    if (!_resources.contains(hashCode)) {
        return nullptr;
    }
    return dynamic_cast<T*>(_resources[hashCode]);
}

#endif // V2RESOURCE

