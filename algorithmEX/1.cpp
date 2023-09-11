#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int a[100001];
#define MAX_L 10000000
int main(){
    int T,n;
    cin>>T;
    int ans;
    rep(i,0,T){
        cin>>n;
        map<int,int> dic;
        int max,ans=MAX_L;
        dic.clear();
        rep(j,0,n){
            cin>>a[j];
            if(dic.find(a[j])!=dic.end()){
                ans = min(ans,j-dic[a[j]]);
            }
            dic[a[j]] = j;
        }
        if(ans==MAX_L){
            cout<<0<<'\n';
            continue;
        }
        cout<<ans<<'\n';
    }

    return 0;
}