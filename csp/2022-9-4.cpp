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
#define lson index * 2
#define rson index * 2 + 1
#define mid (lOfnode + rOfnode) / 2
vector<int> t, lazy;
ll n, m, q;
inline void pushDown(ll index)
{
    lazy[lson] = lazy[index];
    lazy[rson] = lazy[index];
    lazy[index] = -1; //-1 表示左右孩子中有人投票
}
void update(ll index, int l, int r, int lOfnode, int rOfnode, int val)
{
    if (r < lOfnode || rOfnode < l)
    {
        return;
    }
    if (l <= lOfnode && rOfnode <= r)
    {

        lazy[index] = val;
        return;
    }
    if (lazy[index] != -1)
        pushDown(index);
    int mod = mid;
    update(lson, l, r, lOfnode, mid, val);
    update(rson, l, r, mid + 1, rOfnode, val);
}

int query(ll index, int lOfnode, int rOfnode, int w)
{
    if (lOfnode == rOfnode)
    {
        if (lazy[index] == w)
            return 1;
        return 0;
    }
    if (lazy[index] == w)
    {
        return rOfnode - lOfnode + 1;
    }
    if (lazy[index] == -1)
    {
        return query(lson, lOfnode, mid, w) + query(rson, mid + 1, rOfnode, w);
    }
    return 0;
}
void change(ll index, int lOfnode, int rOfnode, int x, int y)
{
    if (lazy[index] == x)
    {
        lazy[index] = y;
        return;
    }
    if (lOfnode == rOfnode)
        return;
    if (lazy[index] == -1)
    {
        change(lson, lOfnode, mid, x, y);
        change(rson, mid + 1, rOfnode, x, y);
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
vector<pair<int, int>> toChange;
void getArea(ll index, int lOfnode, int rOfnode, int val)
{
    if (lazy[index] == val)
    {
        toChange.pb(mp(lOfnode, rOfnode));
        return;
    }
    if (lOfnode == rOfnode)
        return;
    if (lazy[index] == -1)
    {
        getArea(lson, lOfnode, mid, val);
        getArea(rson, mid + 1, rOfnode, val);
    }
}
void getArea(int val)
{
    toChange.clear();
    getArea(1, 1, n, val);
}
vector<int> score;
ll count()
{
    ll sum = 0;
    rep(i, 1, m + 1)
    {
        score[i] = query(1, 1, n, i);
        sum += score[i];
    }
    return sum;
}
int victory()
{
    count();
    int max = 0, maxIdx = 0;
    rep(i, 1, m + 1)
    {
        if (max < score[i])
        {
            max = score[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

int main()
{
    IOS;
    n = read(), m = read(), q = read();
    t.resize(n << 2);
    lazy.resize(n << 2);
    score.resize(m + 1);
    int op, l, r, x, w, y;
    rep(i, 0, q)
    {
        op = read();
        if (op == 1)
        {
            l = read(), r = read(), x = read();
            update(1, l, r, 1, n, x);
        }
        else if (op == 2)
        {
            x = read(), w = read();
            change(1, 1, n, x, w);
        }
        else if (op == 3)
        {
            x = read(), y = read();
            getArea(x);
            change(1, 1, n, y, x);
            for (auto p : toChange)
            {
                update(1, p.first, p.second, 1, n, y);
            }
        }
        else if (op == 4)
        {
            w = read();
            // if(w==0){
            //     cout<<n-count()<<'\n';
            //     continue;
            // }
            cout << query(1, 1, n, w) << '\n';
        }
        else
        {
            cout << victory() << '\n';
        }
    }

    return 0;
}