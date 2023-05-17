#include <bits/stdc++.h>

using namespace std;

vector<int> a, d, t;
int ans = 0,n;
void pick(int index,int pickTime,int ti,int num){
    if(ti<0){
        return;
    }
    ans = max(num,ans);
    if(a[index]-d[index]*pickTime<0){
        return;
    }
    pick(index,pickTime+1,ti-1,num+a[index]-d[index]*pickTime);
    int sumT = t[index];

    for (int i = index+1; i < n; i++)
    {
        pick(i,0,ti-sumT-1,num);
        sumT+=t[i];
    }
    
}
int main()
{
    int ti;
    cin >> n >> ti;
    a.resize(n);
    d.resize(n);
    t.resize(n-1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n - 1; i++)
        cin >> t[i];
    // max[i][j]表示第i分钟，在第j棵树下能摘到的最多果子数
    // vector<vector<int>> maxApples(n + 1, vector<int>(n + 1, {0}));
    pick(0,0,ti,0);
    cout<<ans<<'\n';
    
    return 0;
}