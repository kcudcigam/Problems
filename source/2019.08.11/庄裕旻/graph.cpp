#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
#define mkp make_pair
const int maxn=300000;
int n,m,Q;
map<pair<int,int>,int> mp;
inline void ckm(int &v,int w) { v=v?min(v,w):w; }
struct Edge { int u,v,w; } E[maxn];
inline bool operator<(const Edge &a,const Edge &b) { return a.w<b.w; }
vector<pair<int,int> > G[maxn];
int fa[maxn],mv[maxn][20],fv[maxn][20],vis[maxn],dep[maxn];
inline int ff(int u)
{
	int a=u,b;
	while(u!=fa[u]) u=fa[u];
	while(a!=u)
	{
		b=fa[a];
		fa[a]=u;
		a=b;
	}
	return u;
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	fv[u][0]=fa;
	vis[u]=true;
	for(auto it:G[u]) if(!vis[it.first])
	{
		mv[it.first][0]=it.second;
		dfs(it.first,u);
	}
}
int query(int u,int v)
{
	if(dep[v]>dep[u]) swap(u,v);
	int res=0;
	for(int i=19;i>=0;i--)
		if(dep[fv[u][i]]>=dep[v])
		{
			res=max(res,mv[u][i]);
			u=fv[u][i];
		}
	for(int i=19;i>=0;i--)
		if(fv[u][i]!=fv[v][i])
		{
			res=max(res,mv[u][i]);
			res=max(res,mv[v][i]);
			u=fv[u][i];
			v=fv[v][i];
		}
	if(u!=v) res=max(res,max(mv[u][0],mv[v][0]));
	return res;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=0;i<m;i++)
	{
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		if(u>v) swap(u,v);
		ckm(mp[mkp(u,v)],w);
	}
	m=0;
	for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();++it)
		E[m++]=(Edge){it->first.first,it->first.second,it->second};
	sort(E,E+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<m;i++)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(ff(u)==ff(v)) continue;
		fa[ff(u)]=ff(v);
		G[u].push_back(mkp(v,w));
		G[v].push_back(mkp(u,w));
//		printf("add %d %d\n",u,v);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			fv[i][j]=fv[fv[i][j-1]][j-1];
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++)
			mv[i][j]=max(mv[i][j-1],mv[fv[i][j-1]][j-1]);
	while(Q-->0)
	{
		int u,v; scanf("%d%d",&u,&v);
		if(ff(u)!=ff(v)) puts("-1");
		else printf("%d\n",query(u,v));
	}
	return 0;
}
