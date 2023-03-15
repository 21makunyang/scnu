#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,ans=-1,tem=0;
    cin>>n;
    int *values=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>values[i];
    }
    for (int i = 0; i < n; i++)
    {
        tem=values[i];
        for(int j=i+1;j<n;j++){
            tem=tem^values[j];
            ans=ans<tem?tem:ans;
        }
    }
    cout<<ans<<'\n';
    delete[] values;
    return 0;
}