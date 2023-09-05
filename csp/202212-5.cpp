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
// #define MOD 1000000007
const int MOD = 1e9 + 7;
#define INF 0x7fffffffffffffff
#define N 100010
#define M 300010
#define LOG 20
#define mp make_pair
using namespace std;
typedef long long ll;
ll cal(ll a, ll b)
{
    ll contribution = 2;
    a = a % MOD;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            a = (a * contribution) % MOD;
        }
        contribution = (contribution * contribution) % MOD;
        b >>= 1;
    }
    return a;
}
int head[M], lc[M * LOG], rc[M * LOG], tot = 0, ncnt;
int n, m, rt1, rt2;
struct Edge
{
    int next, to, val;
} e[N * LOG];

inline void addedge(int f, int t, int val)
{
    e[++tot].next = head[f];
    e[tot].to = t;
    e[tot].val = val;
    head[f] = tot;
}

void buildOut(int &o, int l, int r)
{ // 建出树
    if (l == r)
    {
        o = l;
        return; // 已经是子节点,直接赋值
    }
    o = ++ncnt;
    int mid = (l + r) >> 1;
    buildOut(lc[o], l, mid);
    buildOut(rc[o], mid + 1, r);
    addedge(o, lc[o], 0); // 从o向o的左右子树连一条权值为0的有向边
    addedge(o, rc[o], 0);
}

void buildIn(int &o, int l, int r)
{ // 建入树
    if (l == r)
    {
        o = l;
        return;
    }
    o = ++ncnt;
    int mid = (l + r) >> 1;
    buildIn(lc[o], l, mid);
    buildIn(rc[o], mid + 1, r);
    addedge(lc[o], o, 0); // 从o向o的左右子树连一条权值为0的有向边
    addedge(rc[o], o, 0);
}
int L, R;
void update(int o, int l, int r, int f, int val, short type)
{
    if (L <= l && R >= r)
    {
        type == 2 ? addedge(f, o, val) : addedge(o, f, val);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(lc[o], l, mid, f, val, type);
    if (R > mid)
        update(rc[o], mid + 1, r, f, val, type);
}
ll dis[M + N + 1];
priority_queue<pair<ll, int>> q;
int vis[M + N + 1];
void dijkstra(int s)
{
    rep(i, 1, ncnt + 1)
    {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            ll z = e[i].val;
            // if (!vis[y] && ((dis[y] == INF) || (dis[y] > dis[x] + z)))
            if (!vis[y] && dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                q.push(make_pair(-dis[y], y));
            }
        }
    }
}

int main()
{
    IOS;
    cin >> n >> m;
    ncnt = n;
    buildOut(rt1, 1, n);
    buildIn(rt2, 1, n);
    int l1, r1, l2, r2, a, b, l;
    rep(i, 0, m)
    {
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        l = cal(a, b);
        L = l1;
        R = r1;
        update(rt2, 1, n, ++ncnt, 0, 1);
        L = l2;
        R = r2;
        update(rt1, 1, n, ncnt, l, 2);
    }
    dijkstra(1);
    vector<ll> dist(n + 1);
    rep(i, 2, n + 1)
    {
        dist[i] = dis[i];
        // cout << dist[i] << ' ';
    }
    rep(i, 2, n + 1)
    {
        dijkstra(i);
        if (dist[i] == INF || dis[1] == INF)
            cout << -1 << ' ';
        else
        {
            cout << (dist[i] + dis[1]) % MOD << ' ';
        }
    }
    return 0;
}
