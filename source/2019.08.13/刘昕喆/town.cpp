#include<bits/stdc++.h>
using namespace std;
vector<int> m[300001];
bool vis[300001];
int dfs(int Node)
{
	int ans=0;
	for(int i=0;i<m[Node].size();i++)
	{
		if(vis[m[Node][i]]==0)
		{
			vis[m[Node][i]]=1;
			ans=max(ans,dfs(m[Node][i])+1);
		}
	}
	return ans;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		int u,v;
		scanf("%d%d",&u,&v);
		m[u].push_back(v);
		m[v].push_back(u);
		vis[u]=1;
		vis[v]=1;
		cout<<dfs(u)+dfs(v)+1<<endl;
	}
	return 0;
}

