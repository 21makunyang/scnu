#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, begin, end, t;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, {0}));
    vector<vector<int>> trace(n, vector<int>(n,{0}));
    vector<int> w(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> w[i];
    }
    function<string(int i,int j)> traceBack;
    traceBack = [&](int i,int j)->string{
        if(i==j){
            return "M"+to_string(i+1);
        }
        return "("+traceBack(i,trace[i][j])+traceBack(trace[i][j]+1,j)+")";
    };
    function<void(int i, int j)> update = [&](int i, int j)
    {
        int x1 = i, y1 = i, x2 = i + 1, y2 = j;
        int minC = INT_MAX;
        while (y1 < j)
        {
            // minC = min(minC, dp[x1][y1] + dp[x2][y2] + w[x1] * w[x2] * w[y2+1]);
            if(minC>dp[x1][y1] + dp[x2][y2] + w[x1] * w[x2] * w[y2+1]){
                minC = dp[x1][y1] + dp[x2][y2] + w[x1] * w[x2] * w[y2+1];
                trace[i][j] = y1;
            }
            x2++;
            y1++;
        }
        dp[i][j] = minC;
    };
    int x, y;
    for (int d = 1; d < n; d++)
    {
        x = 0;
        y = d;
        while (y < n)
        {
            update(x, y);
            x++;
            y++;
        }
    }
    cout << dp[0][n - 1]<<' '<<traceBack(0,n-1);

    return 0;
}