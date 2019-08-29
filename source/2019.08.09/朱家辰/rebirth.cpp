#include<bits/stdc++.h>
#define maxn 200010
#define maxm 500010
#define inf 0x3f3f3f3f
using namespace std;
priority_queue< pair<int,int> > q;
int dis[maxn][2],vis[maxn];
int a[maxm<<1][4],b[maxn],tot;
int n,m,t;
void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=z;
	a[tot][3]=b[x];
	b[x]=tot;
	tot++;
	a[tot][0]=y;
	a[tot][1]=x;
	a[tot][2]=z;
	a[tot][3]=b[y];
	b[y]=tot;
}
void dij()
{
	for(int i=1;i<=n;i++)
	dis[i][0]=dis[i][1]=inf;
	dis[1][0]=dis[1][1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=b[u];i;i=a[i][3])
		{
			int v=a[i][1];
			if(dis[u][0]+a[i][2]<dis[v][0])
			{
				dis[v][1]=dis[v][0];
				dis[v][0]=dis[u][0]+a[i][2];
				q.push(make_pair(-dis[v][0],v));
			}
			else
			dis[v][1]=min(dis[u][0]+a[i][2],dis[v][1]);
		}
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	fread(t);
	fread(n),fread(m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		fread(x),fread(y),fread(z);
		if(x==y) continue;
		add(x,y,z);
	}
	dij();
	for(int i=1;i<=n;i++)
	{
		if(dis[i][1]!=inf)
		printf("%d ",dis[i][1]);
		else printf("-1 ");
	}
	return 0;
}

