#include<bits/stdc++.h>
using namespace std;
int a[150][150],sx,sy,sze=2,vis[150][150],ans;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(nx<1||nx>128||ny<1||ny>128)
			continue;
		if(vis[nx][ny]||a[nx][ny]==1)
			continue;
		ans++;
		vis[nx][ny]=1;
		dfs(nx,ny);
	}
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&sx,&sy);
	sx++,sy++;
	if(sx>128||sy>128)
	{
		printf("infinity");
		return 0;
	}
	a[1][1]=a[1][2]=a[2][1]=1,a[2][2]=-1;
	for(int i=1;i<=6;i++)
	{
		int sc=1,ec=sze,sr=sze+1,er=sr+sze-1;
		for(int i=sc;i<=ec;i++)
			for(int j=sr;j<=er;j++)
				a[i][j]=a[i-sc+1][j-sr+1];
		sc=sze+1,ec=sc+sze-1,sr=1,er=sze;
		for(int i=sc;i<=ec;i++)
			for(int j=sr;j<=er;j++)
				a[i][j]=a[i-sc+1][j-sr+1];
		sc=sze+1,ec=sc+sze-1,sr=sze+1,er=sr+sze-1;
		for(int i=sc;i<=ec;i++)
			for(int j=sr;j<=er;j++)
				a[i][j]=-a[i-sc+1][j-sr+1];
		sze*=2;
	}
	if(a[sx][sy]==1)
	{
		if(sx>=2&&sx<=127&&sy>=2&&sy<=127)
			if(a[sx-1][sy]==-1&&a[sx][sy-1]==-1&&a[sx+1][sy]==-1&&a[sx][sy+1]==-1)
			{
				printf("1");
				return 0;
			}
		printf("infinity");
		return 0;
	}
	vis[sx][sy]=1;
	ans=1;
	dfs(sx,sy);	
	printf("%d",ans);
	return 0;
}
