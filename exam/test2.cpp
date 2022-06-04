// 描述

// 从给定的无序、不重复的数组A中，取出2个数，使其相加和为M。

// 输出该数组内所有满足上述条件的解的个数。


// 输入
// 第一行两个数 N 和 M，N 为数组长度，M 为相加之和。

// 第二行为实际的数组元素。


// 输出
// 解的个数



#include <bits/stdc++.h>
using namespace std;
#include <vector>

class A{

};
int main()
{
    // int N,M,i,j,count=0;
    // cin>>N>>M;
    // int nums[N];
    int* a = new int[10];
    int*last = a +10;
    for(int i= 0;i<10;i++ )
    {
        cin>>a[i];
    }
    sort(a,last);
    for(int* i= a;i!=last;i++ )
    {
        cout<<*i<<'\n';
    }
    
    // for(i=0;i<N;i++) cin>>nums[i];
    // for(i=0;i<N-1;i++)
    // {
    //     for(j=i+1;j<N;j++)
    //     {
    //         if(nums[i] + nums[j] == M)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // cout<<count<<'\n';
    return 0;
}