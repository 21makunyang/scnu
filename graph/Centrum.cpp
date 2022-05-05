#include "Centrum.h"
const float Centrum::PI = 3.1415926;

Centrum::Centrum(/* args */){}

Centrum::~Centrum(){}

Centrum::Centrum(float height, float radius):Graph(height)
{
    this->radius = radius;
}

float Centrum::getArea() const 
{
    return radius * radius * Centrum::PI + sqrt(pow(radius, 2)+pow(height, 2)) * 2 * Centrum::PI * radius;
}

float Centrum::getVolumn() const
{
    return radius * radius * Centrum::PI * height;
}

ostream& operator<<(ostream &output_, const Centrum& ct)
{
    output_ << "圆锥表面积为:" << ct.getArea() << '\n'
            << "圆锥体积为:" << ct.getVolumn() << '\n';
    return output_;
}