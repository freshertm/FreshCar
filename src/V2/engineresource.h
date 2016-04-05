#ifndef ENGINE_RESOURCE
#define ENGINE_RESOURCE

class EngineResource{
public:
    enum Type {
        GeometryData = 0,
        CutomResourceId = 1000
    };
    virtual ~EngineResource(){}

    Type type(){
        return _type;
    }

protected :
    EngineResource(Type type): _type(type){}

private:
    Type _type;
};

#endif // ENGINE_RESOURCE

