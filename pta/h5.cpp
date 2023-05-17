#include <bits/stdc++.h>
using namespace std;
bool found = false;
inline bool equal(vector<int> &originNums, vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (originNums[i] != nums[i])
        {
            return false;
        }
    }
    return true;
}

void insertNext(vector<int> &originNums, vector<int> &target)
{
    bool out = false;
    vector<int> nums(originNums);
    for (int index = 0; index < nums.size(); index++)
    {
        if (equal(target, nums))
        {
            found = true;
            out = true;
        }
        int i = index + 1;
        while (i - 1 >= 0 && nums[i - 1] > nums[index + 1])
        {
            i--;
        }
        int tem = nums[index + 1];
        for (int j = index + 1; j > i; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[i] = tem;
        if (out)
        {
            cout << "Insertion Sort" << '\n';
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i];
                if (i != nums.size() - 1)
                {
                    cout << ' ';
                }
            }
            cout << '\n';
            break;
        }
    }

    return;
}

void shifDown(vector<int> &nums, int begin, int len)
{
    int i = begin, max = -1, tem = 0;
    while (i < len)
    {
        max = nums[i];
        tem = i;
        if (2 * i + 1 < len && nums[2 * i + 1] > max)
        {
            max = nums[2 * i + 1];
            tem = 2 * i + 1;
        }
        if (2 * i + 2 < len && nums[2 * i + 2] > max)
        {
            max = nums[2 * i + 1];
            tem = 2 * i + 2;
        }
        if (max == nums[i])
        {
            break;
        }
        swap(nums[i], nums[tem]);
        i = tem;
    }
    return;
}
void build(vector<int> &nums, int begin)
{
    if (begin < 0)
    {
        return;
    }
    // no child
    if (begin * 2 + 1 >= nums.size())
    {
        build(nums, begin - 1);
        return;
    }
    if (begin * 2 + 2 >= nums.size())
    {
        if (nums[begin] < nums[begin * 2 + 1])
        {
            swap(nums[begin], nums[begin * 2 + 1]);
            shifDown(nums, begin * 2 + 1, nums.size());
        }
        build(nums, begin - 1);
        return;
    }
    int max = nums[begin], index = begin;
    if (max < nums[begin * 2 + 1])
    {
        max = nums[begin * 2 + 1];
        index = begin * 2 + 1;
    }
    if (max < nums[begin * 2 + 2])
    {
        max = nums[begin * 2 + 2];
        index = begin * 2 + 2;
    }
    swap(nums[index], nums[begin]);
    shifDown(nums, index, nums.size());
    build(nums, begin - 1);
    return;
}
void heapNext(vector<int> &originNums, vector<int> &target)
{
    bool out = false;
    vector<int> nums(originNums);
    build(nums, nums.size());
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (equal(target, nums))
        {
            found = true;
            out = true;
        }
        swap(nums[i], nums[0]);
        shifDown(nums, 0, i);
        if (out)
        {
            cout << "Heap Sort" << '\n';
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i];
                if (i != nums.size() - 1)
                {
                    cout << ' ';
                }
            }
            cout << '\n';
            break;
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> target(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> target[i];
    }
    insertNext(nums, target);
    if (!found)
    {
        heapNext(nums, target);
    }
    return 0;
}