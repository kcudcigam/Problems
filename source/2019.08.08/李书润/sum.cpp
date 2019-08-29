#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100001];
struct node
{
	long long lmax,rmax,mmax,maxx,sum;
}tree[400001];
ll max(ll x,ll y)
{
	return x>y?x:y;
}
void build(int l,int r,int x)
{
	if(l==r)
	{
		tree[x].lmax=max(0,a[l]);
		tree[x].rmax=max(0,a[l]);
		tree[x].mmax=a[l];
		tree[x].sum=a[l];
		tree[x].maxx=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,x*2);
	build(mid+1,r,x*2+1);
	tree[x].maxx=max(tree[x*2].maxx,tree[x*2+1].maxx);
	tree[x].lmax=max(tree[x*2].lmax,tree[x*2].sum+tree[x*2+1].lmax);
	tree[x].rmax=max(tree[x*2+1].rmax,tree[x*2+1].sum+tree[x*2].rmax);
	if(tree[x].maxx>=0)
	{
		tree[x].mmax=max(max(tree[x*2].mmax,tree[x*2+1].mmax),tree[x*2].rmax+tree[x*2+1].lmax);
	}
	else tree[x].mmax=tree[x].maxx;
	tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
bool nul(node x)
{
	return !((x.lmax)||(x.rmax)||(x.mmax)||(x.sum));
}
node query(int l,int r,int x,int a,int b)
{
	if(l>=a&&r<=b)return tree[x];
	node now={0,0,0,0,0};
	int mid=(l+r)/2;
	if(a<=mid)now=query(l,mid,x*2,a,b);
	if(b>mid)
	{
		if(nul(now))now=query(mid+1,r,x*2+1,a,b);
		else
		{
			node t=query(mid+1,r,x*2+1,a,b),p=now;
			now={0,0,0,0,0};
			now.maxx=max(p.maxx,t.maxx);
			now.lmax=max(p.lmax,p.sum+t.lmax);
			now.lmax=max(t.rmax,t.sum+p.rmax);
			if(now.maxx>=0)now.mmax=max(max(p.mmax,t.mmax),p.rmax+t.lmax);
			else now.mmax=now.maxx;
			now.sum=p.sum+t.sum;
		}
	}
	return now;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,n,1);
	ll ans=-1e18;
	for(int i=1;i<n;i++)ans=max(ans,query(1,n,1,1,i).mmax+query(1,n,1,i+1,n).mmax);
	printf("%lld",ans);
	return 0;
}
