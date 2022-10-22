#include <bits/stdc++.h>
using namespace std;
template<typename T>
class A{
public:
    A();
    ~A();
};
template<typename T>
A<T>::A(){}
template<typename T>
A<T>::~A(){}
int main()
{
    ifstream infile("data3.txt",ios::in);
    infile.seekg(5,ios::beg);
    int num=0;
    infile>>num;
    cout<<num<<"\n";
    infile.close();
    return 0;
}