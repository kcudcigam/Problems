#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
queue<int> Q;
int nt[5002],fir[5002],p[5002],value[5002];
int tot;
int dis[2002][2002],das[2002][2002];
int n,m,q,u,v,w;
void Add(int u,int v,int w){
	nt[++tot] = fir[u];
	fir[u] = tot;
	p[tot] = v;
	value[tot] = w;
}
void spfa(int s,int x){
	Q.push(x);
	while (!Q.empty() ){
		x = Q.front() ;
		Q.pop() ;
		for (int i = fir[x]; i; i = nt[i]){
			int y = p[i];
			int z = value[i];
			if (das[s][y]){
				if (das[s][y] > min(das[s][y],max(das[s][x],z))){
					das[s][y] = min(das[s][y],max(das[s][x],z));
					Q.push(y);
				}
			}
			else{
				das[s][y] = max(das[s][x],z);
				Q.push(y);
			}
		}
	} 
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= m; ++ i){
		scanf("%d%d%d",&u,&v,&w);
		Add(u,v,w);
		Add(v,u,w);
	}
	memset(das,0,sizeof(das));
	for (int i = 1; i <= n; ++ i){
		spfa(i,i);
	}
	for (int i = 1; i <= q; ++ i){
		scanf("%d%d",&u,&v);
		if (das[u][v])
			printf("%d\n",das[u][v]);
		else
			printf("-1\n");
	}
	return 0;
}
