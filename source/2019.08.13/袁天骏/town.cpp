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
const int N=300010;
const int LOG=20;
int n,dep[N],pp[N],res[N],pos[N][2],par[LOG][N];
vector<int>ex,ey,G[N];
//
int fF(int x){
	if(pp[x]==x)return x;
	return pp[x]=fF(pp[x]);
}
void init(int x,int p,int d){
	dep[x]=d;
	par[0][x]=p;
	rep(i,G[x].size()){
		int to=G[x][i];
		if(to==p)continue;
		init(to,x,d+1);
	}
}
inline int lca(int x,int y){
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
inline int getdis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=getint();
	rep(i,n-1){
		int x=getint()-1,y=getint()-1;
		G[x].push_back(y);
		G[y].push_back(x);
		ex.push_back(x);
		ey.push_back(y);
	}
	rep(i,n)pp[i]=i;
	rep(i,n)rep(j,2)pos[i][j]=i;
	init(0,-1,0);
	rep(i,LOG-1)rep(j,n){
		if(par[i][j]==-1)par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}
	rep(ii,n-1){
		int x=fF(ex[ii]),y=fF(ey[ii]);
		pp[x]=y;
		int ans=res[x],ansx=pos[x][0],ansy=pos[x][1];
		if(res[y]>ans){
			ans=res[y];
			ansx=pos[y][0];
			ansy=pos[y][1];
		}
		rep(i,2)rep(j,2){
			int len=getdis(pos[x][i],pos[y][j]);
			if(len>ans){
				ans=len;
				ansx=pos[x][i];
				ansy=pos[y][j];
			}
		}
		pos[y][0]=ansx;
		pos[y][1]=ansy;
		printf("%d\n",ans);
		res[y]=ans;
	}
	return 0;
}
