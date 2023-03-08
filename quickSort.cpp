#include <bits/stdc++.h>
using namespace std;
int quickSort(int a[],int len,int left,int right)
{
    if(left<right)
    {
        int i=left+1,j=right;
        int pivot=a[left];
        while(i<j)
        {
            while(a[i]<pivot) i++;
            while(a[j]>pivot) j--;
            //若两边找到的相等则退出循环，防止死循环
            if(i<len&&j>=0&&a[i]==a[j])break;
            else if(i<j) swap(a[i],a[j]); //若j所对应的数（<=pivot的数）在i所对应的数（>=pivot的数）的右边，则交换
        }
        //j必定大于等于0，每次调用都是有效处理，若用i则可能因为i越界无法进行交换
        if(a[left]>a[j]) swap(a[left],a[j]);
        //if(i<len)swap(a[left],a[i]);
        quickSort(a,len,left,j-1);
        quickSort(a,len,j+1,right);
    }
    return 1;
}
int main()
{
    int n = 10;
    cin>>n;
    // int b[n];
    // srand(time(0));
    // for(int i=0;i<n;i++) b[i]=rand()%100;
    // for(int i=0;i<n;i++) cout<<b[i]<<' ';
    // cout<<'\n';
    int b[] = {7, 22, 36, 89, 99, 53, 15, 55, 61, 59};
    //int b[] = {99, 91, 76, 67, 36, 86, 28, 85, 88, 31 };
    quickSort(b,n,0,n-1);
    for(int i=0;i<n;i++) cout<<b[i]<<' ';
    return 0;
}