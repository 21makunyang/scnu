#ifndef _RETANGLE_H_
#define _RETANGLE_H_
#include "Shape.h"
class Rectangle:public Shape
{
private:
    float length;
    float width;
public:
    Rectangle();
    Rectangle(float length,float width);
    ~Rectangle();
    float printArea();
};
#endif
