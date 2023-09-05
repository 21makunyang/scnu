#include <bits/stdc++.h>                               //POJ不支持
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
// typedef long long int;
int main()
{
    IOS;
    int n, m, sum = 1;
    cin >> n >> m;
    vector<int> dp(n + 1, {0});
    vector<vector<int>> t(n+1,vector<int>(n+1,{0}));
    rep(i,1,n+1){
        rep(j,2,i+1){
            t[i/j][i]++;
        }
    }
    dp[n] = 1;
    per(i, n - 1, 0)
    {
        dp[i] = sum;
        // int r = min(n,i*i);
        // rep(j,i+1,r) dp[i] = (dp[i]+dp[j])%m;
        // if(r<n){
        //     int k=i+1;
        //     while(k*i<=n){

        //     }
        // }
        rep(j,i+1,n+1){
            dp[i]=(dp[i]+(t[i][j]*dp[j])%m)%m;
        }

        sum =(sum+dp[i])%m;
    }
    cout << dp[1] << '\n';
    return 0;
}