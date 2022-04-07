#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
        //if(nums.size()==1) return 1;
        //if(nums[0]==0)return 0;
        int n=nums.size(),max=-1,j=nums[0],tem,maxIndex=0,i=0;
        while(1)
        {
            if(j>=n-1) return 1;
            if(nums[i]==0) return 0;
            max=-1;
            for(tem=i+1;tem<=j;tem++)//search max number
            {
                if(nums[tem]+tem>=max+maxIndex)
                {
                    max=nums[tem];
                    maxIndex=tem;
                } 
            }
            i=maxIndex;
            j=maxIndex+max;
        }
    }
int main()
{
    int ans;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    ans=canJump(nums);
    cout<<ans;
    return 0;
}