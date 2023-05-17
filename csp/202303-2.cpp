#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, day, cost, maxD = 0,m;
    cin >> n >> m >> k;
    vector<int> t(100001,{0}), c(100001,{0});
    for (int i = 0; i < n; i++)
    {
        cin >> day >> cost;
        t[day]+=cost;
        maxD = max(maxD, day);
    }
    for (int i = maxD; i >= k; i--)
    {
        if(m>=t[i]){
            m-=t[i];
            t[i-1]+=t[i];
        }else{
            cout<<i<<"\n";
            return 0;
        }
    }
    cout<<k<<"\n";

    return 0;
}