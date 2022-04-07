#include <iostream>
// #include <string>
using namespace std;
//基类

class Point
{
public:
    Point(double h,double v);
    Point(const Point &p);
    static size_t getNpos();
    Point();
    ~Point();
    const static size_t nps;
private:
    double x,y;
};

const size_t Point::nps = -1;

size_t Point::getNpos()
{
    return nps;
}
class Line
{
public:
    Line(double a1,double a2,double b1,double b2,char ch); 
    ~Line();
private:
    Point p1;
    Point p2;
    char c;
};

Point::Point(double h, double v )
{
    x=h;
    y=v;
    cout<<"Point(double, double)"<<'\n';
}
Point::Point()
{
    x=0;
    y=0;
    cout<<"Point()"<<'\n';
}
Point::~Point()
{
    cout<<"~Point()"<<'\n';
}
Point::Point(const Point&p)
{
    x=p.x;
    y=p.y;
    cout<<"Point(const Point&p)"<<'\n';
}
Line::Line(double a1,double a2,double b1,double b2,char ch):p1(a1,a2),p2(b1,b2)
{
    c=ch;
    cout<<"Line()"<<'\n';
}
Line::~Line()
{
    cout<<"~Line()"<<'\n';
}
int main()
{
    // Point p1(4.5,6.7),p2(6.7,8.9);
    // Line t(1.1,2,3,4,'g');
    cout<<Point::getNpos();
    return 0;
}