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
#define MOD 1000000007
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
int head[2][M], lc[2][M * LOG], rc[2][M * LOG], tot[2], ncnt[2];
int n, m, rt1[2], rt2[2];
struct Edge
{
    int next, to, val;
} e[2][N * LOG];

inline void addedge(int f, int t, int val,int g)
{
    e[g][++tot[g]].next = head[g][f];
    e[g][tot[g]].to = t;
    e[g][tot[g]].val = val;
    head[g][f] = tot[g];
}

void buildOut(int &o, int l, int r,int g)
{ // 建出树
    if (l == r)
    {
        o = l;
        return; // 已经是子节点,直接赋值
    }
    o = ++ncnt[g];
    int mid = (l + r) >> 1;
    buildOut(lc[g][o], l, mid,g);
    buildOut(rc[g][o], mid + 1, r,g);
    addedge(o, lc[g][o], 0,g); // 从o向o的左右子树连一条权值为0的有向边
    addedge(o, rc[g][o], 0,g);
}

void buildIn(int &o, int l, int r,int g)
{ // 建入树
    if (l == r)
    {
        o = l;
        return;
    }
    o = ++ncnt[g];
    int mid = (l + r) >> 1;
    buildIn(lc[g][o], l, mid,g);
    buildIn(rc[g][o], mid + 1, r,g);
    addedge(lc[g][o], o, 0,g); // 从o向o的左右子树连一条权值为0的有向边
    addedge(rc[g][o], o, 0,g);
}
int L, R;
void update(int o, int l, int r, int f, int val, short type,int g)
{
    if (L <= l && R >= r)
    {
        type == 2 ? addedge(f, o, val,g) : addedge(o, f, val,g);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(lc[g][o], l, mid, f, val, type,g);
    if (R > mid)
        update(rc[g][o], mid + 1, r, f, val, type,g);
}
ll dis[M + N + 1];
priority_queue<pair<ll, int>> q;
int vis[M + N + 1];
void dijkstra(int s,int g)
{
    rep(i, 1,ncnt[g] + 1)
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
        for (int i = head[g][x]; i; i = e[g][i].next)
        {
            int y = e[g][i].to;
            ll z = e[g][i].val;
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
    ncnt[1] = n;
    buildOut(rt1[0], 1, n,0);
    buildIn(rt2[0], 1, n,0);
    int md[m + 1][5];
    ll d[m + 1];
    int l1, r1, l2, r2, a, b;
    ll l;
    rep(i, 0, m)
    {
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        md[i][0] = l1;
        md[i][1] = r1;
        md[i][2] = l2;
        md[i][3] = r2;

        l = cal(a, b);
        md[i][4] = l;
        d[i] = l;
        L = l1;
        R = r1;
        update(rt2[0], 1, n, ++ncnt[0], 0, 1,0);
        L = l2;
        R = r2;
        update(rt1[0], 1, n, ncnt[0], l, 2,0);
    }
    dijkstra(1,0);
    vector<ll> dist(n + 1);
    rep(i, 2, n + 1)
    {
        dist[i] = dis[i];
        // cout << dist[i] << ' ';
    }
    
    ncnt[1] = n;
    tot[1] = 0;
    rt1[1] = rt2[1] = 0;
    buildIn(rt1[1], 1, n,1);
    buildOut(rt2[1], 1, n,1);
    rep(i, 0, m)
    {
        L = md[i][2];
        R = md[i][3];
        update(rt1[1], 1, n, ++ncnt[1], d[i], 1,1);
        L = md[i][0];
        R = md[i][1];
        update(rt2[1], 1, n, ncnt[1], 0, 2,1);
    }
    dijkstra(1,1);
    rep(i, 2, n + 1)
    {
        if (dist[i] == INF || dis[i] == INF)
            cout << -1 << ' ';
        else
        {
            cout << (dist[i] + dis[i]) % MOD << ' ';
        }
    }
    return 0;
}
