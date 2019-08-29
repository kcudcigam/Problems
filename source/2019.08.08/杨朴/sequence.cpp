#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+5;
#define ll long long
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())	if(c=='-')	f=-f;
	for(;isdigit(c);c=getchar())	x=x*10+c-'0';
	x=x*f;
}
struct Node
{
	ll d,first;
}f[MAXN<<2],add[MAXN<<2];
int a[MAXN<<2],n,m;
void pushdown(int root,int l,int r)
{
	if(f[root].d||f[root].first)
	{
		int mid=(l+r)>>1;
		f[root<<1].d+=f[root].d;
		f[root<<1|1].d+=f[root].d;
		f[root<<1].first+=f[root].first;
		f[root<<1|1].first+=(f[root].first+(mid-l+1)*f[root].d);
		f[root].d=f[root].first=0;
	}
}
void update(int root,int l,int r,int x,int y,ll first,ll d)
{
	if(x<=l&&r<=y)
	{
		f[root].d+=d;
		f[root].first+=(l-x)*d+first;
		return;
	}
	pushdown(root,l,r);
	int mid=(l+r)>>1;
	if(x<=mid)
		update(root<<1,l,mid,x,y,first,d);
	if(y>mid)
		update(root<<1|1,mid+1,r,x,y,first,d);
}
ll query(int root,int l,int r,int pos)
{
	if(l==r)
		return a[l]+f[root].first;
	pushdown(root,l,r);
	int mid=(l+r)>>1;
	if(pos<=mid)
		return query(root<<1,l,mid,pos);
	if(pos>mid)
		return query(root<<1|1,mid+1,r,pos);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		ll s,e,d;
		read(l),read(r),read(s),read(e);
		d=(e-s)/(r-l);
		update(1,1,n,l,r,s,d);
	}
	ll ans=query(1,1,n,1);
	for(int i=2;i<=n;i++)
		ans^=query(1,1,n,i);
	cout<<ans;
	return 0;
}
