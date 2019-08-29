#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define clear(a) memset(a,0,sizeof(a))
using namespace std;
const int N=300005;
int n,m,q,cnt;
int head[N],nxt[N],to[N],w[N],Max,fa[N];
bool vis[N];
//bool Neko(int a,int b) {return w[a]<w[b];}
priority_queue<int>Q;
void Add(int a,int b,int len){
	nxt[++cnt]=head[a];head[a]=cnt;nxt[cnt]=b;w[cnt]=len;
}
int fd(int x){return x==fa[x]?x:fd(fa[x]);}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
bool Gao(int x,int y){
	x=fd(x),y=fd(y);
	return x==y?1:0; 
}//ÅĞÁªÍ¨ 
void dfs1(int x,int Fa){
	for(int i=head[x];i;i=nxt[i]) {
		int u=to[i];
		if(u==Fa) continue; 
	    dfs1(u,x);fa[u]=x;
	}
 }
int dfs2(int x,int y,int ans){
	if(x==y) {
		Q.push(Max);return 0;
	}
	for(int i=head[x];i;i=nxt[i]){
		int u=to[i];
		Max=max(Max,dfs2(u,y,ans+w[u]));
	}
	return w[x];
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=ip(),m=ip(),q=ip();
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) {int u=ip(),v=ip(),w=ip();Add(u,v,w);Add(v,u,w);}
	dfs1(1,0);
	while(q--){
		while(!Q.empty()) Q.pop();Max=0;
		int x=ip(),y=ip();
		if(!Gao(x,y)) {puts("-1");continue;}
		dfs2(x,y,0);
		printf("%d\n",Q.top());
	}
	return 0;
}


