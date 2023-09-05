#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (int i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main(){
    IOS;
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> dp(n+1,{0});
    rep(i,0,n){
        cin>>a[i];
    }
    if(n==1){
        cout<<a[0]<<'\n';
        return 0;
    }
    int ans = 0;
    rep(i,1,n+1){
        dp[i] = max(dp[i-1]+a[i-1],a[i-1]);
        ans = max(ans,dp[i]);
    }
    cout<<ans<<'\n';
    return 0;
}