#include <iostream>
using namespace std;
int main(){
    int n,i=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j:a)
    {
        j++;
        cout<<j<<' ';
    }
    return 0;
}