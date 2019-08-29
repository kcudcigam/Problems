#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	};
	
}yin;
const int maxm=3*1e5+100;
struct edge{
	int x,y,w;
}e[maxm<<1];

int cmp(edge a,edge b)
{
	return a.w<b.w;
}
int f[maxm],r[maxm],fa[maxm][23],f2[maxm];
int gf(int x){if(f[x]==x)return x;return gf(f[x]);}
void merge(int x,int y,int xx)
{
	int sx=gf(x),sy=gf(y);
	if(sx^sy)
	{
		if(r[sx]<r[sy])
		{
			f[sx]=f[sy];
			f2[sx]=xx;
		}
		else
		{
			f[sy]=f[sx];
			f2[sy]=xx;
			if(!(r[sx]^r[sy]))++r[sx];
		}
	}
	return ;
}
int dep[maxm],mi[maxm][23];
vector<pair<int,int> > v[maxm];
void dfs(int u,int ff,int ww)
{
	fa[u][0]=ff;
	mi[u][0]=ww;
	dep[u]=dep[ff]+1;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1],mi[u][i]=max(mi[u][i-1],mi[mi[u][i-1]][i-1]);
	for(unsigned int i=0;i<v[u].size();i++)
	{
		if(v[u][i].first!=ff)dfs(v[u][i].first,u,v[u][i].second);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int ans=0;
	for(int i=20;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])
		{
			ans=max(ans,mi[x][i]);
			x=fa[x][i];
		}
	}
	if(x==y)return ans;
	for(int i=20;i;i--)
	{
		if(x!=y)
		{
			ans=max(ans,max(mi[x][i],mi[y][i]));
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return ans;
}
int n,m,q;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	yin>>n>>m>>q;
	for(int i=1;i<=n;i++)f[i]=i,r[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		yin>>x>>y>>z;
		e[i].x=x;
		e[i].y=y;
		e[i].w=z;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1,k=0;i<=m;i++)
	{
		merge(e[i].x,e[i].y,i);
	}
	for(int i=1;i<=n;i++)
	{
		v[f[i]].push_back(make_pair(i,e[f2[i]].w));
	}
	for(int i=1;i<=n;i++)if(f[i]==i)dfs(i,0,0);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		yin>>x>>y;
		if(gf(x)==gf(y))
		printf("%d\n",lca(x,y));
		else puts("-1");
	}
	return 0;
}

