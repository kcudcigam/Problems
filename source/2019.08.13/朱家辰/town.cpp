#include<bits/stdc++.h>
#define maxn 300010
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int fa[maxn],ans[maxn],d[maxn][2],dep[maxn];
int f[maxn][20],p[20];
int a[maxn<<1][3],b[maxn],tot;
int n,w[maxn][2];
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
void add(int x,int y)
{
	tot++;
	a[tot][0]=x;
	a[tot][1]=y;
	a[tot][2]=b[x];
	b[x]=tot;
	tot++;
	a[tot][0]=y;
	a[tot][1]=x;
	a[tot][2]=b[y];
	b[y]=tot;
}
void dfs(int x,int fa)
{
	d[x][0]=d[x][1]=x;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=b[x];i;i=a[i][2])
	{
		int y=a[i][1];
		if(y==fa) continue;
		dfs(y,x);
	}
}
int getfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
void myswap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) myswap(x,y);
	int ans=0;
	for(int i=19;i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
			ans+=p[i];
		}
	}
	if(x==y) return ans;
	for(int i=19;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
			ans+=p[i]+p[i];
		}
	}
	return ans+2;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	fread(n);
	for(int i=1;i<n;i++)
	{
		fread(w[i][0]),fread(w[i][1]);
		add(w[i][0],w[i][1]);
	}
	dfs(1,0);
	for(int k=1;k<=19;k++)
	{
		for(int i=1;i<=n;i++)
		f[i][k]=f[f[i][k-1]][k-1];
	}
	p[0]=1;
	for(int i=1;i<=19;i++) p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++)
	{
		int mx1,mx2,mx[4],ml=0;
		int fx=getfa(w[i][0]),fy=getfa(w[i][1]);
		mx[0]=d[fx][0],mx[1]=d[fx][1];
		mx[2]=d[fy][0],mx[3]=d[fy][1];
		for(int i=0;i<3;i++)
		{
			for(int j=i+1;j<=3;j++)
			{
				int tmp=lca(mx[i],mx[j]);
				if(tmp>ml)
				{
					ml=tmp;
					mx1=mx[i];
					mx2=mx[j];
				}
			}
		}
		printf("%d\n",ml);
		fa[fx]=fy;
		d[fy][0]=mx1;
		d[fy][1]=mx2;
	}
	return 0;
}


