#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define REP(i,x) for(int i=head[x];i;i=nxt[i])
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m,q;

int ldf[N],cnt,head[N],nxt[N],to[N],siz[N];
void Add(int a,int b,int len){
	nxt[++cnt]=head[a];head[a]=cnt;to[cnt]=b;siz[cnt]=len;
}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
namespace _3_1pts{
	const int M=3005;
	bool vis[M][M];
	void NewAdd(int a,int b,int len){
		nxt[++cnt]=head[a];head[a]=cnt;to[cnt]=b;siz[cnt]=len;
		vis[a][b]=vis[b][a]=1;
	}
	void Modify(int x,int y){
	    REP(i,1){
	    	int u=to[i];
	    	if(vis[u][x]||vis[x][u]) siz[u]+=y;
		}
    }
}

namespace _1_7pts{
	void Modify(int x,int y){
		REP(i,1) if(to[i]==x){siz[to[i]]+=y;}
		siz[to[x]]+=y;
	}
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=ip(),m=ip(),q=ip();
	rep(i,1,m){int x=ip(),y=ip();if(n<=3000&&m<=3000) _3_1pts::NewAdd(x,y,0);else Add(x,y,0);}
	while(q--){
		int opt=ip();
		if(opt==0) printf("%d\n",siz[ip()]);
		if(opt==1) {int x=ip(),y=ip();if(n<=3000&&m<=3000)_3_1pts::Modify(x,y);else _1_7pts::Modify(x,y);}
	}
	return 0;
}


