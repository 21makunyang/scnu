#ifndef _CENTRUM_H_
#define _CENTRUM_H_

#include "Graph.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
using namespace std;
class Centrum:public Graph
{
    public:
        static const float PI;
        Centrum();
        Centrum(float height, float radius,float sideLength);
        ~Centrum();
    private:
        float radius;
    public:
        float getArea();
        float getVolumn();
};


#endif