#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (long long i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
#define MOD 1000000007
typedef long long  ll;
using namespace std;

int main(){
    IOS;
    ll x,n,m,k;
    cin>>x>>n>>m>>k;
    vector<ll> method(x+1,{0});
    vector<bool> hasM(x+1,{0});
    // ll dp[1010] = {1, 0};
    method[0] = 1;
    method[n] = 1;
    method[m] = 1;
    method[k] = 1;
    if(m-n>=0)
        method[m]+=method[m-n];
    if(k-n>=0)
        method[k]+=method[k-n];
    if(k-m>=0)
        method[k]+=method[k-m];
    hasM[m]= true;
    hasM[n]= true;
    hasM[k]= true;
    rep(i,1,x+1){
        if(hasM[i]==0){
            hasM[i] = (i-n>=0?hasM[i-n]:false)||(i-m>=0?hasM[i-m]:false)||(i-k>=0?hasM[i-k]:false);
            method[i] = ((i-n>=0?method[i-n]%MOD:0)+
                    (i-m>=0?method[i-m]%MOD:0)+
                    (i-k>=0?method[i-k]%MOD:0))%MOD;
        }
    }
    if(!hasM[x]){
        cout<<"impossible";
        return 0;
    }
    cout<<method[x]<<'\n';
    return 0;
}