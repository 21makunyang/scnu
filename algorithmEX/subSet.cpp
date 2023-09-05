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
int n, y, t;
int cnt = 0;
vector<int> nums;
void traceBack(int index, vector<int> combine, int sum)
{
    if (sum > y)
    {
        return;
    }
    if (sum == y)
    {
        cnt++;
        if (cnt == t)
        {
            cout<<combine[0];
            rep(i,1,combine.size())
            {
                cout << ' ' << combine[i];
            }
            // cout << '\n';
        }
        return;
    }
    if (index == n || cnt>t)
    {
        return;
    }
    rep(i, index, n)
    {
        combine.push_back(nums[i]);
        traceBack(i + 1, combine, sum+nums[i]);
        combine.pop_back();
    }
}
int main()
{
    IOS;
    cin >> n >> y;
    nums.resize(n);
    rep(i, 0, n)
    {
        cin >> nums[i];
    }
    cin >> t;
    sort(nums.begin(), nums.end());
    traceBack(0, {}, 0);
    if (cnt < t)
    {
        cout << "No Solution!\n";
    }
    return 0;
}