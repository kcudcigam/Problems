#include<bits/stdc++.h>
using namespace std;
const int MAXN=300000+5;
vector <int> edge[MAXN];
int n,len,u;
void dfs(int pos,int dep,int fa)
{
	if(dep>len)
	{
		len=dep;
		u=pos;
	}
	for(int i=0;i<edge[pos].size();i++)
	{
		int v=edge[pos][i];
		if(v==fa)
			continue;
		dfs(v,dep+1,pos);
	}
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
		len=-1;
		dfs(x,0,-1);
		dfs(u,0,-1);
		printf("%d\n",len);
	}
	return 0;
}
