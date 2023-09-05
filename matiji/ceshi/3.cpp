#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int m,n,ans = 0,N;
    m = 1;
    n = 1;
    cin>>N;
    if(N>=1){
        cout<<1<<' ';
    }
    if(N>=2){
        cout<<1<<' ';
    }
    ans = m+n;
    for(int i = 2;i<N;i++){
        int t  = ans;
        ans = m+n;
        n = m;
        m = ans;
        cout<<ans<<' ';
    }
    return 0;
}