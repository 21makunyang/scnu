#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
const int M = 4e6+7;
struct edge
{
	int y,v,next;
}e[2*M];
int link[M],t=0;
int lson[M],rson[M],tot,rotin,rotout;
int n,m;
void add(int x,int y,int v)
{
	t++;
	e[t].y=y;
	e[t].v=v;
	e[t].next=link[x];
	link[x]=t;
}
void buildIn(int &k,int l,int r)
{
	if(l==r)
	{
		k=l;
		return;
	}	
	k=++tot;
	int mid=(l+r)>>1;
	buildIn(lson[k],l,mid);
	buildIn(rson[k],mid+1,r);
	add(k,lson[k],0);
	add(k,rson[k],0);
}
void buildOut(int &k,int l,int r)
{
	if(l==r)
	{
		k=l;
		return;
	} 	
	k=++tot;
	int mid=(l+r)>>1;
	buildOut(lson[k],l,mid);
	buildOut(rson[k],mid+1,r);
	add(lson[k],k,0);
	add(rson[k],k,0);
} 
void Addout(int k,int l,int r,int L,int R,int pos)
{
	if(L<=l&&r<=R)
	{
		add(k,pos,0);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) Addout(lson[k],l,mid,L,R,pos);
	if(R>mid) Addout(rson[k],mid+1,r,L,R,pos);
}
void Addin(int k,int l,int r,int L,int R,int pos)
{
	if(L<=l&&r<=R)
	{
		add(pos,k,0);
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid) Addin(lson[k],l,mid,L,R,pos);
	if(R>mid) Addin(rson[k],mid+1,r,L,R,pos);
}
void Insert(int a,int b,int c,int d)
{
	int p=++tot;
	Addout(rotout,1,n,a,b,p);
	int q=++tot;
	Addin(rotin,1,n,c,d,q);
	add(p,q,1);
}
inline int read()
{
	int X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
int st;
struct node
{
	int x;
	long long d;
};
bool operator < (const node &x,const node &y)
{
	return x.d>y.d;
}
node turn(int x,long long d)
{
	node T;
	T.x=x;
	T.d=d;
	return T;
}
priority_queue<node> q;
long long dis[M],vis[M];
void Dij()
{
	memset(dis,120,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push(turn(st,0));
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int x=tmp.x;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=link[x];i;i=e[i].next)
		{
			int y=e[i].y;
			if(dis[y]>dis[x]+e[i].v)
			{
				dis[y]=dis[x]+e[i].v;
				q.push(turn(y,dis[y]));
			}
		}
	}
}
int main()
{
	n=read();
	m=read();
	st=read();
	tot=n;
	buildIn(rotin,1,n);
	buildOut(rotout,1,n);
	while(m--)
	{
		int a,b,c,d;
		a=read();
		b=read();
		c=read();
		d=read();
		Insert(a,b,c,d);
		Insert(c,d,a,b);
	}
	Dij();
	for(int i=1;i<=n;i++)
	printf("%lld\n",dis[i]);
	return 0;
 } 
