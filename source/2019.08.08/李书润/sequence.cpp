#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
struct node
{
	ll a0,t;
}tree[2000001];
inline void pushdown(int l,int r,int x)
{
	if(l==r)return;
	tree[x*2].a0+=tree[x].a0,tree[x*2].t+=tree[x].t;
	ll mid=(l+r)/2,s=tree[x].a0+1ll*(mid-l+1)*tree[x].t;
	tree[x*2+1].a0+=s,tree[x*2+1].t+=tree[x].t;
	tree[x].a0=0,tree[x].t=0;
}
void add(int l,int r,int x,int a,int b,ll s,ll t)
{
	if(l>=a&&r<=b)
	{
		tree[x].a0+=1ll*(l-a)*t+s;
		tree[x].t+=1ll*t;
		return;
	}
	int mid=(l+r)/2;
	if(a<=mid)add(l,mid,x*2,a,b,s,t);
	if(b>mid)add(mid+1,r,x*2+1,a,b,s,t);
}
ll ask(int l,int r,int x)
{
	pushdown(l,r,x);
	if(l==r)return tree[x].a0;
	int mid=(l+r)/2;
	return ask(l,mid,x*2)^ask(mid+1,r,x*2+1);
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	register int n,m,l,r;
	ll s,e;
	read(n),read(m);
	for(register int i=1;i<=m;++i)
	{
		read(l),read(r),read(s),read(e);
		ll t=(e-s)/(1ll*r-l);
		add(1,n,1,l,r,s,t);
	}
	printf("%lld",ask(1,n,1));
	return 0;
}
