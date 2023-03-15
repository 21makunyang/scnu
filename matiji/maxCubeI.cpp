#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    int n,r,x,y,num,sum;
    cin>>n>>r;
    int nums[1001][1001]{0};
    for (int i = 0; i < n; i++)
    {
        cin>>x>>y>>num;
        nums[x][y]+=num;
    }
    int ans=-1;
    for(int i=0;i<=1001-r;i++){
        for(int j=0;j<1001-r;j++){
            sum=0;
            for(x=i;x<i+r;x++){
                for(y=j;y<j+r;y++){
                    sum+=nums[x][y];
                }
            }
            ans=ans<sum?sum:ans;
        }
    }
    cout<<ans<<'\n';
    return 0;
}