#include "Graph.h"

Graph::Graph()
{
    sideLength = 0;
    height = 0;
}

Graph::Graph(float height, float sideLength = 0)
{
    this->sideLength = sideLength; 
    this->height = height;
}

Graph::~Graph(){}