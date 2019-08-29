#include<bits/stdc++.h>
using namespace std;
const int MAXN=300000+5;
const int lim=300;
int n,m,Q,du[MAXN],add[MAXN],now[MAXN];
vector <int> edge[MAXN],db[MAXN];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u==v)
			continue;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		du[i]=edge[i].size();
	for(int i=1;i<=n;i++)
		for(int j=0;j<du[i];j++)
			if(du[edge[i][j]]>lim)
				db[i].push_back(edge[i][j]);
	for(int i=1;i<=Q;i++)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==0)
		{
			int x,sum=0;
			scanf("%d",&x);
			if(du[x]>lim)
				printf("%d\n",now[x]+add[x]);
			else
			{ 
				for(int j=0;j<du[x];j++)
					sum+=add[edge[x][j]];
				sum+=add[x];
				printf("%d\n",sum);
			}
		}
		if(opt==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add[x]+=y;
			for(int j=0;j<db[x].size();j++)
				now[db[x][j]]+=y;
		}
	}
	return 0;
}
