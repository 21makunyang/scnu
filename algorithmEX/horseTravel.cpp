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
int n, be1, be2;
vector<vector<int>> table;
// vector<vector<int>> chance;
int cnt = 0;
int getChanceToJump(int a, int b)
{
    int t = 0;
    if (a - 2 > 0)
    {

        t = t + (b - 1 > 0 && table[a - 2][b - 1] == 0 ? 1 : 0) + (b + 1 <= n && table[a - 2][b + 1] == 0 ? 1 : 0);
    }
    if (a - 1 > 0)
    {
        t = t + (b - 2 > 0 && table[a - 1][b - 2] == 0 ? 1 : 0) + (b + 2 <= n && table[a - 1][b + 2] == 0 ? 1 : 0);
    }
    if (a + 2 <= n)
    {
        t = t + (b - 1 > 0 && table[a + 2][b - 1] == 0 ? 1 : 0) + (b + 1 <= n && table[a + 2][b + 1] == 0 ? 1 : 0);
    }
    if (a + 1 <= n)
    {
        t = t + (b - 2 > 0 && table[a + 1][b - 2] == 0 ? 1 : 0) + (b + 2 <= n && table[a + 1][b + 2] == 0 ? 1 : 0);
    }
    return t;
}
struct Node
{
    int x, y, t;
    Node() {}
    Node(int x1, int y1, int t1) : x(x1), y(y1), t(t1) {}
    bool operator<(const Node &obj) const
    {
        return this->t < obj.t;
    }
};
bool found = false;

void traceBack(int a, int b)
{
    vector<Node> que;
    if (a - 2 > 0)
    {
        if (b - 1 > 0 && table[a - 2][b - 1] == 0)
            que.push_back(Node(a - 2, b - 1, getChanceToJump(a - 2, b - 1)));
        if (b + 1 <= n && table[a - 2][b + 1] == 0)
            que.push_back(Node(a - 2, b + 1, getChanceToJump(a - 2, b + 1)));
    }
    if (a - 1 > 0)
    {
        if (b - 2 > 0 && table[a - 1][b - 2] == 0)
            que.push_back(Node(a - 1, b - 2, getChanceToJump(a - 1, b - 2)));
        if (b + 2 <= n && table[a - 1][b + 2] == 0)
            que.push_back(Node(a - 1, b + 2, getChanceToJump(a - 1, b + 2)));
    }
    if (a + 1 <= n)
    {
        if (b - 2 > 0 && table[a + 1][b - 2] == 0)
            que.push_back(Node(a + 1, b - 2, getChanceToJump(a + 1, b - 2)));
        if (b + 2 <= n && table[a + 1][b + 2] == 0)
            que.push_back(Node(a + 1, b + 2, getChanceToJump(a + 1, b + 2)));
    }
    if (a + 2 <= n)
    {
        if (b - 1 > 0 && table[a + 2][b - 1] == 0)
            que.push_back(Node(a + 2, b - 1, getChanceToJump(a + 2, b - 1)));
        if (b + 1 <= n && table[a + 2][b + 1] == 0)
            que.push_back(Node(a + 2, b + 1, getChanceToJump(a + 2, b + 1)));
    }
    if (que.empty())
    {
        if (cnt == n * n)
        {
            if ((a - 2 == be1 && (b - 1 == be2 || b + 1 == be2)) || (a - 1 == be1 && (b - 2 == be2 || b + 2 == be2)) ||
                (a + 1 == be1 && (b - 2 == be2 || b + 2 == be2)) || (a + 2 == be1 && (b - 1 == be2 || b + 1 == be2)))
            {
                found = true;
                rep(i, 1, n + 1)
                {
                    rep(j, 1, n + 1)
                    {
                        cout << table[i][j] << ' ';
                    }
                    cout << '\n';
                }
            }
        }

        return;
    }
    sort(que.begin(), que.end());

    for (auto elem : que)
    {
        cnt++;
        table[elem.x][elem.y] = cnt;
        traceBack(elem.x, elem.y);
        if (found)
            return;
        table[elem.x][elem.y] = 0;
        cnt--;
    }
}
int main()
{
    IOS;
    cin >> n >> be1 >> be2;
    table.resize(n + 1);
    // chance.resize(n + 1);
    rep(i, 0, n + 1)
    {
        table[i].resize(n + 1);
        // chance[i].resize(n + 1);
    }
    table[be1][be2] = 1;
    cnt = 1;
    // rep(i, 1, n + 1)
    // {
    //     rep(j, 1, n + 1)
    //     {
    //         if (i == a && j == b)
    //             continue;
    //         chance[i][j] = getChanceToJump(i, j);
    //     }
    // }
    traceBack(be1, be2);
    return 0;
}