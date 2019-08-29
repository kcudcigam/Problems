#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
const int MAXN=3e5+10;
int n,fa[MAXN],fir[MAXN],cnt,nxt[MAXN<<1],to[MAXN<<1],siz[MAXN],dep[MAXN],po1[MAXN],po2[MAXN],anc[MAXN][20];
inline void ins(int x,int y){nxt[++cnt]=fir[x],to[cnt]=y,fir[x]=cnt;}
inline int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
inline void dfs(int x,int pa){
	dep[x]=dep[pa]+1,anc[x][0]=pa;;
	for(int i=1;i<20;i++)anc[x][i]=0;
	for(int i=1;i<20;i++){
		if(dep[x]<=(1<<i))break;
		else anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=fir[x];i;i=nxt[i])if(to[i]!=pa) dfs(to[i],x);
}
inline int lca(int x,int y){
	if(x==y)return x;
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	for(int i=19;~i;--i)
		if(t&(1<<i))x=anc[x][i];
	if(x==y)return x;
	for(int i=19;~i;--i)
		if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1,dep[i]=1,po1[i]=po2[i]=i;
	for(int i=1,x,y;i<n;i++){
		x=read(),y=read(),ins(x,y),ins(y,x);
		int fx=getfa(x),fy=getfa(y);
		if(siz[fx]>siz[fy]) swap(x,y),swap(fx,fy);
		dfs(x,y);int tmp=0,p,pp;
		if(dep[po1[fx]]+dep[po2[fx]]-2*dep[lca(po1[fx],po2[fx])]>tmp){
			tmp=dep[po1[fx]]+dep[po2[fx]]-2*dep[lca(po1[fx],po2[fx])];
			p=po1[fx],pp=po2[fx];
		}
		if(dep[po1[fy]]+dep[po2[fy]]-2*dep[lca(po1[fy],po2[fy])]>tmp){
			tmp=dep[po1[fy]]+dep[po2[fy]]-2*dep[lca(po1[fy],po2[fy])];
			p=po1[fy],pp=po2[fy];
		}
		if(dep[po1[fx]]+dep[po1[fy]]-2*dep[lca(po1[fx],po1[fy])]>tmp){
			tmp=dep[po1[fx]]+dep[po1[fy]]-2*dep[lca(po1[fx],po1[fy])];
			p=po1[fx],pp=po1[fy];
		}
		if(dep[po1[fx]]+dep[po2[fy]]-2*dep[lca(po1[fx],po2[fy])]>tmp){
			tmp=dep[po1[fx]]+dep[po2[fy]]-2*dep[lca(po1[fx],po2[fy])];
			p=po1[fx],pp=po2[fy];
		}
		if(dep[po2[fx]]+dep[po1[fy]]-2*dep[lca(po2[fx],po1[fy])]>tmp){
			tmp=dep[po2[fx]]+dep[po1[fy]]-2*dep[lca(po2[fx],po1[fy])];
			p=po2[fx],pp=po1[fy];
		}
		if(dep[po2[fx]]+dep[po2[fy]]-2*dep[lca(po2[fx],po2[fy])]>tmp){
			tmp=dep[po2[fx]]+dep[po2[fy]]-2*dep[lca(po2[fx],po2[fy])];
			p=po2[fx],pp=po2[fy];
		}
		printf("%d\n",tmp);po1[fy]=p,po2[fy]=pp;
		fa[fx]=fy,siz[fy]+=siz[fx];
	}
	return 0;
}
