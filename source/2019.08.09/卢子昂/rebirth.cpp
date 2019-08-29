#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int Maxn=200000+10;
const int Maxm=500000+10;
int Du[Maxn],vis[Maxn],fate[Maxn],dis[Maxn],Head[Maxn],Next[Maxm],V[Maxm],W[Maxm];
int tot,n,m,num;
queue<int>q;

void spfa(){
	int u,v,w,i;
	for(i=1;i<=n;i++)dis[i]=INF;
	dis[1]=0;vis[1]=1;q.push(1);
	while(!q.empty()){
		u=q.front();q.pop();vis[u]=0;
		for(i=Head[u];i;i=Next[i]){
			v=V[i];w=W[i];
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				fate[u]=i;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}	
			}
		}
	}
}

void Add(int u,int v,int w){
	V[++tot]=v;W[tot]=w;Next[tot]=Head[u];Head[u]=tot;
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int i,j,x,y,len;
	scanf("%d",&num);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&len);
		Add(x,y,len);
		Add(y,x,len);
		Du[y]++;
	}
	
	for(i=1;i<=n;i++)
	spfa();
	printf("0 ");
	for(i=2;i<=n;i++){
		int cnt=INF;
		if(Du[i]==1)printf("-1 ");
		else{
			for(j=Head[i];j;j=Next[j]){
				if(j!=fate[i]){
					cnt=min(cnt,dis[V[j]]+W[V[j]]);
				}
			}
			printf("%d ",cnt);
		}	
	}

	return 0;
}

