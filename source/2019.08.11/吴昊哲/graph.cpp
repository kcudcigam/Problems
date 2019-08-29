#include<bits/stdc++.h>
using namespace std;
int n,m,Q,x,y,z;
int g[10000][10000];
int main()
{
    freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x][y]=z;
		g[y][x]=z;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(g[i][k]!=0&&g[j][k]!=0&&g[i][k]+g[j][k]<g[i][j])
				{
					g[i][j]=g[i][k]+g[j][k];
				}
			}
		}
	}
	for(int i=1;i<=Q;i++)
	{
		cin>>x>>y;
		if(g[x][y]==0)cout<<-1<<endl;
		else cout<<g[x][y]-1<<endl;
	}
	return 0;
}


