#include <bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        else if(nums.size()==2)
        {
            if(nums[0]==nums[1]) return nums[0]*2;
            else
            {
                if(nums[0]+1==nums[1]||nums[0]-1==nums[1])return nums[0]>nums[1]?nums[0]:nums[1];
                else return nums[0]+nums[1];
            }
        }
        int sumN[10001]={0},n=0,i;
        n=nums.size();
        int dp[10001]={0};
        for(i=0;i<n;i++)sumN[nums[i]]++;
        dp[1]=sumN[1];
        for(i=2;i<=10000;i++) dp[i]=max(dp[i-1],dp[i-2]+sumN[i]*i);
        return dp[10000];
    }
int main()
{
    int ans;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    ans=deleteAndEarn(nums);
    cout<<ans;
    return 0;
}