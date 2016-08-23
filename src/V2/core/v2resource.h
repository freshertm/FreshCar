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

    template <class T>
    void setResource(T* res) {
        //_resources[typeid(*res).hash_code()] = res;
        _resources.insert(typeid(res), res);
        qDebug() << typeid(res).name() << endl;
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

    qDebug() << typeid(T*).name() << endl;
    QList<T*> tList;
    for (auto resIter = _resources.find(typeid(T*));
         resIter != _resources.end(); ++resIter)
    {
        T* obj = dynamic_cast<T*>(*resIter);
        if (nullptr != obj) {
            tList.push_back(obj);
        }
    }

    return tList;
}

#endif // V2RESOURCE

