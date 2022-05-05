#ifndef _CENTRUM_H_
#define _CENTRUM_H_

#include "Graph.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
using namespace std;
class Centrum : public Graph
{
public:
    static const float PI;
    Centrum();
    Centrum(float height, float radius);
    ~Centrum();
    //把运算符重载函数声明为类的友元函数，这样我们就能不用创建对象而直接调用函数
    friend ostream &operator<<(ostream &output_, const Centrum &ct);
    //void err()
private: 
    float radius;

public:
    float getArea() const;
    float getVolumn() const;
};



#endif