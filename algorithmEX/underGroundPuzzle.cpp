#include<bits/stdc++.h>    //POJ不支持
#define rep(i,a,n) for (int i=a;i<n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair
using namespace std;
stack<int> stk;
bool firstFlag = true;
int main(){
    IOS;
    int n,m,k,be,end;
    cin>>n>>m>>k;
    vector<vector<int>> nodes(n+1);
    vector<bool> visited(n+1,{0});
    rep(i,0,m){
        cin>>be>>end;
        nodes[be].push_back(end);
        nodes[end].push_back(be);
    }
    rep(i,1,n+1){
        sort(nodes[i].begin(),nodes[i].end());
    }
    function<void(int)> dfs;
    dfs = [&](int v){
        visited[v] = true;
        if(firstFlag){
            firstFlag = false;
        }else{
            cout<<' ';
        }
        cout<<v;
        rep(i,0,nodes[v].size()){
            if(!visited[nodes[v][i]]){
                dfs(nodes[v][i]);
                cout<<' '<<v;
            } 
        }
    };
    if(nodes[k].size() == 0){
        cout<<k<<"0\n";
        return 0;
    }
    dfs(k);
    
    rep(i,1,n+1){
        if(!visited[i]){
            cout<<" 0\n";
            return 0;
        }
    }
    cout<<'\n';
    return 0;
}