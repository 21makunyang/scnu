#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int colSize = colSum.size();
        int rowSize = rowSum.size();
        vector<vector<int>> ans(rowSize, vector<int>(colSize));
        int col,row,dec;
        for(row=0;row<rowSize;row++){
            if(rowSum[row]==0) continue;
            for(col=0;col<colSize;col++){
                if(colSum[col]==0)continue;
                dec=min(rowSum[row],colSum[col]);
                ans[row][col]=dec;
                rowSum[row]-=dec;
                colSum[col]-=dec;
            }
        }

        return ans;
    }
};
int main()
{
    vector<int> rowSum{3, 8};
    vector<int> colSum{4, 7};
    Solution so;
    vector<vector<int>> ans = so.restoreMatrix(rowSum, colSum);
    for (int i = 0; i < rowSum.size(); i++)
    {
        for (int j = 0; j < colSum.size(); j++)
        {
            cout << ans[i][j]<< '\n';
        }
    }
}