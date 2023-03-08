#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n = 0, num, row, col, unitElement, numIndex;
    bool has[201], hasUnitElement = true,flag; // 判断行是否含单位元
    vector<vector<int>> nums(201);

    for (int i = 0; i < 201; i++)
    {
        nums.resize(201);
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        
        for (int i = 0; i < n; i++)
        {
            nums[i].clear();
        }
        unitElement = -1;
        cin >> n;
        int *inverse = new int[n];
        // 输入数据
        for (row = 0; row < n; row++)
        {
            for (col = 0; col < n; col++)
            {
                cin >> num;
                nums[row].push_back(num);
            }
        }
        
        bool isUnitElement = false,isGroup = false;
        hasUnitElement = false;
        for (row = 0; row < n; row++)
        {
            isUnitElement = true;
            for (col = 0; col < n; col++)
            {
                if(nums[row][col] != col+1|| nums[row][col]!=nums[col][row]){
                    isUnitElement =false;
                    break;
                }
                
            }
            // 不含单位元则判断下一行
            if(!isUnitElement){
                continue;
            }
            else{
                if(!hasUnitElement){
                    hasUnitElement = true;
                    isGroup = true;
                    unitElement = row+1;
                }else{
                    isGroup = false;
                }
            }
        }
        // 没有单位元，不是群
        if (!isGroup)
        {
            cout << "NO\n";
            goto nextGroup;
        }
        
        //unitElement = nums[uniqueRow[0]][uniqueRow[0]];

        for (int i = 0; i < n; i++)
        {
            inverse[i] = -1;
        }
        // 找每个元素逆元
        for (row = 0; row < n; row++)
        {
            for (col = 0; col < n; col++)
            {
                if (nums[row][col] == nums[col][row] && nums[row][col] == unitElement)
                {
                    inverse[row] = col+1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            // 存在没有逆元的数，不是群
            if (inverse[i] == -1)
            {
                cout << "NO\n";
                goto nextGroup;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (nums[i][nums[j][k] - 1] != nums[nums[i][j] - 1][k])
                    {
                        cout << "NO\n";
                        goto nextGroup;
                    }
                }
            }
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            cout << inverse[i];
            if (i != n - 1)
                cout << " ";
        }
        if (i != t - 1)
            cout << '\n';
    nextGroup:
        delete[] inverse;
        // 下一组
    }
    return 0;
}