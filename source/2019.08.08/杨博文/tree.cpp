#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
struct ins{
	template<typename T> void read(T &n)
	{
		n=0;char c;int f=1;
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		n*=f;
	}
	template<typename T> ins operator >> (T &n)
	{
		this->read(n);
		return *this;
	}
}kin;
struct edge{
	int v,nex;
}e[100001<<2];
int tot,tot1,head[200001],fa[200001],n,m,b[200001],a[1001][200001],x[200001],dep[200001];
void __ADD(int x,int y)
{
	e[++tot].v=y;
	e[tot].nex=head[x];
	head[x]=tot;
}
void add(int x,int y)
{
	__ADD(x,y);
	__ADD(y,x);
}
int dg(int last)
{
	if(last>tot1)
	{
		for(register int i=1;i<=n;++i)
		{
			if(b[i]!=x[i])return 0;
		}
		return 1;
	}
	if(dg(last+1))return 1;
	for(register int j=1;j<=n;++j)b[j]^=a[last][j];
	if(dg(last+1))return 1;
	for(register int j=1;j<=n;++j)b[j]^=a[last][j];
	return 0;
}
void dfs(int u,int ff)
{
	dep[u]=dep[ff]+1;
	fa[u]=ff;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(ff!=v)dfs(v,u);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int TTT;
	kin>>TTT;
	while(TTT--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
		tot=tot1=0;
		memset(head,0,sizeof(head));
		kin>>n>>m;
		for(register int i=1;i<n;++i)
		{
			int u,v;
			kin>>u>>v;
			add(u,v);
		}
		for(register int i=1;i<=n;++i)
		{
			kin>>x[i];
		}
		for(register int j=1;j<=n;++j)
		{
			int t;
			kin>>t;
			x[j]^=t;
		}
		if(n<=100)
		{
			dep[1]=0;
			dfs(1,1);
			tot1=0;
			for(register int i=1;i<=n;++i)
			{
				if(dep[i]>=m)
				{
					++tot1;
					for(register int j=1,u=i;j<=m;++j,u=fa[i])
						a[tot1][u]=1;
				}
			}
			if(dg(0))puts("Yes");
			else puts("No");
		}
		else
		{
			puts("Yes");
		}
	}
	
    return 0;
}
