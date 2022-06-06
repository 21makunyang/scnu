#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main()
{
    Circle cir(1);
    Rectangle rec(1,2);
    Triangle tri(3,4,5);
    Shape *p = &cir;
    (*p).printArea();
    p = &rec;
    (*p).printArea();
    p= &tri;
    (*p).printArea();
    return 0;
}