#include <bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
        int i,n=values.size();
        vector<int> values2(values);
        if(n==1) return values[0];
        for(i=0;i<n;i++)
        {
            values2[i]-=i;
        }
        int max=0,ans=values[0];
        for(i=0;i<n-1;i++)
        {
            if(values[max]+max<=values[i]+i) max=i;
            if(ans<values[max]+values2[i+1]+max) ans=values[max]+values2[i+1]+max;
        }
        return ans;
    }
int main()
{
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(6);
    nums.push_back(6);
    nums.push_back(9);
    nums.push_back(4);
    nums.push_back(3);
    /*nums.push_back(1);
    
    nums.push_back(4);*/
    cout<<maxScoreSightseeingPair(nums);
    return 0;
}