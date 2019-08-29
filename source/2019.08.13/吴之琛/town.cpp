#include<bits/stdc++.h>
#define N 300010
#define D 22
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
struct side{
	int v,last;
};
side c[N<<1];
struct que{
	int u,v;
};
que q[N];
int fa[N][D];
int dep[N],h[N];
bool vis[N];
int n,len;
int head[N];
int f[N];
struct node_ans{
	int u,v,w;
};
node_ans ans[N],res;
void put(int x,int y){
	c[++len].v=y;
	c[len].last=head[x];
	head[x]=len;
	return;
}
void dfs(int p){
	for (int i=head[p];i;i=c[i].last)
		if (!vis[c[i].v]){
			vis[c[i].v]=true;
			dep[c[i].v]=dep[p]+1;
			fa[c[i].v][0]=p;
			for (int j=1;fa[c[i].v][j-1];j++,h[c[i].v]++)
				fa[c[i].v][j]=fa[fa[c[i].v][j-1]][j-1];
			dfs(c[i].v);
		}
	return;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int k=dep[x]-dep[y],t=0;
	while (k){
		if (k&1) x=fa[x][t];
		++t;
		k>>=1;
	}
	if (x==y) return x;
	for (int i=h[x];i>=0;i--)
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
int dis(int x,int y){
	int w=lca(x,y);
	return dep[x]+dep[y]-2*dep[w];
}
int par(int x){
	if (f[x]==x) return x;
	f[x]=par(f[x]);
	return f[x];
}
void check(int x,int y){
	int d=dis(x,y);
	if (res.w<d){
		res.u=x;
		res.v=y;
		res.w=d;
	}
	return;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	for (int i=1;i<n;i++){
		read(q[i].u);
		read(q[i].v);
		put(q[i].u,q[i].v);
		put(q[i].v,q[i].u);
	}
	vis[1]=true;
	dfs(1);
	for (int i=1;i<=n;i++){
		f[i]=i;
		ans[i].u=ans[i].v=i;
	}
	for (int i=1;i<n;i++){
		int k1=par(q[i].u),k2=par(q[i].v);
		if (ans[k1].w>ans[k2].w) res=ans[k1];else res=ans[k2];
		check(ans[k1].u,ans[k2].u);
		check(ans[k1].v,ans[k2].u);
		check(ans[k1].u,ans[k2].v);
		check(ans[k1].v,ans[k2].v);
		f[k2]=k1;
		ans[k1]=res;
		printf("%d\n",res.w);
	}
	return 0;
}

