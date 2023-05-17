#include <bits/stdc++.h>
using namespace std;
int n, m, k;
// vector<pair<int, int>> plan;

int main()
{
    int t, c, q;
    cin >> n >> m >> k;
    vector<int> plan(200001, {0});
    for (int i = 0; i < n; i++)
    {
        cin >> t >> c;
        plan[max(1, t - c - k + 1)]++;
        plan[max(1, t- k + 1)]--;
    }
    for (int i = 1; i < 200001; i++)
    {
        plan[i]+=plan[i-1];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>q;
        cout<<plan[q]<<'\n';
    }
    

    return 0;
}