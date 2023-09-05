#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
const LL N=1e3+10;
const LL mod=1e9+7;
LL a[N][N];
LL a2[N][N];
LL dist[N];
bool st[N];
LL dist2[N];
bool st2[N];
LL n,m;
int main()
{
    scanf("%lld%lld",&n,&m);
    memset(a,0x3f,sizeof a);
    for(LL i=1;i<=n;i++)
    a[i][i]=0;
    while(m--)
    {
        LL l1,r1,l2,r2,x1,x2;
        scanf("%lld%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&x1,&x2);
        x1=x1*pow(2,x2);
        for(LL i=l1;i<=r1;i++)
        for(LL j=l2;j<=r2;j++)
        a[i][j]=min(a[i][j],x1);
    }
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(LL i=1;i<=n;i++)
    {
        LL minv=0x3f3f3f3f3f3f3f3f,index=-1;
        for(LL j=1;j<=n;j++)
        {
            if(st[j])
            continue;
            if(dist[j]<=minv)
            {
                minv=dist[j];
                index=j;
            }
        }
        st[index]=true;
        for(LL j=1;j<=n;j++)
        {
            if(st[j])
            continue;
            dist[j]=min(dist[j],dist[index]+a[index][j]);
        }
    }
    //每次找到一个点的最短路
    for(LL i=1;i<=n;i++)
    for(LL j=1;j<=n;j++)
    {
        a2[i][j]=a[j][i];
    }
    memset(dist2,0x3f,sizeof dist2);
    dist2[1]=0;
    for(LL i=1;i<=n;i++)
    {
        LL minv=0x3f3f3f3f3f3f3f3f,index=-1;
        for(LL j=1;j<=n;j++)
        {
            if(st2[j])
            continue;
            if(dist2[j]<=minv)
            {
                minv=dist2[j];
                index=j;
            }
        }
        st2[index]=true;
        for(LL j=1;j<=n;j++)
        {
            if(st2[j])
            continue;
            dist2[j]=min(dist2[j],dist2[index]+a2[index][j]);
        }
    }
    for(LL i=2;i<=n;i++)
    {
        if(dist[i]==0x3f3f3f3f3f3f3f3f||dist2[i]==0x3f3f3f3f3f3f3f3f)
        {
            cout<<-1<<" ";
        }
        else
        cout<<(dist[i]+dist2[i])%mod<<" ";
    }
    cout<<endl;
}
