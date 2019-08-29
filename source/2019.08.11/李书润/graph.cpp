#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x,y,z;
}e[300001];
int const inf=1e9+7;
int f[300001][20],g[300001][20],deep[300001],target[600001],pre[600001],last[600001],w[600001],tot,fa[600001];
bool visited[300001];
inline int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
inline bool cmp(edge x,edge y)
{
	return x.z<y.z;
}
inline void add(int x,int y,int z)
{
	target[++tot]=y;
	pre[tot]=last[x];
	last[x]=tot;
	w[tot]=z;
}
void dfs(int x)
{
	visited[x]=1;
	for(int i=last[x];i;i=pre[i])
	{
		int tar=target[i];
		if(!visited[tar])
		{
			f[tar][0]=x;
			g[tar][0]=w[i];
			deep[tar]=deep[x]+1;
			dfs(tar);
		}
	}
}
inline int mmax(int x,int y)
{
	return x>y?x:y;
}
inline int query(int x,int y)
{
	int ans=0;
	if(deep[x]<deep[y])swap(x,y);
	for(register int k=19;k>=0;--k)if(deep[f[x][k]]>=deep[y])ans=mmax(ans,g[x][k]),x=f[x][k];
	if(x==y)return ans;
	for(register int k=19;k>=0;--k)if(f[x][k]!=f[y][k])ans=mmax(ans,mmax(g[x][k],g[y][k])),x=f[x][k],y=f[y][k];
	ans=mmax(ans,g[x][0]);
	return ans;
}
void read_(int &x)
{
	int f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	register int n,m,q,x,y;
	read_(n),read_(m),read_(q);
	for(register int i=1;i<=m;++i)read_(e[i].x),read_(e[i].y),read_(e[i].z);
	sort(e+1,e+m+1,cmp);
	for(register int i=1;i<=n;++i)fa[i]=i;
	for(register int i=1;i<=m;++i)
	{
		register int fx=find(e[i].x),fy=find(e[i].y);
		if(fx!=fy)fa[fx]=fy,add(e[i].x,e[i].y,e[i].z),add(e[i].y,e[i].x,e[i].z);
	}
	for(register int i=1;i<=n;++i)if(!visited[i])dfs(i);
	for(register int k=1;k<=19;++k)
		for(register int i=1;i<=n;++i)
			f[i][k]=f[f[i][k-1]][k-1],g[i][k]=max(g[i][k-1],g[f[i][k-1]][k-1]);
	for(register int i=1;i<=q;++i)
	{
		read_(x),read_(y);
		if(find(x)!=find(y))printf("-1\n");
		else printf("%d\n",query(x,y));
	}
	return 0;
}
