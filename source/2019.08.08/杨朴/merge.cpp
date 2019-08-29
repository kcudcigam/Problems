#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+5;
int n,Q,fa[MAXN],add[MAXN],ans[MAXN];
vector <int> edge[MAXN];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())	if(c=='-')	f=-f;
	for(;isdigit(c);c=getchar())	x=x*10+c-'0';
	x=x*f;
}
int getf(int x)
{
	return x==fa[x]?fa[x]:fa[x]=getf(fa[x]);
}
void add_edge(int x,int y)
{
	int fx=getf(x),fy=getf(y);
	if(fx==fy)
		return;
	fa[fy]=fx;
	edge[x].push_back(y);
	edge[y].push_back(x);
}
void dfs(int pos,int x,int fa)
{
	ans[pos]+=x;
	for(int i=0;i<edge[pos].size();i++)
	{
		int to=edge[pos][i];
		if(to==fa)
			continue;
		dfs(to,x,pos);
	}
	return;
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(Q);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=Q;i++)
	{
		int opt,x,y;
		read(opt),read(x),read(y);
		if(opt==1)
			add_edge(x,y);
		else
			dfs(x,y,0);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
