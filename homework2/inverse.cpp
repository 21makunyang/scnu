#include <bits/stdc++.h>
using namespace std;

bool inverse(float arr[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        swap(arr[i],arr[len-i-1]);
    }
    return true;
}

bool inverse(list<float>& nums)
{
    list<float>::iterator beg = nums.begin();
    list<float>::iterator end = nums.end();
    while (1)
    {
        if(beg == end)
            break;
        end--;
        if(beg == end)
            break;
        swap(*beg,*end);
        beg++;
    }
    return true;
}
bool deleteMin(list<float> nums)
{
    list<float>::iterator it = nums.begin();
    list<float>::iterator min = nums.begin();
    while(1)
    {
        if(it == nums.begin())
            break;

        if(it == nums.end())
            it = nums.begin();  

        if(*it<*min)
            min = it;
        it++;  
    }
    
    return false;
}
int main()
{
    float arr[] = {1, 2, 3, 4, 5, 6, 7};
    inverse(arr,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';

    // list<float> nums{1, 2, 3, 4, 5, 6, 7};
    // inverse(nums);
    // list<float>::iterator it = nums.begin();
    // for(;it != nums.end();it++)
    // {
    //     cout<<*it<<" ";
    // }
    // cout<<'\n';
    return 0;
}