#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
#define ll long long
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())	if(c=='-')	f=-f;
	for(;isdigit(c);c=getchar())	x=x*10+c-'0';
	x=x*f;
}
int n;
ll a[MAXN],ans=-1LL<<62;
struct Node
{
	ll sum,maxsum,lmax,rmax;
}tr[MAXN<<2];
void build(int l,int r,int id)
{
	if(l==r)
	{
		tr[id].sum=tr[id].maxsum=tr[id].lmax=tr[id].rmax=a[l];
		return;
	}
	int mid=(l+r)>>1,ls=id<<1,rs=id<<1|1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	tr[id].sum=tr[ls].sum+tr[rs].sum;
	tr[id].maxsum=max(max(tr[ls].maxsum,tr[rs].maxsum),tr[ls].rmax+tr[rs].lmax);
	tr[id].lmax=max(tr[ls].lmax,tr[ls].sum+tr[rs].lmax);
	tr[id].rmax=max(tr[rs].rmax,tr[rs].sum+tr[ls].rmax);
}
Node query(int l,int r,int L,int R,int id)
{
	if(L<=l&&r<=R)
		return tr[id];
	int mid=(l+r)>>1,ls=id<<1,rs=id<<1|1;
	if(R<=mid)
		return query(l,mid,L,R,ls);
	if(mid<L)
		return query(mid+1,r,L,R,rs);
	Node lo=query(l,mid,L,R,ls),ro=query(mid+1,r,L,R,rs),ans;
	ans.sum=lo.sum+ro.sum;
	ans.maxsum=max(max(lo.maxsum,ro.maxsum),lo.rmax+ro.lmax);
	ans.lmax=max(lo.lmax,lo.sum+ro.lmax);
	ans.rmax=max(ro.rmax,ro.sum+lo.rmax);
	return ans;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	build(1,n,1);
	for(int i=1;i<n;i++)
		ans=max(ans,query(1,n,1,i,1).maxsum+query(1,n,i+1,n,1).maxsum);
	cout<<ans;
	return 0;
}
