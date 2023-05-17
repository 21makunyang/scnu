#include <bits/stdc++.h>
using namespace std;
string A, B;
vector<string> ans;
vector<vector<int>> dp;
void longest(int lenA, int lenB, string temStr)
{
    while (lenA > 0 && lenB > 0 && A[lenA - 1] == B[lenB - 1])
    {
        temStr = A[lenA - 1] + temStr;
        lenA--;
        lenB--;
    }
    if (lenA == 0 || lenB == 0)
    {
        ans.push_back(temStr);
        return;
    }
    if (dp[lenA - 1][lenB] == dp[lenA][lenB - 1])
    {
        longest(lenA - 1, lenB, temStr);
        longest(lenA, lenB - 1, temStr);
    }
    else if (dp[lenA - 1][lenB] > dp[lenA][lenB - 1])
    {
        longest(lenA - 1, lenB, temStr);
    }
    else if (dp[lenA][lenB - 1] > dp[lenA - 1][lenB])
    {
        longest(lenA, lenB - 1, temStr);
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> A >> B;
    int n = A.size(), m = B.size();
    dp.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        dp[i].resize(m + 1);
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < m + 1; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if (dp[n][m] == 0)
    {
        cout << "NO\n";
        return 0;
    }
    longest(n, m, "");
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }

    // cout<<dp[n][m];
    return 0;
}