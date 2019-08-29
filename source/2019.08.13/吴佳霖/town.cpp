#include<bits/stdc++.h>
using namespace std;
int N;
int d[300000+5];
bool vis[300000+5];
vector<int>G[300000+5];
int h,s;
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<G[x].size();i++){
		int t=G[x][i];
		if(!vis[t]){
			d[t]=d[x]+1;
			if((d[t])>h){h=d[t];s=G[x][i];}
			dfs(t);
			d[t]=0;
		}
	}
	vis[x]=0;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		h=0;
		dfs(x);
		h=0;
		dfs(s);
		printf("%d\n",h);
	}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/
