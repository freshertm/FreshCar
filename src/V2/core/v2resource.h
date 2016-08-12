#ifndef V2RESOURCE
#define V2RESOURCE

#include <QList>
#include <QMap>
#include <QDebug>
#include <typeinfo>
#include <typeindex>

typedef int V2ResourceClass;

class V2Resource{
public:
    virtual ~V2Resource(){}
};


class V2ResourceContainer{
public:
    virtual ~V2ResourceContainer(){}

    void setResource(V2Resource* res) {
        //_resources[typeid(*res).hash_code()] = res;
        _resources.insert(typeid(res), res);
    }

    template <class T>
    T* resource();

    template <class T>
    QList<T*> resources();

private:
    QMultiMap<std::type_index, V2Resource*> _resources;
};


template <class T>
T* V2ResourceContainer::resource()
{
/*    size_t hashCode = typeid(T).hash_code();
    if (!_resources.contains(hashCode)) {
        return nullptr;
    }

    return dynamic_cast<T*>(_resources[hashCode]);*/

    QList<T*> res = resources<T>();
    if (res.size() > 0)
    {
        return res.first();
    }
    return nullptr;
}

template <class T>
QList<T*> V2ResourceContainer::resources()
{
    QList<V2Resource*> resList =  _resources.values(typeid(T));
    QList<T*> tList;

    foreach(V2Resource * res , resList) {
        T* obj = dynamic_cast<T*>(res);
        if (nullptr != obj) {
            tList.push_back(obj);
        }
    }
    return tList;
}

#endif // V2RESOURCE

