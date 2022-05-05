#ifndef _CUBE_H_
#define _CUBE_H_

#include "Graph.h"
#include <iostream>
using namespace std;
class Cube : public Graph
{
public:
    Cube();
    Cube(float sideLength, float height);
    Cube(float sideLength);
    ~Cube();
    float getArea() const;
    float getVolumn() const;
private:
    float sideLength;
public:
    float getSideLength(){ return sideLength; };
    friend ostream & operator<<(ostream& output, const Cube& obj);
};

#endif