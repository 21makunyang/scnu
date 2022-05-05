#include "Graph.h"
#include "Centrum.h"
#include "Cylinder.h"
#include "Cube.h"
#include <iostream>

using namespace std;

int main()
{
    Centrum ct(1.0,2);
    cout<<ct;
    Cylinder cl(1.0,2);
    cout<<cl;
    Cube cu(1.0,2);
    cout<<cu;
    Cube cu2(1.0);
    cout<<cu2;
    return 0;
}