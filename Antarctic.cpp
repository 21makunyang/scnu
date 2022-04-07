#include <bits/stdc++.h>
using namespace std;

int main()
{
    int money,x,k,sum,day;
    float avar;
    cin>>money;
    avar=money/364.0;
    if(avar>103)
    {
        x=100;
        k=ceil((avar-100)/3);
    }
    else
    {
        k=1;
        x=ceil(avar-3);
    }
    while(364*(3*k+x)>money)
    {
        x--;
    }
    cout<<x<<'\n'<<k<<'\n';
    return 0;
}