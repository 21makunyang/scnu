#ifndef _CYLINDER_H_
#define _CYLINDER_H_

#include "Graph.h"
#include <cstddef>
#include <iostream>
using namespace std;
class Cylinder : public Graph
{
public:
    static const float PI;
    Cylinder();
    Cylinder(float height, float radius);
    ~Cylinder();

private:
    float radius;
public:
    float getArea() const;
    float getVolumn() const;
    friend ostream& operator<<(ostream& output,const Cylinder& obj);
};

#endif