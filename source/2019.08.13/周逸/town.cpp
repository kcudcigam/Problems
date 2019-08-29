#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n,ans,root;
int dep[maxn];
struct node{
	int u,v;
}road[maxn];
vector<int>G[maxn];
void dfs(int u,int anc){
	dep[u]=dep[anc]+1;
	int i,v;
	for(i=0;i<G[u].size();i++){
		v=G[u][i];
		if(v==anc)
			continue;
		dfs(v,u);
	}
	if(dep[u]>ans){
		ans=dep[u];
		root=u;
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	int i,u,v;
	if(n<=2000){
		for(i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			dep[u]=0;
			dfs(u,u);
			dep[root]=0;
			dfs(root,root);
			printf("%d\n",ans-1);
			ans=0;
		}
		return 0;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		dep[v]=dep[u]+1;
		ans=max(ans,dep[v]);
		printf("%d\n",ans);
	}
	return 0;
}

 nbb
