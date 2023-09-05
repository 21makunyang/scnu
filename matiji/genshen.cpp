#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (long long i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
int main(){
    IOS;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> cost(n+1);
    rep(i,0,n+1){
        cost[i].resize(n+1-i);
        rep(j,0,n+1-i){
            cin>>cost[i][j];
        }

    }
    return 0;
}