#ifndef V2WINDOW_H
#define V2WINDOW_H

class V2Window
{
public:
    V2Window();
    virtual ~V2Window();

    virtual void init(){}
    virtual void finalize(){}
    virtual void swapBuffers(){}
};

#endif // V2WINDOW_H
