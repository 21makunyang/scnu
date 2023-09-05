#include <bits/stdc++.h>                         //POJ不支持
#define rep(i, a, n) for (int i = a; i < n; i++) // i为循环变量，a为初始值，n为界限值，递增
#define per(i, a, n) for (int i = a; i > n; i--) // i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    rep(i, 0, n + 1)
    {
        cin >> cost[i];
    }
    int co;
    per(i, n, 0)
    {
        int cur =n-i; 
        rep(j, 1, i+1)
        {
            cin >> co;
            if(cost[cur+j]>cost[cur]+co){
                cost[cur+j]=cost[cur]+co;
            }
        }
    }
    cout<<cost[n]<<'\n';
    return 0;
}