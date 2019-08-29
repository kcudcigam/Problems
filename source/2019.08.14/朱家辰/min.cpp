#include<bits/stdc++.h>
#define maxn 200010
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll f[maxn],s[maxn],a[4];
int n;
ll val(ll x)
{
	return a[0]*x*x*x+a[1]*x*x+a[2]*x+a[3];
}
struct node{
	int l,r;
	ll mxf,mns;
	ll mxans;
	bool p;
};
node tr[maxn<<2];
void build(int x,int l,int r)
{
	tr[x].l=l;
	tr[x].r=r;
	tr[x].mxf=-2e18,tr[x].mns=0x80000001;
	tr[x].mxans=-2e18;
	tr[x].p=false;
	if(l==r) return;
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void down(int x)
{
	if(tr[x].p)
	{
		int lc=x<<1,rc=x<<1|1;
		tr[lc].mns=tr[rc].mns=tr[x].mns;
		tr[lc].mxans=tr[lc].mxf+val(tr[x].mns);
		tr[rc].mxans=tr[rc].mxf+val(tr[x].mns);
		tr[x].p=false;
		tr[lc].p=tr[rc].p=true;
	}
}
void up(int x)
{
	int lc=x<<1,rc=x<<1|1;
	tr[x].mxf=max(tr[lc].mxf,tr[rc].mxf);
	tr[x].mns=min(tr[lc].mns,tr[rc].mns);
	tr[x].mxans=max(tr[lc].mxans,tr[rc].mxans);
}
void update(int x,int l,int r,ll mn)
{
	if(tr[x].r<l||r<tr[x].l) return;
	if(l<=tr[x].l&&tr[x].r<=r)
	{
		tr[x].mns=mn;
		tr[x].p=true;
		tr[x].mxans=tr[x].mxf+val(mn);
		return;
	}
	down(x);
	update(x<<1,l,r,mn);
	update(x<<1|1,l,r,mn);
	up(x);
}
void add(int x,int p,ll k)
{
	if(tr[x].l==p&&tr[x].r==p)
	{
		tr[x].mxf=k;
		return;
	}
	down(x);
	int mid=tr[x].l+tr[x].r>>1;
	if(p<=mid) add(x<<1,p,k);
	else add(x<<1|1,p,k);
	up(x);
}
ll query(int x,int p)
{
	if(tr[x].l==p&&tr[x].r==p) return tr[x].mns;
	down(x);
	int mid=tr[x].l+tr[x].r>>1;
	if(p<=mid) return query(x<<1,p);
	else return query(x<<1|1,p);
	up(x);
}
int ef(int l,int r,ll k)
{
	while(l<r)
	{
		int mid=l+r>>1;
		if(k>=query(1,mid)) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<4;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	build(1,0,n);
	add(1,0,0);
	for(int i=1;i<=n;i++)
	{
		update(1,ef(0,i,s[i]),i-1,s[i]);
		f[i]=tr[1].mxans;
		add(1,i,f[i]);
	}
	printf("%lld",f[n]);
	return 0;
}

