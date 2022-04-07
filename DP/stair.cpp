#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int i,f=1,s=1,ans=0;
    if(n<=2) return 1;
    else
    {
        for(i=2;i<n;i++)
        {
            ans=f+s;
            f=s;
            s=ans;
        }
        return ans;
    }
}
int main()
{
    int n,i,f,k;
    cin>>n;
    cout<<fib(n);
    return 0;
}