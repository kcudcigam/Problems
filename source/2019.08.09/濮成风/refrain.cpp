#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1E9+7;
const int maxn=1E5+5;
int num;
int n,k1,k2,a[maxn],tot,size,head[maxn],bucket[maxn];
bool vis0[55][55],vis1[55][55],vis[maxn];
ll fac[maxn],inv[maxn];
struct hapi
{
	int x,y,type;
}e[555];
struct edge
{
	int to,next;
}E[maxn*2];
inline void add(int u,int v)
{
	E[++size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
inline ll qpow(ll x,ll y)
{
	ll ans=1,base=x;
	while(y)
	{
		if(y&1)
			ans=ans*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return ans;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=100000;++i)
		fac[i]=fac[i-1]*i%mod;
	for(int i=0;i<=100000;++i)
		inv[i]=qpow(fac[i],mod-2);
}
inline ll C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void work1()
{
	for(int i=1;i<=n;++i)
		a[i]=i;
	for(int i=1;i<=k1;++i)
	{
		++size;
		cin>>e[size].x>>e[size].y;
		vis0[e[size].x][e[size].y]=1;
		vis0[e[size].y][e[size].x]=1;
	}
	for(int i=1;i<=k2;++i)
	{
		++size;
		cin>>e[size].x>>e[size].y;
		vis1[e[size].x][e[size].y]=1;
		vis1[e[size].y][e[size].x]=1;
		e[size].type=1;
	}
	do
	{
		for(int i=1;i<=size;++i)
		{
			if(e[i].type==0&&!vis0[a[e[i].x]][a[e[i].y]])
				goto end;
			if(e[i].type==1&&!vis1[a[e[i].x]][a[e[i].y]])
				goto end;
		}
		++tot;
		end:;
	}while(next_permutation(a+1,a+n+1));
	cout<<fac[n]-tot<<endl;
}
void work2()
{
	cout<<(fac[n]-fac[k1]*fac[k2]%mod*fac[n-2*k1-2*k2]%mod*qpow(2,k1+k2)%mod+mod)%mod<<endl;
}
int TOT;
void dfs(int u)
{
	vis[u]=1;
	++TOT;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(vis[v])
			continue;
		dfs(v);
	}
}
void work3()
{
	for(int i=1;i<=k1+k2;++i)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			TOT=0;
			dfs(i);
			++bucket[TOT];
		}
	}
	ll ans=1;
	for(int i=1;i<=n;++i)
		ans=ans*qpow(i,bucket[i])%mod*fac[bucket[i]]%mod;
	cout<<(fac[n]-ans+mod)%mod<<endl;
}
void work4()
{
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>num>>n>>k1>>k2;
	init();
	if(n<=10)
	{
		work1();
		return 0;
	}
	else if(num==7||num==8||num==9||num==10)
	{
		work2();
		return 0;
	}
	else if(num==11||num==12||num==13||num==14)
	{
		work3();
		return 0;
	}
	else
		work4();
	return 0;
}

