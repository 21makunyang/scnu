
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int ans = 0, n, k, minV, xsum;
    int a[n];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int s = k; s < n; ++s)
    {
        for (int r = s; r < n; ++r)
        {
            minV = 2e9;
            for (int i = r - s + 1; i <= r; ++i)
            {
                xsum = 0;
                for (int j = 1; j <= i; ++j)
                {
                    xsum ^= a[j];
                }
                minV = min(minV, xsum);
            }
            ans = max(ans, minV);
        }
    }
    cout << ans;
    return 0;
}
