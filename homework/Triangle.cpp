#include "Triangle.h"
#include  <cmath>

Triangle::Triangle(/* args */)
{
}

Triangle::~Triangle()
{
}
Triangle::Triangle(float a,float b,float c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}
float Triangle::printArea()
{
    float p = a/2.0 + b/2.0 +c/2.0;
    cout<<"三角形面积："<<sqrt(p *(p - a) *(p - b) *(p - c))<<'\n';
    return sqrt(p *(p - a) *(p - b) *(p - c));
}