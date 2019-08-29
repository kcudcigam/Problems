#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300005;

int n,m,q;
struct Edge
{
	int u,v;
	int ne;
}E[MAXN*2];
int header[MAXN],tot=0;
int forcepoint[MAXN],anothermethod[MAXN],linkone[MAXN];

void addEdge(int u,int v)
{
	E[++tot].u=u;E[tot].v=v;
	E[tot].ne=header[u];header[u]=tot;
	if(u==1) linkone[v]=1;
}

void forcechange(int x,int d)
{
	forcepoint[x]+=d;
	for(int i=header[x];i;i=E[i].ne)
	{
		int y=E[i].v;
		forcepoint[y]+=d;
	}
}

int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	memset(linkone,0,sizeof(linkone));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);addEdge(v,u);
	}
	if(n<=3000&&m<=3000&&q<=3000)
	{
		for(int i=1;i<=q;++i)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				int x,d;
				scanf("%d%d",&x,&d);
				forcechange(x,d);
			}
			if(type==0)
			{
				int x;
				scanf("%d",&x);
				printf("%d\n",forcepoint[x]);
			}
		}
	}
	else
	{
		for(int i=1;i<=q;++i)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				int x,d;
				scanf("%d%d",&x,&d);
				if(x!=1)
				{
					forcechange(x,d);
				}
				if(x==1) anothermethod[1]+=d;
			}
			if(type==0)
			{
				int x;
				scanf("%d",&x);
				if(x==1)
				{
					printf("%d\n",anothermethod[1]+forcepoint[1]);
				}
				else
				{
					if(linkone[x]!=1) printf("%d\n",forcepoint[x]);
					else printf("%d\n",anothermethod[1]+forcepoint[x]);
				}
			}
		}
	}
	return 0;
}
