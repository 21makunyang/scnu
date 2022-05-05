#include "Cylinder.h"

const float Cylinder::PI = 3.1415926;
Cylinder::Cylinder()
{
    radius = 0;
}

Cylinder::Cylinder(float height, float radius):Graph(height)
{
    this->radius = radius;
}

Cylinder::~Cylinder()
{
}

float  Cylinder::getArea() const
{
    return radius * radius * Cylinder::PI * 2 + radius * 2 * PI * height;
}

float Cylinder::getVolumn() const
{
    return radius * radius * Cylinder::PI * height;
}

ostream& operator<<(ostream& output,const Cylinder& obj)
{
    output<<"圆柱表面积为:"<<obj.getArea()<<'\n';
    output<<"圆柱表面积为:"<<obj.getVolumn()<<'\n';
    return output;
}