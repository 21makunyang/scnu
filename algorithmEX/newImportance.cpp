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
    int n,m,be,end,k;
    scanf("%d %d",&n,&m);
    vector<vector<int>> nodes(n+1);
    vector<bool> visited(n + 1, {0});

    rep(i,0,m){
        scanf("%d %d",&be,&end);
        nodes[be].pb(end);
        nodes[end].pb(be);
    }
    function<float(int)> bfs;
    bfs = [&](int v)->float
    {
        int sum = 0;
        int level = 0;//curent level
        int curLevelN = 1;//nodes' number of curent level 
        int nextLevelN = 0;//nodes' number of the next level
        int curIdx = 0;//record curent node Index
        queue<int> que;
        visited[v] = true;
        // que.push(v);
        rep(i, 0, nodes[v].size())
        {
            if (!visited[nodes[v][i]])
            {
                que.push(nodes[v][i]);
                nextLevelN++;
            }
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            curIdx++;
            if(curIdx==curLevelN){
                level++;
                curIdx = 0;
                curLevelN = nextLevelN;
                nextLevelN=0;
            }
            if(visited[cur]) continue;
            visited[cur] = true;
            sum+=level;
            rep(i,0,nodes[cur].size()){
                int nextNode = nodes[cur][i];
                if(!visited[nextNode]){
                    nextLevelN ++;
                    que.push(nodes[cur][i]);
                }
            }
        }
        if(sum==0){
            return 0;
        }
        return float(n-1)/float(sum);
    };
    scanf("%d",&k);
    rep(i,0,k){
        rep(j,1,n+1) visited[j] = false;
        scanf("%d",&be);
        float ans = bfs(be);
        // bool connected = true;
        rep(j,1,n+1){
            if(!visited[j]){
                ans = 0;
            }
        }
        printf("Cc(%d)=%.2f\n",be,ans);
    }

    return 0;
}