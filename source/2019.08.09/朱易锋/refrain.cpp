#include<bits/stdc++.h>
#define ll long long
#define V void
#define R register
#define I inline
#define swap(x,y) (x^=y^=x^=y)
using namespace std;
int n=0,m1,m2;
const int N=100;
bool f[N][N],v[N];
int e[N][N];
int fe[N][N];
I int check(R int x,R int y)
{
	for(R int i=1;i<=n;i++)
	{
		if(e[x][i]!=e[y][i])
		{
			if(e[x][i]==1&&e[y][i]==0)return 1;
		}
		if(fe[x][i]!=fe[y][i])
		{
			if(fe[x][i]==-1&&fe[y][i]==0)return 1;
		}
	}
	return 0;
}
int flag=0;
int ans=0;
V dfs(R int now)
{
	if(now==n+1)
	{
		if(flag)ans++;
		return;
	}
	for(R int i=1;i<=n;i++)
	{
		if(v[i])continue;
		v[i]=1;
		if(f[i][now])flag++;
		dfs(now+1);
		v[i]=0;
		if(f[i][now])flag--;
	}
}
int main()
{
//	freopen("refrain.in","r",stdin);
//	freopen("refrain.out","w",stdout);
	R int num=0;
	scanf("%d",&num);
	scanf("%d %d %d",&n,&m1,&m2);
	for(R int i=1;i<=m1;i++)
	{
		R int x=0,y=0,z=1;
		scanf("%d %d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for(R int i=1;i<=m2;i++)
	{
		R int x=0,y=0,z=-1;
		scanf("%d %d",&x,&y);
		fe[x][y]=fe[y][x]=-1;
	}
	for(R int i=1;i<=n;i++)
	{
		for(R int j=i+1;j<=n;j++)
		{
			if(check(i,j))f[i][j]=1;
			if(check(j,i))f[j][i]=1;
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
