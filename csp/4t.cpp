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

const int N = 3e5 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[N];
int a[N];
int dep[N], sz[N], hson[N];
multiset<int> mset;
ll ans[N], sum;

void init()
{
    mset.insert(inf), mset.insert(inf);
    mset.insert(-inf), mset.insert(-inf);
}

void dfs0(int u, int fa = -1)
{
    int mx = 0, size = 1;
    for (auto v : g[u])
    {
        if (v != fa)
        {
            dfs0(v, u);
            size += sz[v];
            if (sz[v] > mx)
            {
                hson[u] = v, mx = sz[v];
            }
        }
    }
    sz[u] = size;
}

ll calu(ll x, ll y, ll z)
{
    if (abs(y) == inf)
    {
        return 0;
    }

    if (abs(x) != inf && abs(z) != inf)
    {
        return min((y - z) * (y - z), (y - x) * (y - x));
    }
    else if (abs(x) != inf && abs(z) == inf)
    {
        return (y - x) * (y - x);
    }
    else if (abs(x) == inf && abs(z) != inf)
    {
        return (y - z) * (y - z);
    }
    else
    {
        return 0;
    }
}

void add(int u)
{
    // 加入一个节点，只可能改变值相邻两个节点的聚集方差增量
    auto it = mset.lower_bound(a[u]);
    // 找到第一个不小于a[u]值
    it--, it--;
    ll b[6];
    b[1] = *it, it++;
    b[2] = *it, it++;
    b[3] = a[u];
    b[4] = *it, it++;
    b[5] = *it, it++;

    sum -= calu(b[1], b[2], b[4]);
    sum -= calu(b[2], b[4], b[5]);
    sum += calu(b[1], b[2], b[3]);
    sum += calu(b[2], b[3], b[4]);
    sum += calu(b[3], b[4], b[5]);

    mset.insert(a[u]);
}
void del(int u)
{
}

void addsubtree(int u, int fa = -1)
{
    add(u);
    for (auto v : g[u])
    {
        if (v != fa)
            addsubtree(v, u);
    }
}
void delsubtree(int u, int fa = -1)
{
    del(u);
    for (auto v : g[u])
    {
        if (v != fa)
            delsubtree(v, u);
    }
}

void dfs(int u, int fa = -1, bool keep = -1)
{
    // keep标志信息是否保留
    // 先遍历轻儿子
    for (auto v : g[u])
    {
        if (v != fa && v != hson[u])
        {
            dfs(v, u, 0);
        }
    }
    // 最后遍历重儿子
    if (hson[u])
    {
        dfs(hson[u], u, 1);
    }
    add(u);
    for (auto v : g[u])
    {
        if (v != fa && v != hson[u])
        {
            addsubtree(v, u);
        }
    } // 重儿子的信息没有删除，因此不必再添加
    ans[u] = sum;
    if (!keep)
    {
        // delsubtree(u, fa);
        // clearup
        mset.clear();
        init();
        sum = 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    int v;
    for (int u = 2; u <= n; u++)
    {
        cin >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs0(1);
    init();
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}

int main()
{

    solve();
    return 0;
}