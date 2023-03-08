#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int ans=INT_MAX,len=nums.size(),cnt;
        for (int offset=0;offset<=1;offset++){
            cnt=0;
            for (int i = offset; i < len; i+=2)
            {
                cnt+=max({i>0?nums[i]-nums[i-1]+1:0,
                        i+1<len?nums[i]-nums[i+1]+1:0,0});
            }
            ans=min(cnt,ans);
        }
        return ans;
    }
};
int main()
{
    vector<int> nums{2, 2, 2, 2, 1};
    Solution so;
    cout << so.movesToMakeZigzag(nums);
    return 0;
}