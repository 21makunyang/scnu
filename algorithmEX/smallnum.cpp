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

inline int read(){
    int data=0,w=1;char ch=0;
    while(ch!='-' && (ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0' && ch<='9')data=data*10+ch-'0',ch=getchar();
    return data*w;
}
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,{0}));
        rep(i,0,n){
            dp[0][i] = matrix[0][i];
        }
        rep(i,1,n){
            rep(j,0,n){
                int min = dp[i-1][j];
                if(j-1>=0&&min>dp[i-1][j-1]) min = dp[i-1][j-1];
                if(j+1<n&&min>dp[i-1][j+1]) min = dp[i-1][j+1];
                dp[i][j] = min+matrix[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
int main(){


    return 0;
}