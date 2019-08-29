#include<bits/stdc++.h>
#define N 300010
#define D 25
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,m,q;
int f[N];
int fa[N][D];
int dis[N][D];
int h[N];
int step[N];
struct side{
	int u,v,w;
};
side c[N];
struct node{
	int v,w,last;
};
node s[N<<1];
int len,head[N];
int par(int x){
	if (f[x]==x) return x;
	f[x]=par(f[x]);
	return f[x];
}
bool cmp(side x,side y){
	return x.w<y.w;
}
void put(int x,int y,int z){
	s[++len].v=y;
	s[len].w=z;
	s[len].last=head[x];
	head[x]=len;
	return;
}
void dfs(int g,int p){
	f[p]=g;
	for (int i=head[p];i;i=s[i].last){
		if (fa[p][0]!=s[i].v){
			step[s[i].v]=step[p]+1;
			fa[s[i].v][0]=p;
			dis[s[i].v][0]=s[i].w;
			for (int j=1;fa[s[i].v][j-1];j++,h[s[i].v]++){
				fa[s[i].v][j]=fa[fa[s[i].v][j-1]][j-1];
				dis[s[i].v][j]=max(dis[s[i].v][j-1],dis[fa[s[i].v][j-1]][j-1]);
			}
			dfs(g,s[i].v);
		}
	}
	return;
}
void solve(int x,int y){
	if (f[x]!=f[y]){
		puts("-1");
		return;
	}
	int res=0;
	if (step[x]<step[y]) swap(x,y);
	int k=step[x]-step[y],t=0;
	while (k){
		if (k&1){
			res=max(res,dis[x][t]);
			x=fa[x][t];
		}
		++t;
		k>>=1;
	}
	if (x==y){
		printf("%d\n",res);
		return;
	}
	for (int i=h[x];i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			res=max(res,dis[x][i]);
			res=max(res,dis[y][i]);
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	res=max(res,dis[x][0]);
	res=max(res,dis[y][0]);
	printf("%d\n",res);
	return;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);read(m);read(q);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		read(c[i].u);
		read(c[i].v);
		read(c[i].w);
	}
	sort(c+1,c+m+1,cmp);
	for (int i=1;i<=m;i++){
		if (par(c[i].u)!=par(c[i].v)){
			f[par(c[i].u)]=par(c[i].v);
			put(c[i].u,c[i].v,c[i].w);
			put(c[i].v,c[i].u,c[i].w);
		}
	}
	for (int i=1;i<=n;i++)
		if (f[i]==i) dfs(i,i);
	while (q--){
		int x,y;
		read(x);read(y);
		solve(x,y);
	}
	return 0;
}

