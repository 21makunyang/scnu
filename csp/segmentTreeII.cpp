#include <bits/stdc++.h>
#define int long long
#define inf 200000000000007
using namespace std;
const int maxl=100005,maxg=20;

int read(){
	int s=0,w=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-')  w=-w;ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return s*w;
}
int n,m,s,blo,opt,u,l,r,w,cnt=0;
int head[8*maxl],itree[4*maxl],otree[4*maxl],pos[maxl];
int dis[8*maxl],vis[8*maxl];

struct edge{int nxt,to,dis;}e[4*maxg*maxl];//边数可能较多
struct node{
	int dis,pos;
	bool operator < (const node &x) const{return x.dis<dis;}
};

void add_edge(int u,int v,int w){
	cnt++;
	e[cnt].to=v,e[cnt].dis=w,e[cnt].nxt=head[u];
	head[u]=cnt;
}

void build_itree(int l,int r,int rt){
	if (l==r){
		pos[l]=rt;
		add_edge(rt+blo,rt,0),add_edge(rt,rt+blo,0);
		return;
	}
	int mid=(l+r)>>1;
	add_edge(rt,2*rt,0),build_itree(l,mid,2*rt);
	add_edge(rt,2*rt+1,0),build_itree(mid+1,r,2*rt+1);
}

void build_otree(int l,int r,int rt){
	if (rt!=1)  add_edge(blo+rt,blo+(rt/2),0); 
	if (l==r)  return;
	
	int mid=(l+r)>>1;
	build_otree(l,mid,2*rt);
	build_otree(mid+1,r,2*rt+1);
}

void tree_edge(int nl,int nr,int l,int r,int rt,int link_pos,int ww,int k){
	if (nl<=l&&r<=nr){
		if (k==0)  add_edge(link_pos+blo,rt,ww);
		else add_edge(rt+blo,link_pos,ww);
		return;
	}
	int mid=(l+r)>>1;
	if (nl<=mid)  tree_edge(nl,nr,l,mid,2*rt,link_pos,ww,k);
	if (nr>mid)  tree_edge(nl,nr,mid+1,r,2*rt+1,link_pos,ww,k);
}

std::priority_queue<node> q;
void dijkstra(){
	q.push((node){0,s});
	dis[s]=0;
	while (!q.empty()){
		int now=q.top().pos;
		q.pop();
		if (vis[now])  continue;
		vis[now]=1;
		
		for (int i=head[now];i;i=e[i].nxt){
			int y=e[i].to;
			if (dis[y]>dis[now]+e[i].dis){
				dis[y]=dis[now]+e[i].dis;
				if (!vis[y])  q.push((node){dis[y],y});
			}
		}
	}
}

signed main(){
	n=read(),m=read(),s=read();blo=4*n;
	build_itree(1,n,1);
	build_otree(1,n,1);//给树中的每个节点一个统一的编号
	for (int i=1;i<=m;i++){
		opt=read(),u=read();
		if (opt==1){
			l=read(),w=read();
			tree_edge(l,l,1,n,1,pos[u],w,0);
		}
		else if (opt==2){
			l=read(),r=read(),w=read();
			tree_edge(l,r,1,n,1,pos[u],w,0);
		}
		else if (opt==3){
			l=read(),r=read(),w=read();
			tree_edge(l,r,1,n,1,pos[u],w,1);
		}
	}
	s=blo+pos[s];
	for (int i=1;i<=8*n;i++)  dis[i]=inf;
	
	dijkstra();
	for (int i=1;i<=n;i++){
		if (dis[pos[i]]>=inf)  dis[pos[i]]=-1;
	}
	for (int i=1;i<=n;i++)  printf("%lld ",dis[pos[i]]);
	return 0;
}
