#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
#define iiii pair<int,pii >
#define INF 1000000000
#define MOD 1000000007
#define ll long long
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=5e5+5;
int n,q,cnt,c;
bool vis[N<<1];
int par[N<<1],pp[N<<1],tag[N<<1],res[N<<1],h[N<<1],nxt[N<<1],to[N<<1];
//
inline void addedge(int x,int y){
	++c;
	to[c]=y;
	nxt[c]=h[x];
	h[x]=c;
}
inline int fF(int x){
	if(par[x]==x)return x;
	return par[x]=fF(par[x]);
}
void solve(int x){
	for(int i=h[x];i;i=nxt[i]){
	//	assert(par[G[x][i]]!=G[x][i]);
		tag[to[i]]+=tag[x];
		res[to[i]]+=res[x];
		solve(to[i]);
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	n=getint();q=getint();cnt=n;
	rep(i,n)par[i]=i;
	memset(pp,-1,sizeof(pp));
	rep(qqq,q){
		int op=getint(),x=getint()-1,y=getint()-1;
		if(op==1){
			int xx=fF(x),yy=fF(y);
			if(xx==yy)continue;
			int now=cnt++;
			par[now]=now;
			par[xx]=par[yy]=now;
			pp[xx]=pp[yy]=now;
		}
		else{
			int xx=fF(x);++y;
			//cout<<xx<<" "<<ls[xx]<<" "<<rs[xx]<<endl;
			res[xx]+=y;
			tag[xx]+=y;
		}
	}
	//cout<<cnt<<endl;
	//return 0;
	rep(i,cnt)if(pp[i]!=-1)addedge(pp[i],i);
	rep(i,cnt)if(fF(i)==i)solve(i);
	rep(i,n)printf("%d ",res[i]);
	return 0;
}


