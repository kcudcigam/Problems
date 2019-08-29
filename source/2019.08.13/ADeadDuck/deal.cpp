#pragma GCC optimize 2
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
const int maxn=1E5+5;
ll n,X,maxx;
ll f[maxn],g[maxn],bucket[maxn],ans;
ll sum[maxn];
int bel[maxn];
struct note
{
	ll w,a,b;
}a[maxn];
inline void add(ll&x,ll y)
{
	x=(x+y%mod+mod)%mod;
}
void init()
{
	g[0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=maxx;++j)
			bel[j]=sum[j]=0;
		for(int j=maxx;j>=1;--j)
		{
			if(!bel[j])
			{
				bel[j]=j;
				for(int k=1;k<=a[i].b&&j-a[i].w*k>=0;++k)
					add(sum[bel[j]],g[j-a[i].w*k]);
				for(int k=1;j-a[i].w*k>=0;++k)
					bel[j-a[i].w*k]=j;
			}
			else
			{
				add(sum[bel[j]],mod-g[j]);
				if(j-a[i].w*a[i].b>=0)
					add(sum[bel[j]],g[j-a[i].w*a[i].b]);
			}
			add(g[j],sum[bel[j]]);
		}
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>X;
	for(int i=1;i<=n;++i)
		cin>>a[i].w>>a[i].a>>a[i].b;
	maxx=X+a[n].w;
	init();
	f[0]=1;
	for(int i=n;i>=1;--i)
	{
		for(int j=0;j<=maxx;++j)
			bel[j]=sum[j]=0;
		for(int j=maxx;j>=1;--j)
		{
			if(!bel[j])
			{
				bel[j]=j;
				for(int k=1;k<=a[i].a&&j-a[i].w*k>=0;++k)
					add(sum[bel[j]],f[j-a[i].w*k]);
				for(int k=1;j-a[i].w*k>=0;++k)
					bel[j-a[i].w*k]=j;
			}
			else
			{
				add(sum[bel[j]],mod-f[j]);
				if(j-a[i].w*a[i].a>=0)
					add(sum[bel[j]],f[j-a[i].w*a[i].a]);
			}
			add(f[j],sum[bel[j]]);
		}
		for(int j=X;j<=maxx;++j)
			if(j-X<a[i].w&&(!(j-X<a[i-1].w)))
				add(ans,f[j]*g[j-X]);
	}
	cout<<ans<<endl;
	return 0;
}

