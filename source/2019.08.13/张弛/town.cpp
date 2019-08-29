#include<bits/stdc++.h>
using namespace std;
const int N=310000,M=21;
vector<int> a[N];
struct edge{
	int x,y;
}e[N];
struct node{
	int fa,x,y,d;
}b[N];
int f[N][M],dep[N];
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
int dfs(int u,int fu){
	f[u][0]=fu,dep[u]=dep[fu]+1;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v!=fu) dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int fid(int x){
	if(x==b[x].fa) return x;
	return b[x].fa=fid(b[x].fa);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		e[i]=(edge){x,y};
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for(int i=1;i<=n;i++)
		b[i]=(node){i,i,i,0};
	for(int i=1;i<n;i++){
		int x=e[i].x,y=e[i].y;
		int fx=fid(x),fy=fid(y);
		node &u=b[fx],&v=b[fy],t=b[fx];
		v.fa=fx;
		if(v.d>u.d) u=(node){fx,v.x,v.y,v.d};
		int d=dis(t.x,v.x);
		if(d>u.d) u=(node){fx,t.x,v.x,d};
		d=dis(t.x,v.y);
		if(d>u.d) u=(node){fx,t.x,v.y,d};
		d=dis(t.y,v.x);
		if(d>u.d) u=(node){fx,t.y,v.x,d};
		d=dis(t.y,v.y);
		if(d>u.d) u=(node){fx,t.y,v.y,d};
		cout<<u.d<<"\n";
	}
	return 0;
}
