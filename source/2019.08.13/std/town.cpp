#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	int f=1,g=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
	return f*g;
}
const int N=300005;
int n,fr[N],depth[N],fa[N][20],u[N],v[N];
vector<int> e[N];
struct node{int x,y;}a[N];
int lca(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	for (int i=18;i>=0;i--) if (depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;i>=0;i--) if (depth[fa[x][i]]>=depth[y]) x=fa[x][i];
	for (int i=18;i>=0;i--)
	if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return depth[x]+depth[y]-depth[lca(x,y)]*2;}
node operator+(node a,node b){
	static int f[4];
	f[0]=a.x,f[1]=a.y,f[2]=b.x,f[3]=b.y;
	int x,y,d=-1;
	for (int i=0;i<4;i++)
	for (int j=i+1;j<4;j++){
		int t=dis(f[i],f[j]);
		if (t>d){d=t;x=f[i];y=f[j];}
	}
	return (node){x,y};
}
void build(int x,int fath){
	depth[x]=depth[fath]+1;fa[x][0]=fath;
	for (int i=1;i<=18;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (auto y : e[x])
	if (y!=fath) build(y,x);
}
int find(int x){return (x==fr[x]) ? x : fr[x]=find(fr[x]);}
void merge(int x,int y){
	x=find(x),y=find(y);
	a[x]=a[x]+a[y];fr[y]=x;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=(node){i,i},fr[i]=i;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	build(1,0);
	for (int i=1;i<n;i++){
		merge(u[i],v[i]);
		int t=find(u[i]);
		printf("%d\n",dis(a[t].x,a[t].y));
	}
	return 0;
}
