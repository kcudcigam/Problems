#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int MAXN=300010;

int n;
struct Edge
{
	int u,v;
	int next;
}E[MAXN*2];
int header[MAXN],tot=0;
int fa[MAXN];
int d1[MAXN],d2[MAXN];

void addEdge(int u,int v)
{
	E[++tot].u=u;E[tot].v=v;
	E[tot].next=header[u];header[u]=tot;
}

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

void merge(int x,int y)
{
	fa[get(x)]=get(y);
}

int bfs1(int x)
{
	int rrr;
	int temp=0;
	queue<int> q;memset(d1,0,sizeof(d1));
	q.push(x);d1[x]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(d1[x]>temp) {temp=d1[x];rrr=x;}
		for(int i=header[x];i;i=E[i].next)
		{
			int y=E[i].v;
			if(d1[y]) continue;
			d1[y]=d1[x]+1;
			q.push(y);
		}
	}
	return rrr;
}

int bfs2(int x)
{
	int temp=0;
	queue<int> q;memset(d2,0,sizeof(d2));
	q.push(x);d2[x]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(d2[x]>temp) {temp=d2[x];}
		for(int i=header[x];i;i=E[i].next)
		{
			int y=E[i].v;
			if(d2[y]) continue;
			d2[y]=d2[x]+1;
			q.push(y);
		}
	}
	return temp-1;
}

int main()
{
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<=n-1;++i)
    {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	merge(u,v);
    	addEdge(u,v);addEdge(v,u);
    	int startpos=bfs1(get(u));
    	printf("%d\n",bfs2(startpos));
	}
	return 0;
}
