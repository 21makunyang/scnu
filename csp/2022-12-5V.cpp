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
#define N 200010
#define M 200010
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
bool smaller(ll a1, ll b1, ll a2, ll b2)
{
    if (a1 < a2 && b1 <= b2)
    {
        return true;
    }
    if (a1 < a2 && b1 > b2)
    {
        a1 *= 2;
        b1--;
        while (a1 < a2)
        {

            a1 *= 2;
            b1--;
            if (b1 == b2)
            {
                return a1 < a2;
            }
        }
        return false;
    }
    if(a1==a2) return b1<b2;
    if(b1==b2) return a1<a2;
    if (a1 > a2 && b1 < b2)
    {
        a2 *= 2;
        b2--;
        while (a1 > a2)
        {

            a2 *= 2;
            b2--;
            if (b1 == b2)
            {
                return a1 < a2;
            }
        }
        return false;
    }
    return false;
}
int head[2][M + N], lc[2][M * LOG], rc[2][M * LOG], tot[2], ncnt[2];
int n, m, rt1[2], rt2[2];
struct Edge
{
    int next, to,a,b;
} e[2][N * LOG];

inline void addedge(int f, int t, int a,int b, int g)
{
    e[g][++tot[g]].next = head[g][f];
    e[g][tot[g]].to = t;
    e[g][tot[g]].a = a;
    e[g][tot[g]].b = b;

    head[g][f] = tot[g];
}

void buildOut(int &o, int l, int r, int g)
{ // 建出树
    if (l == r)
    {
        o = l;
        return; // 已经是子节点,直接赋值
    }
    o = ++ncnt[g];
    // cout<<ncnt[g]<<'\n';
    int mid = (l + r) >> 1;
    buildOut(lc[g][o], l, mid, g);
    buildOut(rc[g][o], mid + 1, r, g);
    addedge(o, lc[g][o], 0,0, g); // 从o向o的左右子树连一条权值为0的有向边
    addedge(o, rc[g][o], 0,0, g);
}

void buildIn(int &o, int l, int r, int g)
{ // 建入树
    if (l == r)
    {
        o = l;
        return;
    }
    o = ++ncnt[g];
    int mid = (l + r) >> 1;
    buildIn(lc[g][o], l, mid, g);
    buildIn(rc[g][o], mid + 1, r, g);
    addedge(lc[g][o], o, 0,0, g); // 从o向o的左右子树连一条权值为0的有向边
    addedge(rc[g][o], o, 0,0, g);
}
int L, R;
void update(int o, int l, int r, int f, int a,int b, short type, int g)
{
    if (L <= l && R >= r)
    {
        type == 2 ? addedge(f, o, a,b, g) : addedge(o, f, a,b, g);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(lc[g][o], l, mid, f, a,b, type, g);
    if (R > mid)
        update(rc[g][o], mid + 1, r, f, a,b, type, g);
}
// ll dis[M + N + 1][2];
struct Dist
{
    ll a;
    ll b;
    Dist(){}
    Dist(int _a,int _b):a(_a),b(_b){}
    bool operator > (const Dist obj)const{
        return smaller(this->a,this->b,obj.a,obj.b);
    }
    bool operator < (const Dist obj)const{
        return !smaller(this->a,this->b,obj.a,obj.b);
    }
}dis[M + N + 1];

priority_queue<pair<Dist, int>> q;
int vis[M + N + 1];
void dijkstra(int s, int g)
{
    rep(i, 1, M + N + 1)
    {
        dis[i].a = INF;
        dis[i].b = INF;
        vis[i] = 0;
    }
    dis[s].a = 0;
    dis[s].b = 0;
    q.push(make_pair(Dist(0,0), s));
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
            int a = e[g][i].a;
            int b = e[g][i].b;
            // if (!vis[y] && ((dis[y] == INF) || (dis[y] > dis[x] + z)))
            if (!vis[y] &&  smaller(dis[x].a+a,dis[x].b+b,dis[y].a,dis[y].b))
            {
                dis[y].a = dis[x].a + a;
                dis[y].b = dis[x].b + b;
                q.push(make_pair(dis[y], y));
            }
        }
    }
}
inline int read()
{
    int data = 0, w = 1;
    char ch = 0;
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        data = data * 10 + ch - '0', ch = getchar();
    return data * w;
}
int main()
{
    IOS;
    // freopen("xingji1.in", "r", stdin);
    // cin >> n >> m;
    // clock_t start,end;
    n = read();
    m = read();
    // start = clock();
    ncnt[0] = n;
    ncnt[1] = n;
    tot[1] = 0;
    rt1[1] = rt2[1] = 0;
    buildOut(rt1[0], 1, n, 0);
    buildIn(rt2[0], 1, n, 0);
    buildIn(rt1[1], 1, n, 1);
    buildOut(rt2[1], 1, n, 1);

    int l1, r1, l2, r2, a, b;
    int l;
    rep(i, 0, m)
    {
        // cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        l1 = read();
        r1 = read();
        l2 = read();
        r2 = read();
        a = read();
        b = read();
        // l = cal(a, b);

        L = l1;
        R = r1;
        update(rt2[0], 1, n, ++ncnt[0], 0,0, 1, 0);
        L = l2;
        R = r2;
        update(rt1[1], 1, n, ++ncnt[1], a,b, 1, 1);
        L = l2;
        R = r2;
        update(rt1[0], 1, n, ncnt[0], a,b, 2, 0);
        L = l1;
        R = r1;
        update(rt2[1], 1, n, ncnt[1], 0,0, 2, 1);
    }
    // end = clock();
    // cout<<double(end - start)/CLOCKS_PER_SEC<<'\n';
    dijkstra(1, 0);
    vector<Dist> dist(n + 1);
    rep(i, 2, n + 1)
    {
        dist[i].a = dis[i].a;
        dist[i].b = dis[i].b;
        // cout << dist[i] << ' ';
    }

    dijkstra(1, 1);
    rep(i, 2, n + 1)
    {
        if (dist[i].a == INF ||dist[i].b == INF|| dis[i].a == INF||dis[i].b == INF)
            cout << -1 << ' ';
        else
        {
            cout << (cal(dist[i].a,dist[i].b) + cal(dis[i].a,dis[i].b)) % MOD << ' ';
        }
    }
    // end = clock();
    // cout<<double(end - start)/CLOCKS_PER_SEC<<'\n';
    return 0;
}
