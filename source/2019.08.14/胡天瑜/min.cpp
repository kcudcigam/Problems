#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200010;

int n;
long long A,B,C,D;
int a[MAXN],tag[MAXN],p[MAXN],pre[MAXN];
long long dp[MAXN];
long long ans[MAXN];
struct SegmentTree
{
	int l,r;
	long long dat;
}t[MAXN*4];

void build(int p,int l,int r)
{
	t[p].l=l;t[p].r=r;
	if(l==r) {t[p].dat=-(1ll*1<<60);return;}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}

void change(int p,int x,long long v)
{
	if(t[p].l==t[p].r) {t[p].dat=v;return;}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,v);
	else change(p*2+1,x,v);
	t[p].dat=max(t[p*2].dat,t[p*2+1].dat);
}

long long ask(int p,int l,int r)
{
	if(l<=t[p].l&&r>=t[p].r) return t[p].dat;
	int mid=(t[p].l+t[p].r)/2;
	long long val=-(1ll*1<<60);
	if(l<=mid) val=max(val,ask(p*2,l,r));
	if(r>mid) val=max(val,ask(p*2+1,l,r));
	return val;
}

long long f(int x)
{
	return A*x*x*x+B*x*x+C*x+D;
}

int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	a[0]=-(1<<30);
	for(int i=1;i<=n;++i)
	{
		if(a[i]>a[i-1]) continue;
		tag[i]=1;
	}
	int here=1;
	build(1,1,n);
	for(int i=1;i<=n;++i)
	{
		if(tag[i])
		{
			p[i]=here;
			here=i;
		}
		else p[i]=i-1;
	}
	dp[0]=0;dp[1]=f(a[1]);
	change(1,1,dp[1]);
	for(int i=2;i<=n;++i)
	{
		if(tag[i]==0)
		{
			dp[i]=max(dp[i-1]+f(a[i]),dp[i-1]);
		}
		else
		{
			int kkk=lower_bound(a+p[i],a+i,a[i])-a-p[i]+1;
			long long aaa=ask(1,kkk,i-1);
			dp[i]=max(aaa+f(a[i]),dp[kkk-1]+f(a[i]));
		}
		change(1,i,dp[i]);
	}
	printf("%lld",dp[n]);
	return 0;
}
