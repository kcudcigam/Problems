#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200010;
const int p=1000000007;

struct Edge
{
	int u,v;
	int ne;
}E[MAXN*2];
int header[MAXN],tot=0,cnt=0;
int water[MAXN*2],fire[MAXN*2];
int tag[MAXN],sep;
int num;
int n,m1,m2;
int vis[MAXN],root[MAXN];
long long minusans=0;
int block[MAXN];

void addEdge(int u,int v)
{
	E[++tot].u=u;E[tot].v=v;
	E[tot].ne=header[u];header[u]=tot;
}

void dfs(int x)
{
	vis[x]=cnt;
	for(int i=header[x];i;i=E[i].ne)
	{
		int y=E[i].v;
		if(vis[y]) continue;
		dfs(y);
	}
}

long long realans()
{
	long long ans=1;
	for(int i=n;i>=1;--i)
	{
		ans=ans*i;
		if(ans>p) ans=ans%p;
	}
	return ans;
}

int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	memset(tag,0,sizeof(tag));
	memset(vis,0,sizeof(vis));
	scanf("%d",&num);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		tag[a]=-1;tag[b]=-1;
		water[a]=b;water[b]=a;
		addEdge(a,b);addEdge(b,a);
	}
	for(int i=1;i<=m2;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(tag[a]==-1) tag[a]=2;
		else tag[a]=1;
		if(tag[b]==-1) tag[b]=2;
		else tag[b]=1;
		fire[a]=b;fire[b]=a;
		addEdge(a,b);addEdge(b,a);
	}
	if(num==1||num==2)
	{
		printf("0\n");
	}
	if(num>=3&&num<=6)
	{}
	if(num>=7&&num<=10)
	{}
	if(num>=11&&num<=14)
	{
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				++cnt;
				dfs(i);
			}
		}
		for(int i=1;i<=n;++i)
		{
			++block[vis[i]];
		}
		for(int i=1;i<=cnt;++i)
		{
			minusans=minusans*block[i]%p;
		}
		printf("%lld\n",realans()-minusans);
	}
	return 0;
}
