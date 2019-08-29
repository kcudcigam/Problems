#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+5;
int U,V,S;
vector<int>G[maxn];
int W[maxn];
bool vis[maxn];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&U,&V,&S);
	for(int i=1;i<=V;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=S;i++){
		int type;
		scanf("%d",&type);
		if(type==0){
			int q;
			scanf("%d",&q);
			printf("%d\n",W[q]);
		}
		if(type==1){
			int q,w;
			scanf("%d%d",&q,&w);
			W[q]+=w;
			for(int j=0;j<G[q].size();j++){
				int ne=G[q][j];
				if(vis[ne]==0){
					vis[ne]=1;
					W[ne]+=w;
				}
			}
			memset(vis,0,sizeof(vis));
		}
	}
	return 0;
}
/*
4 4 4
1 2
1 3
1 4
2 3
1 1 1
0 2
1 3 3
0 2
*/
