#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    int n = cnt1 + cnt2;
    int numx = 0, numy = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt1 > numx && cnt2 > numy&&i % x != 0 && i % y != 0)
        {
            cnt1-numx > cnt2-numy ? numx++ : numy++;
            continue;
        }
        if (cnt1 > numx&&i % x != 0)
        {
            numx++;
        }
        else if (cnt2 > numy&&i % y != 0)
        {
            numy++;
        }
    }
    if (numx == cnt1 && numy == cnt2)
    {
        cout << n << '\n';
        return 0;
    }
    int begin = n+1;
    int ans = 0;
    while (1)
    {
        begin = n+1;
        n += cnt1 - numx + cnt2 - numy;
        for (int i = begin; i <= n; i++)
        {
            if (cnt1 > numx && cnt2 > numy && i % x != 0 && i % y != 0)
            {
                cnt1-numx > cnt2-numy ? numx++ : numy++;
                continue;
            }
            if (cnt1 > numx && i % x != 0)
            {
                numx++;
            }
            else if (cnt2 > numy && i % y != 0)
            {
                numy++;
            }
            if (cnt1 == numx && cnt2 == numy)
            {
                ans = i;
                goto get;
            }
        }
        
    }
get:
    cout << ans << '\n';
    return 0;
}