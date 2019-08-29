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
int cnt,S,n,m,q,deg[N],dat[N],res[N];
vector<int>G[N];
int h[N],nxt[N<<1],to[N<<1];
//
bool cmp(int x,int y){return deg[x]<deg[y];}
inline void addedge(int x,int y){
	++cnt;
	to[cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=getint();m=getint();q=getint();
	S=sqrt(n)+1;
	rep(i,m){
		int x=getint()-1,y=getint()-1;
		if(x==y)continue;
		G[x].push_back(y);
		G[y].push_back(x);
//		deg[x]++;deg[y]++;
	}
	rep(i,n){
		sort(G[i].begin(),G[i].end());
		G[i].resize(unique(G[i].begin(),G[i].end())-G[i].begin());
	}
	rep(i,n)deg[i]=G[i].size();
	rep(i,n){
		sort(G[i].begin(),G[i].end(),cmp);
	}
	rep(i,n)rep(j,G[i].size()){
		addedge(i,G[i][j]);
	}
	rep(qqq,q){
		int op=getint();
		if(op){
			int x=getint()-1,y=getint();
			res[x]+=y;
			if(deg[x]>S)dat[x]+=y;
			else{
				for(int i=h[x];i;i=nxt[i])res[to[i]]+=y;
			}
		}
		else{
			int x=getint()-1,ans=0;
			for(int i=h[x];i;i=nxt[i]){
				if(deg[to[i]]<=S)break;
				ans+=dat[x];
			}
			printf("%d\n",ans+res[x]);
		}
	}
	return 0;
}
