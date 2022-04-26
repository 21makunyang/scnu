#include "Centrum.h"
const float Centrum::PI = 3.1415926;

Centrum::Centrum(/* args */){}

Centrum::~Centrum(){}

Centrum::Centrum(float height, float radius, float sideLength):Graph(height, sideLength)
{
    this->radius = radius;
}

float Centrum::getArea()
{
    return radius * radius * Centrum::PI + sqrt(pow(radius, 2)+pow(height, 2)) * 2 * Centrum::PI * radius;
}

float Centrum::getVolumn()
{
    return radius * radius * Centrum::PI * height;
}