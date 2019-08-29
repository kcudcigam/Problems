#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100+(3e5);
const int M=100+(6e5);

int n,x,y;
int a[N],b[N];
int fa[N],c[N],d[N],e[N];
int tot,sta[N],v[M],nxt[M];
int dep[N],lca[N][20];
int f,g,h;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void addedge(int x,int y){
	v[++tot]=y;nxt[tot]=sta[x];sta[x]=tot;
}

void dfs(int x,int f,int d){
	lca[x][0]=f;dep[x]=d;
	for (int i=1;i<=18;++i) lca[x][i]=lca[lca[x][i-1]][i-1];
	for (int i=sta[x];i>0;i=nxt[i])
		if (v[i]!=f) dfs(v[i],x,d+1);
}

int getfa(int x){
	fa[x]=(fa[x]==x)?x:getfa(fa[x]);
	return fa[x];
}

int getdis(int x,int y){
	int ans=dep[x]+dep[y];
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=18;i>=0;--i)
		if (dep[lca[x][i]]>=dep[y]) x=lca[x][i];
	if (x==y) return (ans-(dep[x]<<1));
	for (int i=18;i>=0;--i)
		if (lca[x][i]!=lca[y][i]){
			x=lca[x][i];
			y=lca[y][i];
		}
	return (ans-(dep[lca[x][0]]<<1));
}

void Add(int x,int u,int v,int w){
	if (w>h){
		f=u;g=v;h=w;
	}
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=rd();
	tot=0;
	memset(sta,0,sizeof(sta));
	for (int i=1;i<n;++i){
		a[i]=rd();b[i]=rd();
		addedge(a[i],b[i]);
		addedge(b[i],a[i]);
	}
	
	for (int i=0;i<=18;++i) lca[0][i]=0;
	dep[0]=0;
	dfs(1,0,1);
	
	for (int i=1;i<=n;++i){
		fa[i]=c[i]=d[i]=i;e[i]=0;
	}
	
	for (int i=1;i<n;++i){
		x=a[i];y=b[i];
		x=getfa(x);y=getfa(y);
		fa[y]=x;
		f=c[x];g=d[x];h=e[x];
		Add(x,c[y],d[y],e[y]);
		Add(x,c[x],c[y],getdis(c[x],c[y]));
		Add(x,c[x],d[y],getdis(c[x],d[y]));
		Add(x,d[x],c[y],getdis(d[x],c[y]));
		Add(x,d[x],d[y],getdis(d[x],d[y]));
		cout<<h<<'\n';
		c[x]=f;d[x]=g;e[x]=h;
	}
	return 0;
}
