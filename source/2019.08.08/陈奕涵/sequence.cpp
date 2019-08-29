#include<cstdio>
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;c< '0' || c >'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0' && c<='9';c=getchar())x=x*10+c-'0';
	x*=f;
}
const int maxn=500010;
int n,m;
//把询问离线 
struct asks{
	int l,r;
	long long s,e0;
	void reads(){
		read(l),read(r);
		read(s),read(e0);
	}
}ask[maxn];
//20分 线段树
struct tree{
	long long val,tag;
	int l,r;
}e[maxn<<2];
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
void pushup(int x){
	e[x].val=e[ls(x)].val^e[rs(x)].val;
}
void build(int x,int l,int r){
	e[x].l=l,e[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
}
void pushdown(int x){
	e[ls(x)].val+=e[x].tag;
	e[rs(x)].val+=e[x].tag;
	e[ls(x)].tag+=e[x].tag;
	e[rs(x)].tag+=e[x].tag;
	e[x].tag=0;
}
void add(int x,long long val,int l,int r){
	if(e[x].l>=l && e[x].r<=r){
		e[x].val+=val,e[x].tag+=val;
		return;
	}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(l<=mid)add(ls(x),val,l,r);
	if(r>mid)add(rs(x),val,l,r);
	pushup(x);
}
//剩下全部暴力走起 
long long a[maxn];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	//读入 
	read(n),read(m);
	bool can_tree=true;//线段树特判标志 
	for(int i=1;i<=m;++i){
		ask[i].reads();
		if(ask[i].s!=ask[i].e0)can_tree=false;
	}
	//如果保证s=e,线段树走起 
	if(can_tree){
		 build(1,1,n);
		 for(int k=1;k<=m;++k){
			int l=ask[k].l,r=ask[k].r;
			add(1,ask[k].s,l,r);
		}
		printf("%lld\n",e[1].val);
	}
	//不保证？暴力 
	else{
		for(int k=1;k<=m;++k){
			int l=ask[k].l,r=ask[k].r;
			long long s=ask[k].s,e0=ask[k].e0;
			for(int i=l;i<=r;++i)
				a[i]+=(s+(e0-s)/(r-l)*(i-l));
		}
		long long ans=a[1];
		for(int i=2;i<=n;++i)ans=ans^a[i];
		printf("%lld\n",ans);
	}
	return 0;	
}

