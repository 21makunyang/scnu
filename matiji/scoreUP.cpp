#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int i,n,p,x,y,k,z;
    cin>>n>>p;
    vector<int> score(n);
    for(i=0;i<n;i++){
        cin>>score[i];
    }
    for(i=0;i<p;i++){
        cin>>x>>y>>z;
        for(k=x-1;k<=y-1;k++){
            score[k]+=z;
        }
    }
    sort(score.begin(),score.end());
    cout<<score[0]<<'\n';
    return 0;
}