#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,x,y;
    cin>>n>>k;
    vector<bool> a(n+1,{0});
    a[0] = true;
    int cnt = 0;
    for (int  i = 0; i < k; i++)
    {
        cin>>x>>y;
        if(!a[y]){
            cnt++;
        }
        a[x] = true;
    }
    cout<<cnt<<'\n';
    return 0;
}