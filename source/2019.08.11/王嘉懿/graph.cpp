#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m,q,a[1001][1001]={9999999},vis[1001],ans[1001],x,y,z;
vector <int > nex[1001];
void dfs(int u,int jl)
{
	if(u==y)
	{
		
	}
	if(vis[u]==0)
	{
       vis[u]=1;
	   	ans[u]=max(ans[u],jl);
	   	for(int i=0;i<nex[u].size();i++)
		   dfs(nex[u][i],a[u][nex[u][i]]);
	}
	
}
int main()
{
	//freopen("graph.in","r",stdin);
	//freopen("graph.out","w",stdout);
	read(n);read(m);read(q);
	for(register int i=1;i<=m;i++)
	{
		read(x);read(y);read(z);
		a[x][y]=a[y][x]=z;
		nex[x].push_back(y);
		nex[y].push_back(x);
	}
	while(q--)
	{
		memset(ans,0,sizeof(ans));
		read(x);read(y);
		vis[x]=0;
		for(register int i=0;i<nex[x].size();i++)
		{
			dfs(nex[x][i],a[x][nex[x][i]]);
		}
	}
}
