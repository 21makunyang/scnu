#include <bits/stdc++.h>                          //POJ不支持
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
#define lson id * 2
#define rson id * 2 + 1
typedef long long ll;
using namespace std;

struct Node
{
    ll sum;
    int l, r;
};
int main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    rep(i, 1, n+1)
    {
        cin >> a[i];
    }
    ll t[n << 2];
    ll mark[n << 2];
    for (int i = 0; i < n<<2; i++)
    {
        t[i] = 0;
        mark[i]=0;
    }
    
    function<void(int)> push_up = [&](int id)
    {
        t[id] = t[lson] + t[rson];
    };
    function<void(int, int, int)> build;
    build = [&](int id, int l, int r)
    {
        if (l == r)
        {
            t[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        push_up(id);
    };
    function<void(int, int)> push_down = [&](int id, int len)
    {
        // 标记向下传递
        mark[lson] += mark[id];
        mark[rson] += mark[id];
        // 往下更新一层
        t[lson] += mark[id] * (len - len / 2);
        t[rson] += mark[id] * (len / 2);
        // 清除标记
        mark[id] = 0;
    };
    function<void(int, int, ll, int, int, int)> update;
    update = [&](int l, int r, ll data, int id, int cl, int cr)
    {
        // l  需要更新的左边界
        // r  需要更新的右边界
        // data 每个元素需要加的值
        // id 当前结点下标
        // cl 当前结点管辖的左边界
        // cr 当前结点管辖的右边界
        if (cl > r || cr < l)
            return; // 区间无交集
        if (cl >= l && cr <= r)
        { // 当前节点对应的区间包含在目标区间中
            t[id] += (cr - cl + 1) * data;
            if (cl < cr)
            {
                mark[id] += data;
            }
            return;
        }
        // 与目标区间有交集，但不包含于其中
        int mid = (cl + cr) >> 1;
        push_down(id, cr - cl + 1);
        update(l, r, data, lson, cl, mid);
        update(l, r, data, rson, mid + 1, cr);
        push_up(id);
    };
    function<ll(int, int, int, int, int)> query;
    query = [&](int l, int r, int id, int cl, int cr) -> ll
    {
        // l  需要查询的左边界
        // r  需要查询的右边界
        // id 当前结点下标
        // cl 当前结点管辖的左边界
        // cr 当前结点管辖的右边界
        if (cl > r || cr < l)
            return 0;
        else if (cl >= l && cr <= r)
            return t[id];
        int mid = (cr+cl)>>1;
        push_down(id,cr-cl+1);
        return query(l,r,lson,cl,mid)+query(l,r,rson,mid+1,cr);
    };
    build(1, 1, n);
    int oper,l,r,k;
    rep(i, 0, m)
    {
        cin>>oper>>l>>r;
        if(oper == 1){
            cin>>k;
            update(l,r,k,1,1,n);
        }else if (oper==2)
        {
            cout<<query(l,r,1,1,n)<<'\n';
        }
        
    }
    return 0;
}