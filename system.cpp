#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, index;
    int num;
    cin >> n;
    string oper;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> oper;
        if (oper[0] == '+')
        {
            cin >> num;
            nums.push_back(num);
        }
        else
        {
            sort(nums.begin(), nums.end());
            if (nums.size() % 2 == 0)
            {
                if (nums[nums.size() / 2 - 1] % 2 == nums[nums.size() / 2]%2)
                {
                    printf("%d\n", nums[nums.size() / 2 - 1] / 2.0 + nums[nums.size() / 2] / 2.0);
                }
                else
                {
                    printf("%.1f\n", nums[nums.size() / 2 - 1] / 2.0 + nums[nums.size() / 2] / 2.0);
                }
            }
            else
            {
                printf("%d\n", nums[nums.size() / 2]);
            }
        }
    }

    return 0;
}