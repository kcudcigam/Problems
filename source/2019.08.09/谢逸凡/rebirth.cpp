#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define REP(i,x) for(int i=head[x];i;i=nxt[i])
#define Rep(i,l,k) for(int i=l;i>=k;i--)
typedef long long ll;
using namespace	std;
const int N=3e5+5;
const int INF=0x3f3f3f3f;
int num,n,m,flag1,flag2;
int head[N],nxt[N],to[N],cnt,del,Vis[N];
ll w[N],dis[N],ans;
bool vis[N];
queue<int>q;
void Add(int a,int b,int v){
	nxt[++cnt]=head[a];head[a]=cnt;to[cnt]=b;w[cnt]=v;
}
void dfs(int x){
	Vis[x]=1;
	REP(i,x){if(!Vis[x]) dfs(to[i]);}
}
void spfa(int s){
	rep(i,1,n) dis[i]=INF;
	q.push(s);vis[s]=1;dis[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u]) continue;
		if(dis[u]>dis[s]+w[u]){
			dis[u]=dis[s]+w[u];
			vis[u]=1;q.push(u);
		}
	}
}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
namespace fifteenpts{
	void Gao(){
		rep(i,1,n){
			 rep(I,1,n) {rep(j,1,I-1) dis[I]+=w[j];}
			 del=max(head[i],nxt[i]);
		     vis[del]=Vis[del]=1;
		     spfa(i);
	         memset(vis,0,sizeof(vis));
		     memset(Vis,0,sizeof(Vis));
		     dfs(1);
		     if(!Vis[i]) flag1=1;
		     if(flag1){printf("-1 ");continue;}
		     printf("%d ",dis[i]);
		}
		rep(i,1,n) if(flag1&&flag2) printf("-1 ");else printf("%d",dis[i]);
	}
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	num=ip(),n=ip(),m=ip();
	rep(i,1,n) dis[i]=INF;
	rep(i,1,m){int x=ip(),y=ip(),len=ip();Add(x,y,len);}
	if(num>=12&&num<=16){
		fifteenpts::Gao();return 0;
	}
	rep(i,1,n){
		if(del==head[i]){
			vis[del]=Vis[del]=1;
	    	spfa(i);
	    	memset(vis,0,sizeof(vis));
	    	memset(Vis,0,sizeof(Vis));
	    	dfs(1);
	    	if(!Vis[i]) flag1=1;
	    	
		}
		if(del==nxt[i]){
			vis[del]=Vis[del]=1;
	    	spfa(i);
	    	memset(vis,0,sizeof(vis));
	    	memset(Vis,0,sizeof(Vis));
	    	dfs(1);
	    	if(!Vis[i]) flag1=1;
		}
		if(flag1&&flag2){printf("-1 ");continue;}
	    	printf("%d ",dis[i]);
	}
	return 0;
}
