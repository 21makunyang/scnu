#include <bits/stdc++.h>
using namespace std;

struct tmp1 // 运算符重载<
{
    int begin;
    int end;
    int cost;
    tmp1(){};
    tmp1(int a, int b, int c) : begin(a), end(b), cost(c) {}
    bool operator<(const tmp1 &a) const
    {
        return cost > a.cost;
    }
};

int main()
{
    int n, m, begin, end, money, ans = 0;
    tmp1 newEdge;
    cin >> n >> m;
    vector<vector<int>> cost(n, vector<int>(n, {0}));
    vector<bool> chose(n, {0});
    for (int i = 0; i < m; i++)
    {
        cin >> begin >> end >> money;
        cost[begin - 1][end - 1] = money;
        cost[end - 1][begin - 1] = money;
    }
    priority_queue<tmp1> pqEdge;
    for (int i = 1; i < n; i++)
    {
        if (cost[0][i] > 0)
        {
            pqEdge.push(tmp1(0, i, cost[0][i]));
        }
    }
    chose[0] = true;
    while (!pqEdge.empty())
    {
        //避免重复选边
        while (!pqEdge.empty() && chose[pqEdge.top().end]){
            pqEdge.pop();
        }
        if(pqEdge.empty()){
            break;
        }
        // 选最小边
        newEdge = pqEdge.top();
        ans += newEdge.cost;
        chose[newEdge.end] = true;
        pqEdge.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == newEdge.end || chose[i] ||cost[newEdge.end][i]==0)
            {
                continue;
            }
            // 加入新边
            pqEdge.push(tmp1(newEdge.end, i, cost[newEdge.end][i]));
        }
    }
    // 是否到达所有城市
    for (int i = 0; i < n; i++)
    {
        if (!chose[i])
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
