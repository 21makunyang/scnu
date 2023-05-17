#include <bits/stdc++.h>
using namespace std;

class Locate
{
public:
    int x;
    int y;
    bool operator<(const Locate &l) const
    {
        if (this->x == l.x)
        {
            return this->y < l.y;
        }
        return this->x < l.x;
    }
    Locate() {}
    Locate(int x, int y) : x(x), y(y) {}
};
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, L, S, x, y;
    cin >> n >> L >> S;
    vector<vector<int>> treasure(S + 1, vector<int>(S + 1, {0}));
    map<Locate, bool> land;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        land[Locate(x, y)] = 1;
    }
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j < S + 1; j++)
        {
            cin >> treasure[i][j];
        }
    }
    int match = true;
    int ans = 0;

    for (auto locate : land)
    {
        if (locate.first.x >= L - S + 1 || locate.first.y >= L - S + 1)
        {
            continue;
        }
        match = true;
        for (int i = 0; i < S + 1; i++)
        {
            for (int j = 0; j < S + 1; j++)
            {
                if ((land.find(Locate(locate.first.x+i, locate.first.y+j)) != land.end() && treasure[i][j] == 0) || (land.find(Locate(locate.first.x+i,locate.first.y+ j)) == land.end() && treasure[i][j] == 1))
                {
                    match = false;
                    break;
                }
            }
        }
        if (match)
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}