#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
#define mod 1000000007
using namespace std;
ll fa[maxn],hd[maxn],nxt[maxn];
ll cnt[3][maxn],fac[maxn],sz[maxn],ans;
bool c[maxn];
ll t,n,m1,m2;
void fread(ll &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
void calc()
{
	for(ll i=1;i<=n;i++)
	hd[i]=fa[i]=i,sz[i]=1;
	fac[0]=1;
	for(ll i=1;i<=n;i++)
	fac[i]=fac[i-1]*i%mod;
}
ll getfa(ll x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
ll ksm(ll x,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k&1) ans=ans*x%mod;
		k>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	fread(t);
	fread(n),fread(m1),fread(m2);
	calc();
	for(ll i=1;i<=m1;i++)
	{
		ll x,y;
		fread(x),fread(y);
		ll fx=getfa(x),fy=getfa(y);
		if(fx==fy) c[fx]=true;
		else
		{
			nxt[x]=nxt[y]=1;
			hd[hd[x]]=hd[y];
			hd[hd[y]]=hd[x];
			hd[fy]=hd[x];
			fa[fx]=fy,sz[fy]+=sz[fx];
		}
	}
	for(ll i=1;i<=m2;i++)
	{
		ll x,y;
		fread(x),fread(y);
		ll fx=getfa(x),fy=getfa(y);
		if(fx==fy) c[fx]=true;
		else
		{
			nxt[x]=nxt[y]=-1;
			hd[hd[x]]=hd[y];
			hd[hd[y]]=hd[x];
			hd[fy]=hd[x];
			fa[fx]=fy,sz[fy]+=sz[fx];
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if(fa[i]==i)
		{
			if(c[i])
			cnt[0][sz[i]]++;
			else
			{
				if(sz[i]&1) cnt[1][sz[i]]++;
				else
				{
					if(nxt[hd[i]]==1)
					cnt[1][sz[i]]++;
					else
					cnt[2][sz[i]]++;
				}
			}
		}
	}
	ans=1;
	for(ll i=1;i<=n;i++)
	{
		if(cnt[0][i]!=0)
		{
			ans=ans*ksm(i,cnt[0][i])%mod;
			ans=ans*fac[cnt[0][i]]%mod;
		}
		if(cnt[1][i]!=0)
		{
			ans=ans*fac[cnt[1][i]]%mod;
			if(i%2==0) ans=ans*ksm(2,cnt[1][i])%mod;
		}
		if(cnt[2][i]!=0)
		{
			ans=ans*fac[cnt[2][i]]%mod;
			if(i%2==0) ans=ans*ksm(2,cnt[2][i])%mod;
		}
	}
	ll tmp=(fac[n]-ans)%mod;
	tmp=(tmp+mod)%mod;
	printf("%lld\n",tmp);
	return 0;
}

