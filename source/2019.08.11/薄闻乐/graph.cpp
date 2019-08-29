#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],f[1001][1001],n,m,q,x,y,z;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		a[i][j]=-1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(a[x][y]==-1)
		a[x][y]=z;
		else a[x][y]=min(a[x][y],z);
		if(a[y][x]==-1)
		a[y][x]=z;
		else a[y][x]=min(a[y][x],z);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if(a[i][j]!=-1)
			f[i][j]=a[i][j];
			else f[i][j]=INT_MAX;
		}
	}
	if(n<=1000)
	{
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
			}
			
		}
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		if(f[x][y]==INT_MAX)
		cout<<-1<<endl;
		else cout<<f[x][y]<<endl;
	}
	}
	else {
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		if(f[x][y]==INT_MAX)
		cout<<-1<<endl;
		else cout<<a[x][y]<<endl;
	}
	}
	return 0;
}
