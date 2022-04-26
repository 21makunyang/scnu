#ifndef _CUBE_H_
#define _CUBE_H_

#include "Graph.h"
class Cube:public Graph
{
    public:
        Cube();
        Cube(float sideLength, float height);
        ~Cube();
        float getArea();
        float getVolumn();
};


#endif