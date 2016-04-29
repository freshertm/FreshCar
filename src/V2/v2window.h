#ifndef V2WINDOW_H
#define V2WINDOW_H

#include "imodule.h"
class V2Window: public IModule
{
public:
    V2Window();
    virtual ~V2Window();

    virtual void init(){}
    virtual void finalize(){}
    virtual void swapBuffers(){}
};

#endif // V2WINDOW_H
