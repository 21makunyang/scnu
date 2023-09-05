#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (int i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;


using namespace std;
int n;
vector<int> diff;
int ans = 0;

int main( )
{
    IOS;
    cin>>n;
    diff.resize(n);
    int a,b,sum = 0;
    rep(i,0,n){
        cin>>a>>b;
        diff[i] = a-b;
        sum +=a-b;
    }
    sort(diff.begin(),diff.end());
    while(sum!=0){
        if(sum>0){
            
        }
    }
    // int sum1=0,sum2=0;
    vector<int> dp(n+1);
    dp[0] = 0;
    rep(i,0,n){
        int minN =dp[0];
        rep(j,0,i){
            minN = min(minN,abs(dp[j]+diff[i]));
        }
        dp[i+1] = minN;
    }
    cout<<ans;
    return 0;
}