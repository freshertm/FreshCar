#ifndef V2COLOR_H
#define V2COLOR_H
#include <stdint.h>

class V2Color {
public:
    V2Color(uint8_t r =0, uint8_t g=0, uint8_t b=0):
        _r(r),_g(g),_b(b){}
    uint8_t r(){return _r;}
    uint8_t g(){return _g;}
    uint8_t b(){return _b;}

    void setR(uint8_t r){_r=r;}
    void setG(uint8_t g){_g=g;}
    void setB(uint8_t b){_b=b;}

private:
    uint8_t _r;
    uint8_t _g;
    uint8_t _b;
};

#endif // V2COLOR_H
