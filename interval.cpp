#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int j, maxNum = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            maxNum = max(maxNum, intervals[i][1]);
        }
        bool *axis=new bool[maxNum+2]{0};
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++)
        {
            for(j=intervals[i][0];j<=intervals[i][1];j++){
                axis[j]=true;
            }
        }
        int begin=axis[0]?0:-1,end;
    
        for(int i=0;i<=maxNum;i++){
            if(axis[i]==0&&axis[i+1]==1){
                begin=i+1;
            }
            else if(axis[i]==1&&axis[i+1]==0){
                end=i;
                ans.push_back(vector<int>{begin,end});
            }
        }
        delete[] axis;
        return ans;
    }
};
