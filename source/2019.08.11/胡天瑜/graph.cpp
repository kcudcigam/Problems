#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=300005;

int n,m,q,t;
struct Edge
{
	int u,v,w;
	int ne;
	int tag;
}E[MAXN*2],e[MAXN*2];
int header[MAXN],tot=0;
int hh[MAXN],tt=0;
int fa[MAXN];
int v[MAXN],cnt=0,root[MAXN];
struct F
{
	int num;
	int maxx;
}f[MAXN][21];
int d[MAXN];

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

void addEdge1(int u,int v,int w)
{
	E[++tot].u=u;E[tot].v=v;E[tot].w=w;
	E[tot].ne=header[u];header[u]=tot;
	E[tot].tag=0;
}

void addEdge2(int u,int v,int w)
{
	e[++tt].u=u;e[tt].v=v;e[tt].w=w;
	e[tt].ne=hh[u];hh[u]=tt;
}

void dfsconnect(int x)
{
	v[x]=cnt;
	for(int i=hh[x];i;i=e[i].ne)
	{
		int y=e[i].v;
		if(v[y]) continue;
		dfsconnect(y);
	}
}

void bfs(int r)
{
	queue<int> q;
	q.push(r);d[r]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=hh[x];i;i=e[i].ne)
		{
			int y=e[i].v;
			if(d[y]) continue;
			d[y]=d[x]+1;
			f[y][0].num=x;f[y][0].maxx=e[i].w;
			for(int j=1;j<=t;++j)
			{
				f[y][j].num=f[f[y][j-1].num][j-1].num;
				f[y][j].maxx=max(f[y][j-1].maxx,f[f[y][j-1].num][j-1].maxx);
			}
			q.push(y);
		}
	}
}

int lca(int x,int y)
{
	int returnthings=0;
	if(d[x]>d[y]) swap(x,y);
	int temp1=0;
	for(int i=t;i>=0;--i)
	{
		if(d[f[y][i].num]>=d[x])
		{
			temp1=max(temp1,f[y][i].maxx);
			y=f[y][i].num;
		}
	}
	if(x==y) return temp1;
	int temp2=0;
	for(int i=t;i>=0;--i)
	{
		if(f[x][i].num!=f[y][i].num)
		{
			temp2=max(temp2,f[x][i].maxx);
			temp2=max(temp2,f[y][i].maxx);
			x=f[x][i].num;y=f[y][i].num;
		}
	}
	temp2=max(temp2,f[x][0].maxx);
	returnthings=max(temp1,temp2);
	return returnthings;
}

bool cmp(Edge a,Edge b) {return a.w<b.w;}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	t=(int)(log(n+1)/log(2))+1;
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge1(u,v,w);
	}
	sort(E+1,E+tot+1,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=tot;++i)
	{
		int x=get(E[i].u);
		int y=get(E[i].v);
		if(x==y) continue;
		fa[x]=y;
		E[i].tag=1;
	}
	for(int i=1;i<=tot;++i)
	{
		if(E[i].tag)
		{
			addEdge2(E[i].u,E[i].v,E[i].w);
			addEdge2(E[i].v,E[i].u,E[i].w);
		}
	}
	for(int i=1;i<=n;++i)
		if(!v[i])
		{
			++cnt;
			dfsconnect(i);
		}
	for(int i=1;i<=n;++i) if(!root[v[i]]) root[v[i]]=i;
	for(int i=1;i<=cnt;++i)
	{
		bfs(root[i]);
	}
	for(int i=1;i<=q;++i)
	{
		int aaa,bbb;
		scanf("%d%d",&aaa,&bbb);
		if(v[aaa]!=v[bbb])
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",lca(aaa,bbb));
		}
	}
	return 0;
}
/*
5 5 4
1 2 3
1 3 2
3 2 1
1 4 5
2 4 4
1 2
1 4
3 5
2 4
==========
16 20 30
1 2 3
2 3 4
2 4 2
2 5 1
1 6 4
6 7 3
7 8 2
6 9 2
9 10 3
9 11 2
12 13 3
13 14 1
12 15 4
15 16 1
1 3 1
5 8 1
2 6 5
7 10 8
13 15 2
12 16 5
=============
5 6 1
1 2 3
2 3 1
2 4 2
1 4 4
4 5 1
1 5 5
3 5
*/
