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
const int N=3e5+5;
const int LOG=20;
bool vis[N];
int n,m,q,par[LOG][N],mx[LOG][N];
int ex[N],ey[N],ez[N],id[N],pp[N],dep[N];
vector<pii >G[N];
//
bool cmp(int x,int y){
	return ez[x]<ez[y];
}
int fF(int x){
	if(pp[x]==x)return x;
	return fF(pp[x]);
}
bool fU(int x,int y){
	x=fF(x);y=fF(y);
	if(x==y)return false;
	pp[x]=y;
	return true;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int ans=0;
	for(int i=LOG-1;i>=0;i--)if((dep[x]-dep[y])>>i&1){
		ans=max(ans,mx[i][x]);
		x=par[i][x];
	}
	if(x==y)return ans;
	for(int i=LOG-1;i>=0;i--)if(par[i][x]!=par[i][y]){
		ans=max(ans,max(mx[i][x],mx[i][y]));
		x=par[i][x];
		y=par[i][y];
	}
	ans=max(ans,max(mx[0][x],mx[0][y]));
	return ans;
}
void dfs(int x,int p,int d,int len){
	par[0][x]=p;
	dep[x]=d;
	mx[0][x]=len;
	rep(i,G[x].size()){
		int to=G[x][i].first,l=G[x][i].second;
		if(to==p)continue;
		dfs(to,x,d+1,l);
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=getint();m=getint();q=getint();
	rep(i,m){
		int x=getint()-1,y=getint()-1,z=getint();
		ex[i]=x;ey[i]=y;ez[i]=z;
		id[i]=i;
	}
	sort(id,id+m,cmp);
	rep(i,n)pp[i]=i;
	rep(ii,m){
		int i=id[ii];
		if(!fU(ex[i],ey[i]))continue;
		G[ex[i]].push_back(mp(ey[i],ez[i]));
		G[ey[i]].push_back(mp(ex[i],ez[i]));
	}
	rep(i,n)if(pp[i]==i)dfs(i,-1,0,0);
	rep(i,LOG-1)rep(j,n){
		if(par[i][j]==-1)par[i+1][j]=-1;
		else{
			mx[i+1][j]=max(mx[i][j],mx[i][par[i][j]]);
			par[i+1][j]=par[i][par[i][j]];
		}
	}
	rep(qqq,q){
		int x=getint()-1,y=getint()-1;
		if(fF(x)!=fF(y))printf("%d\n",-1);
		else printf("%d\n",lca(x,y));
	}
	return 0;
}
