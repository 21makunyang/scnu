#include <bits/stdc++.h>
using namespace std;

int move(int *num,int n,int m)
{
    int i,temp[n];
    for(i=0;i<n;i++)
    {
        temp[(i+m)%n]=*(num+i);
    }
    for(i=0;i<n;i++) *(num+i)=temp[i];
    return 1;
}
int main()
{
    int n,i,m;
    printf("请输入n个数：");
    cin>>n;
    printf("请输入将n个数后移多少位：");
    cin>>m;
    int num[n];
    printf("请输入这n个数：");
    for(i=0;i<n;i++)cin>>num[i];
    move(num,n,m);
    printf("结果为：");
    for(i=0;i<n;i++)cout<<num[i]<<' ';
    return 0;
} 
