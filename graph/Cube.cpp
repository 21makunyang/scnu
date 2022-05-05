#include "Cube.h"

Cube::Cube(){}

Cube::~Cube(){}

Cube::Cube(float sideLength):Graph(sideLength)
{
    this->sideLength = sideLength;
}

Cube::Cube(float sideLength, float height):Graph(height)
{
    this->sideLength = sideLength;
}

float Cube::getArea() const
{
    return sideLength * sideLength * 2 + sideLength * height * 4;
}

float Cube::getVolumn() const
{
    return sideLength * sideLength * height;
}

ostream & operator<<(ostream& output, const Cube& obj)
{
    output<<"长方体表面积为:"<<obj.getArea()<<'\n';
    output<<"长方体体积为:"<<obj.getVolumn()<<'\n';
    return output;
}