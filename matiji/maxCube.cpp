#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, r, x, y, num, i, j;
    cin >> n >> r;
    int nums[1001][1001]{0};
    // int(*sum)[1001] = new int[1001][1001];
    int ** sum=new int*[1001];
    for ( i = 0; i < 1001; i++)
    {
        sum[i]=new int[1001];
    }
    
    for (i = 0; i < n; i++)
    {
        cin >> x >> y >> num;
        nums[x][y] += num;
    }
    int ans = -1;
    sum[0][0] = nums[0][0];
    for (i = 0; i < 1001; i++)
    {
        for (j = 0; j < 1001; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
            {
                sum[i][j] = sum[i][j - 1] + nums[i][j];
            }
            else if (j == 0)
            {
                sum[i][j] = sum[i - 1][j] + nums[i][j];
            }
            else
            {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + nums[i][j];
            }
        }
    }
    int tem;
    for (i = r - 1; i < 1001; i++)
    {
        for (j = r - 1; j < 1001; j++)
        {
            if (i == r - 1 && j == r - 1)
            {
                tem = sum[i][j];
            }
            else if (i == r - 1)
            {
                tem = sum[i][j] - sum[i][j - r];
            }
            else if (j == r - 1)
            {
                tem = sum[i][j] - sum[i - r][j];
            }
            else
            {
                tem = sum[i][j] - sum[i - r][j] - sum[i][j - r] + sum[i - r][j - r];
            }
            ans = ans < tem ? tem : ans;
        }
    }

    cout << ans << '\n';
    for(i=0;i<1001;i++){
        delete[] sum[i];
    }
    delete[] sum;
    return 0;
}