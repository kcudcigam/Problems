#include<bits/stdc++.h>
#define rg register
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=3e5+10,INF=0x3f3f3f3f;
struct Edge{int x,y,d;}e[MAXN];
int n,m,Q,fir[MAXN],to[MAXN<<1],nxt[MAXN<<1],v[MAXN<<1],cnt,fa[MAXN],tot,dep[MAXN],anc[MAXN][20],f[MAXN][20];
inline int getfa(int x){return (fa[x]==x)?x:fa[x]=getfa(fa[x]);}
inline void ins(int x,int y,int z){to[++cnt]=y,v[cnt]=z,nxt[cnt]=fir[x],fir[x]=cnt;}
inline bool cmp(Edge a,Edge b){return a.d<b.d;}
inline void dfs(int x,int pa){
	dep[x]=dep[pa]+1,anc[x][0]=pa;
	for(int i=1;i<20;i++)anc[x][i]=anc[anc[x][i-1]][i-1],f[x][i]=max(f[x][i-1],f[anc[x][i-1]][i-1]);
	for(int i=fir[x];i;i=nxt[i])
		if(to[i]!=pa)f[to[i]][0]=v[i],dfs(to[i],x);
}
inline int lca(int x,int y){
	int ans=0;
	if(dep[x]<dep[y])swap(x,y);int t=dep[x]-dep[y];
	for(int i=19;~i;--i)
		if(t&(1<<i))ans=max(ans,f[x][i]),x=anc[x][i];
	if(x==y)return ans;
	for(int i=19;~i;--i)
		if(anc[x][i]!=anc[y][i])ans=max(ans,max(f[x][i],f[y][i])),x=anc[x][i],y=anc[y][i];
	return max(ans,f[x][0]);
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(),m=read(),Q=read();
	for(rg int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].d=read();
	sort(e+1,e+1+m,cmp);
	for(rg int i=1;i<=n;i++)fa[i]=i;
	for(rg int i=1;i<=m;i++){
		if(getfa(e[i].x)!=getfa(e[i].y))ins(e[i].x,e[i].y,e[i].d),ins(e[i].y,e[i].x,e[i].d),fa[getfa(e[i].x)]=getfa(e[i].y),++tot;
		if(tot==n-1)break;
	}
	for(int i=1;i<=n;i++)if(!dep[i])dfs(i,0);
	for(rg int i=1,x,y;i<=Q;i++){
		x=read(),y=read();
		if(getfa(x)!=getfa(y))printf("-1\n");
		else printf("%d\n",lca(x,y));
	}
	return 0;
}
