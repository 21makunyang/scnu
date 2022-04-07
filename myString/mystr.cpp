#include "MyString.h"
//#include "tools.h"
#include <iostream>
using namespace std;
int main()
{
    MyString str1("zshnb");
    MyString str2("mkysb",5);
    str1.showMyString();
    cout<<MyString::npos;
    cout<<str2.getStr()<<'\n';
    cout<<str2.find('z')<<'\n';
    cout<<1<<'\n';
    str1.append(str2);
    str1.showMyString();
    str1.Swap(str1,str2);
    str1.showMyString();
    str1=str2;
    str1.showMyString();
    return 0;
}
