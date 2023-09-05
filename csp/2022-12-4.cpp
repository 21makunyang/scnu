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
#define N 3e5+5
#define mp make_pair
#define MAX_A INT_MAX
using namespace std;
typedef long long ll;

int n;
ll sum;
vector<int> hson(N), sz(N);
vector<vector<int>> edge(N);
vector<ll> a(N), ans(N);
multiset<int> mset;
void dfs1(int cur, int par = -1)
{
    int size = 1, ma = 0;
    for (auto child : edge[cur])
    {
        if (child != par)
        {
            dfs1(child, cur);
            size += sz[child];
            if (sz[child] > ma)
            {
                hson[cur] = child;
                ma = sz[child];
            }
        }
    }
    sz[cur] = size;
}

ll cal(ll x, ll y, ll z)
{
    if (abs(y) == MAX_A)
        return 0;
    if (abs(z) != MAX_A && abs(x) != MAX_A)
        return min((y - z) * (y - z), (x - y) * (x - y));
    else if (abs(z) != MAX_A&& abs(x)==MAX_A)
        return (y - z) * (y - z);
    else if (abs(x) != MAX_A&& abs(z)==MAX_A)
        return (x - y) * (x - y);
    else
        return 0;
}
void add(int node)
{
    // 加入一个节点，只可能改变值相邻两个节点的聚集方差增量
    auto it = mset.lower_bound(a[node]);
    it--, it--;
    ll tem[6];
    tem[1] = *it;
    it++;
    tem[2] = *it;
    it++;
    tem[3] = a[node];
    tem[4] = *it;
    it++;
    tem[5] = *it;
    it++;
    sum -= cal(tem[1], tem[2], tem[4]);
    sum -= cal(tem[2], tem[4], tem[5]);
    sum += cal(tem[1], tem[2], tem[3]);
    sum += cal(tem[2], tem[3], tem[4]);
    sum += cal(tem[3], tem[4], tem[5]);
    mset.insert(a[node]);
}
void addSubTree(int node, int par = -1)
{
    add(node);
    for (auto child : edge[node])
    {
        if (child != par)
            addSubTree(child, node);
    }
}
void del(int u)
{
}
void delsubtree(int u, int fa = -1)
{
    del(u);
    for (auto v : edge[u])
    {
        if (v != fa)
            delsubtree(v, u);
    }
}
void init()
{
    mset.insert(MAX_A);
    mset.insert(MAX_A);
    mset.insert(-MAX_A);
    mset.insert(-MAX_A);
}
void solve(int cur, int par = -1, bool keep = -1)
{
    for (auto child : edge[cur])
    {
        if (child != par && child != hson[cur])
            solve(child, cur, 0);
    }
    if (hson[cur])
    {
        solve(hson[cur], cur, true);
    }
    add(cur);
    for (auto v : edge[cur])
    {
        if (v != par && v != hson[cur])
            addSubTree(v, cur);
    }
    ans[cur] = sum;
    if (!keep)
    {
        mset.clear();
        init();
        sum = 0;
    }
}
int main()
{
    // IOS;
    cin >> n;
    // a.resize(n + 1);
    // hson.resize(n + 1);
    // edge.resize(n + 1);
    // sz.resize(n + 1);
    // ans.resize(n + 1);
    sum = 0;
    int v;
    rep(i, 2, n + 1)
    {
        cin >> v;
        edge[v].pb(i);
        edge[i].pb(v);
    }
    rep(i, 1, n + 1)
    {
        cin >> a[i];
    }
    dfs1(1);
    init();
    solve(1);
    rep(i, 1, n + 1)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}