#include<bits/stdc++.h>
#define maxn 300010
#define inf 0x3f3f3f3f
using namespace std;
int a[maxn<<1][4],b[maxn],tot;
int n,m,q;
int f[maxn][21],g[maxn][21],d[maxn];
int fa[maxn];
bool vis[maxn];
struct node{
	int x,y,z;
};
node w[maxn];
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
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int getfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;
	f[x][0]=fa;
	vis[x]=true;
	for(int i=b[x];i;i=a[i][3])
	{
		int y=a[i][1];
		if(y==fa) continue;
		g[y][0]=a[i][2];
		dfs(y,x);
	}
}
void myswap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
int lca(int x,int y)
{
	if(d[x]<d[y]) myswap(x,y);
	int ans=0;
	for(int i=19;i>=0;i--)
	{
		if(d[f[x][i]]>=d[y])
		{
			ans=max(ans,g[x][i]);
			x=f[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			ans=max(ans,max(g[x][i],g[y][i]));
			x=f[x][i];
			y=f[y][i];
		}
	}
	return max(ans,max(g[x][0],g[y][0]));
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	fread(n),fread(m),fread(q);
	for(int i=1;i<=m;i++)
	fread(w[i].x),fread(w[i].y),fread(w[i].z);
	sort(w+1,w+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=getfa(w[i].x),fy=getfa(w[i].y);
		if(fx==fy) continue;
		fa[fx]=fy;
		add(w[i].x,w[i].y,w[i].z);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);
	for(int k=1;k<=19;k++)
	{
		for(int i=1;i<=n;i++)
		{
			f[i][k]=f[f[i][k-1]][k-1];
			g[i][k]=max(g[i][k-1],g[f[i][k-1]][k-1]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,fx,fy;
		fread(x),fread(y);
		fx=getfa(x),fy=getfa(y);
		if(fx!=fy) printf("-1\n");
		else printf("%d\n",lca(x,y));
	}
	return 0;
}

