#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10;
int H[maxn],N[maxn*2],W[maxn*2],V[maxn*2],fa[maxn],tot=0;
bool vis[maxn];
map<long long,int> ha;
int read(){
	int num=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){num=num*10+c-'0';c=getchar();}
	return num*f;
}
void add(int u,int v,int w){
	V[++tot]=v;W[tot]=w;N[tot]=H[u];H[u]=tot;
}
int st[maxn][35],dis[maxn][35],dep[maxn];
int Gt(int x){
	if(fa[x]==x) return x;
	return fa[x]=Gt(fa[x]);
}
void Merg(int x,int y){
	x=Gt(x);y=Gt(y);
	fa[x]=fa[y];
}
void dfs(int u,int f){
	int i,v,w;
	vis[u]=1;
	st[u][0]=f;
	if(f==0) dis[u][0]=10000000,dep[u]=0;
	else dis[u][0]=ha[u*1000000+f],dep[u]=dep[f]+1;
	for(i=1;i<=20;i++){
		st[u][i]=st[st[u][i-1]][i-1];
		dis[u][i]=max(dis[u][i-1],dis[st[u][i-1]][i-1]);
	}
	for(i=H[u];i;i=N[i]){
		v=V[i];
		if(v!=f) dfs(v,u);
	}
}
int Fid(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int i,len,mi,ans=0;
	len=dep[u]-dep[v];
	for(i=20;i>=0;i--){
		mi=1<<i;
		if(len-mi<0) continue;
		len-=mi;
		ans=max(ans,dis[u][i]);
		u=st[u][i];
		if(len==0) break;
	}
	if(u==v) return ans;
	for(i=20;i>=0;i--){
		if(st[u][i]==st[v][i]) continue;
		ans=max(ans,dis[u][i]);
		ans=max(ans,dis[v][i]);
		u=st[u][i];
		v=st[v][i];
	}
	if(st[u][0]==st[v][0]){
		ans=max(ans,dis[u][0]);
		ans=max(ans,dis[v][0]);
		return ans;
	}
}
struct dge{
	int u,v,w;
}e[maxn];
bool cmp(dge x,dge y){
	return x.w<y.w;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int i,j,u,v,w,n,m,Q,ans;
	n=read(),m=read(),Q=read();
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++) {e[i].u=read();e[i].v=read();e[i].w=read();}
	sort(e+1,e+1+m,cmp);
	for(i=1;i<=m;i++){
		u=e[i].u;v=e[i].v;w=e[i].w;
		if(Gt(u)==Gt(v)) continue;
		Merg(u,v);add(u,v,w);add(v,u,w);
		ha[u*1000000+v]=w;ha[v*1000000+u]=w;
	}
	for(i=1;i<=n;i++){
		if(vis[i]==0) dfs(i,0);
	}
	while(Q--){
		v=read();u=read();
		if(Gt(u)!=Gt(v)) printf("-1\n");
		else{
			ans=Fid(u,v);
			printf("%d\n",ans);
		}
	}
	return 0;
}
