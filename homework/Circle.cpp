#include "Circle.h"
#include <iostream>
using namespace std;
float Circle::PI = 3.14;
Circle::Circle(/* args */)
{
}

Circle::~Circle()
{
}

Circle::Circle(float radis)
{
    this->radis = radis;
}
float Circle::printArea()
{
    cout<<"圆形面积："<<radis*radis*PI<<'\n';
    return radis*radis*PI;
}