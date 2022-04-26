#ifndef _CYLINDER_H_
#define _CYLINDER_H_

#include "Graph.h"
#include <cstddef>
class Cylinder:public Graph
{
    public:
        static const float PI;
        Cylinder();
        Cylinder(float height, float radius,float sideLength);
        ~Cylinder();
    private:
        float radius;
    public:
        float getArea();
        float getVolumn();
};


#endif