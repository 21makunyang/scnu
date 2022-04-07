#include <bits/stdc++.h>
using namespace std;
int quickSort(int a[],int left,int right)
{
    if(left<right)
    {
        int i=left+1,j=right;
        int pivot=a[left];
        while(i<j)
        {
            while(a[i]<pivot) i++;
            while(a[j]>pivot) j--;
            if(a[i]==a[j])break;
            else if(i<j) swap(a[i],a[j]);
        }
        if(a[left]>a[j]) swap(a[left],a[j]);
        quickSort(a,left,j-1);
        quickSort(a,j+1,right);
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    int b[n];
    srand(time(0));
    for(int i=0;i<n;i++) b[i]=rand()%100;
    for(int i=0;i<n;i++) cout<<b[i]<<' ';
    cout<<'\n';
    quickSort(b,0,n-1);
    for(int i=0;i<n;i++) cout<<b[i]<<' ';
    return 0;
}