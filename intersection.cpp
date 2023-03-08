#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    map<int, int> nums1;
    while (1)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        nums1[num]++;
    }
    bool flag = false, k = false;
    while (1)
    {
        cin >> num;
        if (num == -1)
        {
            break;
        }
        if (nums1.find(num) != nums1.end())
        {
            flag = true;
            if (nums1[num] > 0)
            {
                if (!k)
                {
                    printf("%d", num);
                    k=true;
                }
                else
                {
                    printf(" %d", num);
                }
                nums1[num]--;
            }
        }
    }
    if (!flag)
    {
        printf("NULL");
    }
    printf("\n");
    return 0;
}