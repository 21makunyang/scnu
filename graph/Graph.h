#ifndef _GRAPH_H_
#define _GRAPH_H_

class Graph
{
    public:
        Graph();
        Graph(float height);
        ~Graph();
    protected:
        float height;
    public:
        float getHeight(){ return height;};
        virtual float getArea() const = 0;
        virtual float getVolumn() const = 0;
};



#endif