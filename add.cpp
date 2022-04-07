#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
        return (long)(&(((char*)(long)a)[b]));
    }
int main()
{
    int a=1,b=20;
    cout<<add(a,b);
    return 0;
}