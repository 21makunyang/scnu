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
typedef ll number;

int main()
{
    IOS;
    number m, n;
    cin >> m >> n;

    vector<number> dp(m*(n-1) + 1);
    dp[1] = 1;
    dp[2] = 2;
    rep(i, 3, m*(n-1) + 1)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[m*(n-1)]<<'\n';
    return 0;
}