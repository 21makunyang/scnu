#include "Rectangle.h"
#include <iostream>
using namespace std;
 
Rectangle::Rectangle(/* args */)
{
}
Rectangle::Rectangle(float length,float width)
{
    this->length = length;
    this->width = width;
}
Rectangle::~Rectangle()
{
}
float Rectangle::printArea()
{
    cout<<"矩形面积："<<length*width<<'\n';
    return length*width;
}