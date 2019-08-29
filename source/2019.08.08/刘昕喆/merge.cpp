#include<bits/stdc++.h>
using namespace std;
vector<int> m[6001];
int a[6001];bool vis[6001];
void dfs(int now,int add)
{
	a[now]+=add;
	vis[now]=1;
	for(int i=0;i<m[now].size();i++)
	{
		if(vis[m[now][i]]==0)	dfs(m[now][i],add);
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			m[x].push_back(y);
			m[y].push_back(x);
		}
		if(op==2)
		{
			memset(vis,0,sizeof(vis));
			dfs(x,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

