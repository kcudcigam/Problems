#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pa=pair<ll,int>;
struct edge{int v,w;};basic_string<edge> e;
priority_queue<pa,vector<pa>,greater<pa>> pq;
int n,m,ban[4010],vis[1010];
ll dis[1010];

basic_string<int> v[1010];

void dij(int s){
	memset(dis,0x3f,sizeof dis);dis[s]=0;pq.push({0,s});
	memset(vis,0,sizeof vis);
	while(pq.size()){
		int p;ll d;tie(d,p)=pq.top();pq.pop();
		if(vis[p])continue;vis[p]=1;
		for(int i:v[p])if(!ban[i] && dis[e[i].v]>dis[p]+e[i].w){
			dis[e[i].v]=dis[p]+e[i].w;
			pq.push({dis[e[i].v],e[i].v});
		}
	}
}

int main(){
	freopen("rebirth.in","r",stdin),freopen("rebirth.out","w",stdout);
	scanf("%*d%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		e+={y,w},e+={x,w};
		v[x]+=e.size()-2,v[y]+=e.size()-1;
	}
	for(int i=1;i<=n;i++){
		ll ans=0;
		for(int j:v[i]){
			memset(ban,0,sizeof ban);
			ban[j]=ban[j^1]=1;
			dij(1);
			ans=max(ans,dis[i]);
		}
		printf("%lld%c",ans>1e18?-1ll:ans," \n"[i==n]);
	}
	return 0;
}
