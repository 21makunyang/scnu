#include <iostream>
#include <cmath>
using namespace std;
#define m 1000000007
int main(){
    unsigned int n,x;
    cin>>n>>x;
    unsigned int sum=0;
    for (unsigned int i = 0; i <= n; i++)
    {
        sum+=(i^x);
    }
    cout<<sum%m;
    // unsigned int i=0;
    // cout<<(i^5);
    return 0;
}
