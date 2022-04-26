#include "Cube.h"

Cube::Cube(){}

Cube::~Cube(){}

Cube::Cube(float height, float sideLength):Graph(height,sideLength){}

float Cube::getArea()
{
    return sideLength * sideLength * 6;
}

float Cube::getVolumn()
{
    return sideLength * sideLength * height;
}