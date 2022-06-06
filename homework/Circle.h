#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Shape.h"
class Circle:public Shape
{
private:
    float radis;
public:
    static float PI ;
    Circle(/* args */);
    Circle(float radis);
    ~Circle();
    float printArea();
};



#endif