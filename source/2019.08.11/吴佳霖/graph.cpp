#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+5,INF=0x3f3f3f3f;
struct node{
	int D;
	int W;
};
vector<node>G[maxn];
bool vis[maxn];
int dis[maxn];
int N,M,Q;
int ans;
void dfs(int qi,int zh){
	if(qi==zh){ans=min(ans,dis[zh]);return;}
	for(int i=0;i<(int)G[qi].size();i++){
		int ne=G[qi][i].D;
		if(!vis[ne]){
			vis[ne]=1;
			dis[ne]=max(dis[qi],G[qi][i].W);
			dfs(ne,zh);
			vis[ne]=0;
		}
	}
	return;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=1;i<=M;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		node x;
		x.D=v;
		x.W=w;
		G[u].push_back(x);
		x.D=u;
		G[v].push_back(x);
	}
	for(int i=1;i<=Q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		ans=INF;
		vis[x]=1;
		dfs(x,y);
		vis[x]=0;
		if(ans==INF)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
/*
5 5 4
1 2 3
1 3 2
3 2 1
1 4 5
2 4 4
1 2
1 4
3 5
2 4
*/

