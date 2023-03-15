#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, x, y, m, x1, x2, y1, y2;
    cin >> n >> m;
    vector<vector<int>> floor(n, vector<int>(n, {0}));
    for (i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (x = x1 - 1; x <= x2 - 1; x++)
        {
            for (y = y1 - 1; y <= y2 - 1; y++)
            {
                floor[x][y]++;
            }
        }
    }
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
        {
            cout << floor[x][y] << ' ';
        }
        cout << '\n';
    }
}