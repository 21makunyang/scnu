#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        int ans=nums[0],pre=nums[0];
        for(int i=1;i<n;i++)
        {
            pre=max(nums[i],pre+nums[i]);
            ans=max(pre,ans);
        }
        return ans;
    }
int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<maxSubArray(nums);
    return 0;
}