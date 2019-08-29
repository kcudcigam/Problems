#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const ll inf=2e18;
const int N=2e5+5;
const int M=5e5+5;
const int LOG=20;
int n,m,id[M],pp[N],dep[N],par[LOG][N],pre[N],pree[N];
bool vis[M];
ll dis[N],res[N];
vector<int>ex,ey,ez;
vector<pii >G[N];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
//
inline int fF(int x){
	if(pp[x]==x)return x;
	return pp[x]=fF(pp[x]);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=LOG-1;i>=0;i--)if((dep[x]-dep[y])>>i&1){
		x=par[i][x];
	}
	if(x==y)return x;	
	for(int i=LOG-1;i>=0;i--)if(par[i][x]!=par[i][y]){
		x=par[i][x];
		y=par[i][y];
	}
	return par[0][x];
}
bool cmp(int x,int y){
	return dis[ex[x]]+dis[ey[x]]+1ll*ez[x]<dis[ex[y]]+dis[ey[y]]+1ll*ez[y];
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num=getint();
	n=getint();m=getint();
	rep(i,m){
		int x=getint()-1,y=getint()-1,z=getint();
		ex.push_back(x);
		ey.push_back(y);
		ez.push_back(z);
		G[x].push_back(mp(y,i));
		G[y].push_back(mp(x,i));
	}
	pre[0]=-1;
	pree[0]=-1;
	rep(i,n)dis[i]=inf;
	dis[0]=0ll;
	pq.push(mp(0ll,0));
	while(!pq.empty()){
		pair<ll,int>u=pq.top();pq.pop();
		if(u.first>dis[u.second])continue;
		///vis[u.second]=true;
		rep(i,G[u.second].size()){
			int to=G[u.second][i].first,d=G[u.second][i].second;
			if(dis[to]>dis[u.second]+1ll*ez[d]){
				dis[to]=dis[u.second]+1ll*ez[d];
				pree[to]=d;
				pre[to]=u.second;
				dep[to]=dep[u.second]+1;
				pq.push(mp(dis[to],to));
			}
		}
	}
	memset(vis,0,sizeof(vis));
	par[0][0]=-1;
	for(int i=1;i<n;i++){
		if(dis[i]==inf)par[0][i]=-1;
		else{
			par[0][i]=pre[i];
			vis[pree[i]]=true;
		}
	}
	rep(i,LOG-1)rep(j,n){
		if(par[i][j]==-1)par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}
	rep(i,m)id[i]=i;
	rep(i,n)pp[i]=i;
	sort(id,id+m,cmp);
	memset(res,-1,sizeof(res));
	//rep(i,n)cout<<i<<" "<<pre[i]<<" "<<pree[i]<<" "<<dis[i]<<endl;
	rep(ii,m){
		int i=id[ii];
		if(vis[i]||dis[ex[i]]==inf)continue;
		int z=lca(ex[i],ey[i]);
		int x=fF(ex[i]),y=fF(ey[i]);
		ll val=dis[ex[i]]+dis[ey[i]]+1ll*ez[i];
	//	cout<<ex[i]<<" "<<ey[i]<<" "<<z<<endl;
		while(dep[x]>dep[z]){
			res[x]=val-dis[x];
			int to=fF(pre[x]);
			pp[x]=to;x=to;
		//	cout<<x<<endl;
		}
		while(dep[y]>dep[z]){
			res[y]=val-dis[y];
			int to=fF(pre[y]);
			pp[y]=to;y=to;
		//	cout<<y<<endl;
		}
	}
	printf("%d ",0);
	for(int i=1;i<n;i++){
		if(dis[i]==inf){
			printf("%d ",-1);
			continue;
		}
		printf("%lld ",res[i]);
	}
	cout<<endl;
	//cout<<dis[3]<<endl;
	return 0;
}
