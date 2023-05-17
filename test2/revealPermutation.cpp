#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
map<int, bool> dic;
map<int, bool> lostNumMap;
int n = 0;
int k = 0;
int ans = 0;
void revealPermutation(int index)
{
    int i = index;
    while (i < n)
    {
        if (nums[i] != 0)
        {
            i++;
        }
        else
            break;
    }
    if (i == n)
    {
        // check
        int cnt = 0;
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if(nums[j]<nums[k]){
                    cnt++;
                }
            }
        }
        if (cnt==k ){
            ans++;
        }
        return;
    }
    for (map<int, bool>::iterator it = lostNumMap.begin(); it != lostNumMap.end(); it++)
    {
        if (it->second)
        {
            it->second = false;
            nums[i] = it->first;
            revealPermutation(i + 1);
            it->second = true;
            nums[i] = 0;
        }
    }
}

int main()
{
    int num;
    cin >> n >> k;

    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num != 0)
        {
            dic[num] = 1;
            nums[i] = num;
        }
    }
    int lostSize = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dic.find(i) == dic.end())
        {
            lostSize++;
            lostNumMap[i] = true;
        }
    }
    revealPermutation(0);
    cout<<ans<<'\n';
    return 0;
}