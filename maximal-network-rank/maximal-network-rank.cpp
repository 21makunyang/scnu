#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &x, pair<int, int> &y)
{
    return x.second > y.second;
}

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> cnt(n, {0});
        vector<vector<int>> graph(n, vector<int>(n, {0}));
        for (auto road : roads)
        {
            cnt[road[0]]++;
            cnt[road[1]]++;
            graph[road[0]][road[1]] = 1;
            graph[road[1]][road[0]] = 1;
        }
        int ans = -1, i = 0, tem = 0;
        while (i < n)
        {
            for (int j = i + 1; j < n; j++)
            {

                tem = cnt[i] + cnt[j] - graph[i][j];
                ans = ans < tem ? tem : ans;
            }
            i++;
        }

        return ans;
    }
};
int main()
{
    Solution so;
    int n = 5;
    vector<vector<int>> roads{{2, 3}, {0, 3}, {0, 4}, {4, 1}};
    cout << so.maximalNetworkRank(n, roads);
    return 0;
}