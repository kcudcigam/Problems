#include<bits/stdc++.h>
using namespace std;
int n,f[300002],ans,u,v,ltk[300002],ff[300002];
vector <int> g[300002];
void dfs(int x)
{
	ltk[x]++;
	ff[x]=1;
	for(int i=0;i<g[x].size();i++) if(ff[g[x][i]]==0) dfs(g[x][i]);
}
void duck(int akioi,int ac)
{

	if(akioi>ans) ans=akioi;
	f[ac]=1;
	for(int i=0;i<g[ac].size();i++)
	{
		if(f[g[ac][i]]==0) duck(akioi+1,g[ac][i]);
	}	
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n-1;i++)
 	{
 		scanf("%d%d",&u,&v);
 		g[u].push_back(v);g[v].push_back(u);
 		if(i==1) cout<<1<<endl;
 		else
 		{
 			memset(ff,0,sizeof(ff));
 			memset(ltk,0,sizeof(ltk));
 			dfs(u);
 			for(int j=1;j<=n;j++)
 			{
			 	memset(f,0,sizeof(f));
 				if(f[j]==0&&ltk[j]==1)duck(0,j);	
			}	
			printf("%d\n",ans);
			ans=0;
		}
	}
	return 0;
}


