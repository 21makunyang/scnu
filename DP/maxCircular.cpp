/*给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-circular-subarray
*/
#include <bits/stdc++.h>
using namespace std;
//以当前数组元素为末尾的最大序列和
//不是继承的最优子结构，上一个元素得到最大序列和的组成元素不一定是下一个元素得到最大序列和的组成元素
int maxCircular(vector<int>& nums)
{
    int n=nums.size(),sum=nums[0],temMax=nums[0],temMin=nums[0],ansMax=nums[0],ansMin=nums[0];
    bool flag=0;
    if(n==1) return nums[0];
    if(nums[0]>0)flag=1;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>0) flag=1;
        temMax=max(temMax+nums[i],nums[i]);
        //这里的temMax不能换成dpMax[i-1]，换的话会使1，-2，3，-2的dpMax[2]=4，实际应等于3
        //temMax算的是当前数组元素为末尾的最大序列和
        ansMax=max(ansMax,temMax);
        temMin=min(temMin+nums[i],nums[i]);
        ansMin=min(ansMin,temMin);
        sum+=nums[i];
    }
    if(!flag)return ansMax;//如果和所有元素<0那么sum-ansMin=0，返回错误答案
    return max(ansMax,sum-ansMin);
}
int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    /*nums.push_back(9);
    /*nums.push_back(4);
    nums.push_back(-1);
    
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);*/
    cout<<maxCircular(nums);
    return 0;
}