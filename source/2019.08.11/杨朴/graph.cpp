#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+5
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
int n,m,t,dist[MAXN],in[MAXN],e[MAXN][MAXN],last=-1;
queue <int> Q;
vector < pii > edge[MAXN];
void print(int y)
{
	if(dist[y]==0x7f7f7f7f)
		printf("-1\n");
	else
		printf("%d\n",dist[y]);
}
void spfa(int x,int y)
{
	if(x==last)
	{
		print(y);
		return;
	}
	while(!Q.empty())
		Q.pop();
	memset(dist,0x7f,sizeof(dist));
	memset(in,0,sizeof(in));
	Q.push(x);
	in[x]=1;
	dist[x]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		in[u]=0;
		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i].first,w=edge[u][i].second;
			if(max(dist[u],w)<dist[v])
			{
				dist[v]=max(dist[u],w);
				if(!in[v])
				{
					in[v]=1;
					Q.push(v);
				}
			}
		}
	}
	print(y);
	last=x;
	return;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(e,0x7f,sizeof(e));
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[x][y]=e[y][x]=min(e[x][y],w);
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(e[i][j]!=0x7f7f7f7f)
				edge[i].push_back(mp(j,e[i][j])),edge[j].push_back(mp(i,e[i][j]));
	for(int i=1;i<=t;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		spfa(x,y);
	}
	return 0;
}
