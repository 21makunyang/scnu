#include "Cylinder.h"

const float Cylinder::PI = 3.1415926;
Cylinder::Cylinder()
{
    radius = 0;
}

Cylinder::Cylinder(float height, float radius,float sideLengt=0):Graph(height,sideLength)
{
    this->radius = radius;
}

Cylinder::~Cylinder()
{
}

float  Cylinder::getArea()
{
    return radius * radius * Cylinder::PI * 2 + radius * 2 * PI * height;
}

float Cylinder::getVolumn()
{
    return radius * radius * Cylinder::PI * height;
}