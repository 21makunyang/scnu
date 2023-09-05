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
int n, m, k;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> color;
bool islegal(int v)
{

    for (auto next : graph[v])
    {
        if (color[v] == color[next])
            return false;
    }
    return true;
}
int ans = 0;
void traceBack(int v)
{
    if (n+1 == v)
    {
        // for(auto co:color){
        //     cout<<co<<' ';
        // }
        ans++;
        // cout<<ans<<'\n';
        return;
    }
    rep(i, 1, k + 1)
    {
        color[v] = i;
        if (islegal(v))
        {
            traceBack(v + 1);
        }
        color[v] = 0;
    }
}
int main()
{
    IOS;
    cin >> n >> m >> k;
    graph.resize(n + 1);
    color.resize(n + 1);
    int be, end;
    rep(i, 0, m)
    {
        cin >> be >> end;
        graph[be].pb(end);
        graph[end].pb(be);
    }
    traceBack(1);
    cout << ans ;
    return 0;
}