#ifndef _GRAPH_H_
#define _GRAPH_H_

class Graph
{
    public:
        Graph();
        Graph(float sideLength, float height);
        ~Graph();
    protected:
        float sideLength;
        float height;
    public:
        float getSideLength(){ return sideLength; };
        float getHeight(){ return height;};
        virtual float getArea() = 0;
        virtual float getVolumn() = 0;
};



#endif