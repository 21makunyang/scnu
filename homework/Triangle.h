#ifndef _TRIANGELE_H_
#define _TRIANGELE_H_
#include "Shape.h"
class Triangle:public Shape
{
private:
    float a;
    float b;
    float c;
public:
    Triangle(/* args */);
    Triangle(float a,float b,float c);
    ~Triangle();
    float printArea();
};




#endif