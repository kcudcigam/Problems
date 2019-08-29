#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=300005;
int f[maxn];
int find(int x)
{
	return (f[x]==x)?x:f[x]=find(f[x]);
}
int maxl[maxn];
int lne[maxn];
int fst[maxn];
int nxt[maxn<<1];
int v[maxn<<1];
int edge;
void add(int x,int y)
{
	edge++;
	nxt[edge]=fst[x];
	fst[x]=edge;
	v[edge]=y;
}
void dfs(int x,int pre,int val)
{

	if(lne[x]<val)lne[x]=val;
	for(int i=fst[x];i;i=nxt[i])
	{
		if(v[i]==pre)continue;
		dfs(v[i],x,val+1);
	}
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		f[fx]=fy;
		maxl[fy]=max(maxl[fx],max(maxl[fy],1+lne[x]+lne[y]));
		printf("%d\n",maxl[fy]);
		int bfx=lne[x],bfy=lne[y];
		dfs(x,0,bfy+1);
		dfs(y,0,bfx+1);
		add(x,y);
		add(y,x);
	}
}
