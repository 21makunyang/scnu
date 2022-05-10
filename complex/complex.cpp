#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
    Complex obj1(1,3);
    Complex obj2;
    cin>>obj2;
    cout<<obj2<<'\n';
    obj2 = obj1;
    cout<<obj2;
    return 0;
}