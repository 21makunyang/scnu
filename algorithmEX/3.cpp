#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
int a[100001];
int MOD = 1e9 + 7;
int ans = 0;
vector<int> nums;

int main()
{
    int k, n;
    cin >> n >> k;
    nums.resize(n);
    rep(i, 0, n)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int i = 0;
    for (; i < n; i++)
    {

        while (i < n && nums[i] == nums[i + 1])
            i++;
        if(nums[i]>k) break;
        int j = i + 1;
        for (; j < n; j++)
        {
            while (j < n && nums[j] == nums[j + 1])
                j++;

            if (nums[j] + nums[i] > k || j >= n || nums[i] == nums[j])
                break;
            ans=(ans+1)%MOD;

        }
    }
    cout << ans << '\n';
    return 0;
}