#include<bits/stdc++.h>
using namespace std;
int n,q;
struct op{//离散化所以要记录操作
	int opt;
	string x,y;
	int l,r;
	int user;
}opts[50005];
string plusone(string s){int w;//IP地址+1
	s[w=s.length()-1]++;
	while(w>=0&&s[w]=='g'){
		s[w]='0';
		if(s[w-1]==':') s[w-2]++,w-=2;
		else s[w-1]++,w--;
	}
	if(s[w]==58) s[w]='a';
	return s;
}
struct LSH{//离散化
	set<string> s;int cnt;
	unordered_map<string,int> toNum;
	inline void pls(string str){s.insert(str);}
	inline void run(){
		auto it=s.begin(),ti=s.end();//ti是it的上一个
		for(;it!=s.end();it++){
			if(it!=s.begin()){
				if(ti==s.end()) ti=s.begin();
				else ti++;
				if(plusone(*ti)!=(*it)) cnt++;
			}
			toNum[*it]=++cnt;
		}
	}
	inline int gNum(string s){return toNum[s];}
}lsh;
bitset<4000005> isnp;int pr[400005],prcnt;int W[200005],anscnt;
map<int,int> ni;
void shai(int n){//筛出足够多的质数
	isnp[1]=1;
	for(int i=2;i<=n;i++){
		if(!isnp[i]){
			pr[++prcnt]=i;
			if(i>200000) W[++anscnt]=i,ni[i]=anscnt;//记录一下倒过来是什么
			if(anscnt>=200000) return;
		}
		for(int j=1;j<=prcnt&&1ll*i*pr[j]<=n;j++){
			isnp[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}
#define ll long long
ll MIN(ll a,ll b){return a==0?b:b==0?a:a<b?a:b;}//这里建议没有数的时候min就是 0，方便输出但是要自己定义一下新的min
#define ls (p<<1)
#define rs (p<<1|1)
#define mid (l+r>>1)
struct node{//下面是线段树
	ll sum,mn,lazy,len;
	node operator +(node b){return {sum+b.sum,MIN(mn,b.mn),0,len+b.len};}
	node operator =(ll b){return {sum=b*len,mn=b,lazy=b,len};}
}tr[800005];
void build(int p,int l,int r){
	if(l==r){tr[p]={0,0,0,1};return;}
	build(ls,l,mid);build(rs,mid+1,r);tr[p]=tr[ls]+tr[rs];
}
void pushdown(int p){if(tr[p].lazy) tr[ls]=tr[p].lazy,tr[rs]=tr[p].lazy,tr[p].lazy=0;}
void chg(int p,int l,int r,int L,int R,ll c){
	if(l>=L&&r<=R){tr[p]=c;return;}
	pushdown(p);
	if(L<=mid) chg(ls,l,mid,L,R,c);
	if(R>mid) chg(rs,mid+1,r,L,R,c);
	tr[p]=tr[ls]+tr[rs];
}
ll qsum(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tr[p].sum;
	ll ans=0;
	pushdown(p);
	if(L<=mid) ans+=qsum(ls,l,mid,L,R);
	if(R>mid) ans+=qsum(rs,mid+1,r,L,R);
	return ans;
}
ll qmin(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tr[p].mn;
	ll ans=0;
	pushdown(p);
	if(L<=mid) ans=MIN(ans,qmin(ls,l,mid,L,R));
	if(R>mid) ans=MIN(ans,qmin(rs,mid+1,r,L,R));
	return ans;
}
int main(){
	shai(4000000);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>opts[i].opt;
		if(opts[i].opt==1) cin>>opts[i].user>>opts[i].x>>opts[i].y;
		else if(opts[i].opt==2) cin>>opts[i].x;
		else cin>>opts[i].x>>opts[i].y;
		lsh.pls(opts[i].x);
		if(opts[i].opt!=2) lsh.pls(opts[i].y);
	}
	lsh.run();
	for(int i=1;i<=q;i++) opts[i].l=lsh.gNum(opts[i].x),(opts[i].opt!=2)&&(opts[i].r=lsh.gNum(opts[i].y));
	n=lsh.cnt;//相当于一共就这么多节点
	build(1,1,n);
	for(int i=1;i<=q;i++){int op=opts[i].opt,l=opts[i].l,r=opts[i].r,id=opts[i].user;//按照思路写出来非常轻松
		if(op==1){
			ll sum=qsum(1,1,n,l,r);
			if((sum%W[id])||sum/W[id]==r-l+1) cout<<"NO"<<endl;
			else{
				chg(1,1,n,l,r,W[id]);
				cout<<"YES"<<endl;
			}
		}
		if(op==2){
			cout<<ni[qmin(1,1,n,l,l)]<<endl;
		}
		if(op==3){
			ll sum=qsum(1,1,n,l,r),mn=qmin(1,1,n,l,r);
			if(mn==0||sum%mn==0&&sum/mn==r-l+1) cout<<ni[mn]<<endl;
			else cout<<0<<endl;
		}
	}
	return 0;
}
