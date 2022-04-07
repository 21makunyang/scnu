#include<iostream>
#include <algorithm>
using namespace std;
int dp[2000][2000];

int minEggThrow(int egg,int high)
{
	int i,j,k=1,mini;//从第k层开始扔 
	for(i=2;i<=egg;i++)
	{
		for(j=2;j<=high;j++)
		{
			if(!dp[i][j]) 
			{	
				k=1;
				mini=1+max(dp[i][j-k],dp[i-1][k-1]);
				for(k;k<=j;k++)
				{
					mini=min(mini,1+max(dp[i][j-k],dp[i-1][k-1]));
				}
				dp[i][j]=mini;
				//cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			}
		}
	}
	return dp[egg][high];
}
int main()
{
	//freopen("test.in","r",stdin);
	int i,n,j,egg,high;
	for(i=0;i<=2000;i++)
	{
		dp[1][i]=i;
		dp[i][1]=1;
	}
	cin>>n;
	for(i=0;i<n;i++) 
	{
		cin>>egg>>high;
		cout<<minEggThrow(egg,high)<<'\n';
	}
	return 0;
}
