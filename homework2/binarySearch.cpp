#include <bits/stdc++.h>
using namespace std;
int locate(float arr[],int left,int right,float x)
{
    if(left>=right)
        return right;

    int mid = left/2 + right/2;
    return (x <= arr[mid])?locate(arr,left,mid,x): locate(arr,mid+1,right,x);
}
bool insert(float arr[],int left,int right,float x){
    int loc = locate(arr,left,right,x);
    for(int i=right;i>loc;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[loc] =x;
    return true;
}
//平均时间复杂度为O(n)+O(lgn)=O(n)
int main()
{
    float arr[] ={1.2, 3.0, 6.1, 10, 12};
    cout<<locate(arr,0,5,0)<<'\n'; 
    insert(arr,0,5,0);
    //cout<<insert(arr,0,5,13)<<'\n';
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    return 0;
}