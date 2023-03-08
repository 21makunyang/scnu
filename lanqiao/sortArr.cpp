#include <bits/stdc++.h>

using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }

    int flag, num, n1, n2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &flag, &num);
        if (flag)
        {
            // sort(nums+num-1,nums+n);
            // n1 = n1 > num ? num : n1;
            n1=num;
        }
        else
        {
            // sort(nums,nums+num,cmp);
            // n2 = n2 < num ? num : n2;
            n2=num;
        }
    }
    sort(nums, nums + n2, cmp);
    sort(nums + n1 - 1, nums + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    delete[] nums;
    return 0;
}
