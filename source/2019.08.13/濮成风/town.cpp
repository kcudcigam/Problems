#include<bits/stdc++.h>
using namespace std;
const int maxn=3E5+5;
int n;
int size,head[maxn*2];
int ask[maxn][2],dep[maxn],fa[maxn][20];
int UFS[maxn];
int where[maxn][2];
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
void init(int u,int F,int d)
{
	dep[u]=d;
	fa[u][0]=F;
	for(int i=1;i<20;++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(v==F)
			continue;
		init(v,u,d+1);
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=0;i<20;++i)
		if(d&(1<<i))
			x=fa[x][i];
	if(x==y)
		return x;
	for(int i=19;i>=0;--i)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline int dis(int x,int y)
{
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
inline int find(int x)
{
	return UFS[x]==x?x:UFS[x]=find(UFS[x]);
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n-1;++i)
	{
		cin>>ask[i][0]>>ask[i][1];
		add(ask[i][0],ask[i][1]);
		add(ask[i][1],ask[i][0]);
	}
	for(int i=1;i<=n;++i)
		UFS[i]=where[i][0]=where[i][1]=i;
	init(1,1,0);
	for(int i=1;i<=n-1;++i)
	{
		int u=find(ask[i][0]),v=find(ask[i][1]);
		int len=-1,pos1=-1,pos2=-1;
		for(int k1=0;k1<2;++k1)
			for(int k2=0;k2<2;++k2)
			{
				int d=dis(where[u][k1],where[v][k2]);
				if(d>len)
					len=d,pos1=where[u][k1],pos2=where[v][k2];
			}
		int g=dis(where[u][0],where[u][1]);
		if(g>len)
			len=g,pos1=where[u][0],pos2=where[u][1];
		g=dis(where[v][0],where[v][1]);
		if(g>len)
			len=g,pos1=where[v][0],pos2=where[v][1];
		UFS[find(u)]=find(v);
		where[find(u)][0]=pos1,where[find(u)][1]=pos2;
		cout<<len<<endl;
	}
	return 0;
}

