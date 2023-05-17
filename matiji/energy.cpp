#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,b,l,r,need;
    cin>>n>>b;
    vector<int> road(n+1,{0});
    for (int i = 0; i < b; i++)
    {
        cin>>l>>r>>need;
        for (int j = l; j <= r; j++)
        {
            road[j]++;
        }
        
    }
    
    return 0;
}