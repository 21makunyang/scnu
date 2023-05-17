#include <bits/stdc++.h>
using namespace std;

int folyd(int n, int m)
{
    // initialize
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> trace(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = INT_MAX;
            trace[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
        trace[i][i] = 0;
    }
    int be, end, dst;
    for (int i = 0; i < m; i++)
    {
        cin >> be >> end >> dst;
        dp[be][end] = dst;
        dp[end][be] = dst;
    }
    // solve
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dp[i][k] ==INT_MAX || dp[k][j]==INT_MAX){
                    continue;
                }
                if (dp[i][j] >= dp[i][k] + dp[k][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    trace[i][j] = k;
                }
            }
        }
    }
    int ans = n, tem;
    vector<int> longest(n, {0});
    function<bool(void)> check;
    check = [&](void) -> bool
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] == INT_MAX)
                {
                    return false;
                }
                if (longest[i] < dp[i][j])
                {
                    longest[i] = dp[i][j];
                }
            }
        }
        return true;
    };
    if (!check())
    {
        return -1;
    }
    tem = longest[0];
    ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (longest[i] < tem)
        {
            ans = i;
            tem = longest[i];
        }
    }
    return ans;
}
int main()
{
    int n, m, begin, end, t;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        cin >> m;
        cout << folyd(n, m) << '\n';
    }
    return 0;
}