#include<bits/stdc++.h>
using namespace std;
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;char c;bool f=0;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);return *this;
	}
}yin;
const int maxn=1e7+10;
int n,m;
int g1,g2,g3,g4,g5;
struct seg{
	struct node{int ma,tag,mas;}a[maxn<<2];
	void pushup(int p){	node &x=a[p<<1],&y=a[p<<1|1];if(x.ma>y.ma)a[p].ma=x.ma,a[p].mas=x.mas;else a[p].ma=y.ma,a[p].mas=y.mas;}
	void build(int p,int l,int r){if(l==r){a[p].ma=0;a[p].tag=0;a[p].mas=l;return ;}int mid=(l+r)>>1;build(p<<1,l,mid);build(p<<1|1,mid+1,r);pushup(p);}void build(int x){build(1,1,x);}
	void pushdown(int p){if(!a[p].tag)return ;node &x=a[p<<1],&y=a[p<<1|1];x.ma+=a[p].tag;x.tag+=a[p].tag;y.ma+=a[p].tag;y.tag+=a[p].tag;a[p].tag=0;}
	void add(int p,int ll,int rr,int l,int r,int d){pushdown(p);if(l<=ll&&rr<=r){a[p].tag+=d;a[p].ma+=d;return ;}int mid=(ll+rr)>>1;if(l>mid)add(p<<1|1,mid+1,rr,l,r,d);else if(r<=mid)add(p<<1,ll,mid,l,r,d);else add(p<<1,ll,mid,l,r,d),add(p<<1|1,mid+1,rr,l,r,d);pushup(p);}void add(int l,int r,int d){add(1,1,m,l,r,d);}
	int query(){return a[1].mas;}
}x;
inline int cc(int x)
{
	return g1*x+g2*x*x+g3*x*x*x+g4*x*x*x*x+g5*x*x*x*x*x;
}
const int maxm=1000;
int l[maxm],r[maxm],vis[maxm];
int main()
{
	fre("stand");
	yin>>n>>m;
	yin>>g1>>g2>>g3>>g4>>g5;
	for(int i=1;i<=n;i++)
	{
		yin>>l[i]>>r[i];
	}
	int ansl=0,ansr=m;
	for(int i=1;i<=n;i++)
	{
		ansl=max(ansl,l[i]);
		ansr=min(ansr,r[i]);
	}
	if(ansl<=ansr)
	{
		cout<<cc(n)<<endl;
		return 0;
	}
	x.build(m);
	for(int i=1;i<=n;i++){
		x.add(l[i],r[i],1);
	}
	int tt=n,ans=0;
	while(tt)
	{
		int wz=x.query(),sum=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&l[i]<=wz&&wz<=r[i])x.add(l[i],r[i],-1),vis[i]=1,sum++;
		}
		tt-=sum;
		ans+=cc(sum);
	}
	cout<<ans<<endl;
	return 0;
}
