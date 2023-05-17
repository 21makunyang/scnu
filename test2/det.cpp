#include <bits/stdc++.h>
using namespace std;

int det(vector<vector<int>>& matrix,int n){
    if(n==1){
        return matrix[0][0];
    }
    vector<vector<int>> cofactors(n-1,vector<int>(n-1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        for (int k = 0; k < n-1; k++)
        {
            if(k<i){
                cofactors[j][k] = matrix[j+1][k];
            }else{
                cofactors[j][k] = matrix[j+1][k+1];
            }
        }
        ans+=pow(-1,i)*matrix[0][i]*det(cofactors,n-1);
    }
    return ans;
}

int main()
{
    int n, k, num;
    cin>>n;
    vector<vector<int> > matrix(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    
    cout<<det(matrix,n);

    return 0;
}