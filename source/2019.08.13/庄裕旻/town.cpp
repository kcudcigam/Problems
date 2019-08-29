#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,pair<int,int> > ZJ;
#define mzj(x,a,b) make_pair(x,make_pair(a,b))
const int maxn=300005;
int n,x[maxn],y[maxn],res[maxn],fa[maxn];
ZJ zj[maxn];
vector<int> G[maxn];
int dep[maxn],fn[20][maxn];
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
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	fn[0][u]=fa;
	for(int i=0;i<(int)G[u].size();i++) if(G[u][i]!=fa) dfs1(G[u][i],u);
}
inline int lca(int a,int b)
{
	if(dep[a]<dep[b]) swap(a,b);
	int res=0;
	for(int i=19;i>=0;i--)
		if(dep[fn[i][a]]>=dep[b])
		{
			a=fn[i][a];
			res+=1<<i;
		}
	for(int i=19;i>=0;i--)
		if(fn[i][a]!=fn[i][b])
		{
			res+=1<<(i+1);
			a=fn[i][a];
			b=fn[i][b];
		}
	if(a!=b) res+=2;
	return res;
}
inline bool operator<(const ZJ &a,const ZJ &b) { return a.first<b.first; }
inline ZJ Get(ZJ a,ZJ b)
{
	return max(
				max(mzj(lca(a.second.first,b.second.first),a.second.first,b.second.first),
					mzj(lca(a.second.first,b.second.second),a.second.first,b.second.second)),
				max(mzj(lca(a.second.second,b.second.first),a.second.second,b.second.first),
					mzj(lca(a.second.second,b.second.second),a.second.second,b.second.second))
				);
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++) { scanf("%d%d",&x[i],&y[i]); G[x[i]].push_back(y[i]); G[y[i]].push_back(x[i]); }
	for(int i=1;i<=n;i++) { fa[i]=i; zj[i]=mzj(0,i,i); }
	dfs1(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			fn[i][j]=fn[i-1][fn[i-1][j]];
	for(int i=1;i<=n-1;i++)
	{
		x[i]=ff(x[i]); y[i]=ff(y[i]);
		ZJ a=zj[x[i]],b=zj[y[i]];
		fa[x[i]]=y[i];
		zj[y[i]]=max(max(a,b),Get(a,b));
		res[i]=zj[y[i]].first;
	}
	for(int i=1;i<=n-1;i++) printf("%d\n",res[i]);
	return 0;
}
