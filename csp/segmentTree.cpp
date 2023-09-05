#include<bits/stdc++.h>
#define N 100010
#define M 300010
#define LOG 20
typedef int mainint;
#define int long long
using namespace std;
int head[M],lc[M*LOG],rc[M*LOG],tot,ncnt;
int n,m,s,rt1,rt2;
struct Edge{
    int nxt,to,val;
    #define nxt(x) e[x].nxt
    #define to(x) e[x].to
    #define val(x) e[x].val
}e[N*LOG];
inline void addedge(int f,int t,int val){
    nxt(++tot)=head[f];to(tot)=t;val(tot)=val;head[f]=tot;
}
void buildOut(int &o,int l,int r){//建出树 
    if(l==r){
        o=l;return;//已经是子节点,直接赋值 
    }o=++ncnt;
    int mid=(l+r)>>1;
    buildOut(lc[o],l,mid);
    buildOut(rc[o],mid+1,r);
    addedge(o,lc[o],0);//从o向o的左右子树连一条权值为0的有向边
    addedge(o,rc[o],0); 
}
void buildIn(int &o,int l,int r){//建入树 
    if(l==r){
        o=l;return;
    }
    o=++ncnt;
    int mid=(l+r)>>1;
    buildIn(lc[o],l,mid);
    buildIn(rc[o],mid+1,r);
    addedge(lc[o],o,0);//从o向o的左右子树连一条权值为0的有向边 
    addedge(rc[o],o,0);
}
int L,R;
void update(int o,int l,int r,int f,int val,short type){
    if(L<=l && R>=r){
        type==2?addedge(f,o,val):addedge(o,f,val);
        return;
    }
    int mid=(l+r)>>1;
    if(L<=mid)update(lc[o],l,mid,f,val,type);
    if(R>mid)update(rc[o],mid+1,r,f,val,type);
}
const int inf=0x7fffffffffffffff;
int dis[M+1];
priority_queue< pair<int,int> > q;
int vis[M+1];
void dijkstra(int s){
    for(int i=1;i<=M;i++)dis[i]=inf,vis[i]=0;
    dis[s]=0;q.push(make_pair(0,s));
    while(q.size()){
        int x=q.top().second;q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(int i=head[x];i;i=nxt(i)){
            int y=to(i),z=val(i);
            if(!vis[y]&&dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
inline int read(){
    int data=0,w=1;char ch=0;
    while(ch!='-' && (ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(ch>='0' && ch<='9')data=data*10+ch-'0',ch=getchar();
    return data*w;
}
mainint main(){
    n=read();m=read();s=read();
    ncnt=n;//建边要求,线段树节点从n+1开始编号 
    buildOut(rt1,1,n);buildIn(rt2,1,n);
    while(m--){
        int opt,f,t,val;
        opt=read();
        if(opt==1){
            f=read();t=read();val=read();
            addedge(f,t,val);//上面对叶子节点已经处理了,直接连边 
        }else{
            f=read();L=read();R=read();val=read();
            update(opt==2?rt1:rt2,1,n,f,val,opt);
        }
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
        printf("%lld ",dis[i]<inf?dis[i]:-1);
    return 0;
}