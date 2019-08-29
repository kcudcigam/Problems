#include<bits/stdc++.h>
#define N 600010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
struct Info{int nu,ne,qu;}a[N*2];
struct edge{int x,y,z;}e[N];
int num,m,n,q,b[N],f[N],d[N],ft[N][22],ma[N][22],x,y;
bool vi[N];
bool c1(const edge &a,const edge &b){return a.z<b.z;}
void jb(int x,int y,int z){
	a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].qu=z;
	a[++num].nu=x;a[num].ne=b[y];b[y]=num;a[num].qu=z;
}
int que(int x){if (f[x]!=x) f[x]=que(f[x]);return f[x];}
void dfs(int x,int fa,int dep){
	ft[x][0]=fa;d[x]=dep;vi[x]=0;
	for (int y=b[x];y;y=a[y].ne)if (vi[a[y].nu]){dfs(a[y].nu,x,dep+1);ma[a[y].nu][0]=a[y].qu;}
}
int lca(int x,int y){
	int an=0;
	if (d[x]<d[y]) swap(x,y);
	for (int i=18;i>=0;i--)if (d[ft[x][i]]>=d[y]){an=max(an,ma[x][i]);x=ft[x][i];}
	for (int i=18;i>=0;i--){
		if (ft[x][i]!=ft[y][i]){an=max(an,max(ma[x][i],ma[y][i]));x=ft[x][i];y=ft[y][i];}
	}
	if (x!=y){an=max(an,max(ma[x][0],ma[y][0]));x=ft[x][0];y=ft[y][0];}
	return an;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);read(m);read(q);
	for (int i=1;i<=m;i++){read(e[i].x);read(e[i].y);read(e[i].z);}
	for (int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+m+1,c1);
	for (int i=1;i<=m;i++){
		int nx=que(e[i].x),ny=que(e[i].y);
		if (f[nx]!=ny){f[nx]=ny;jb(e[i].x,e[i].y,e[i].z);}
	}
	for (int i=1;i<=n;i++)vi[i]=1;
	for (int i=1;i<=n;i++)if(vi[i])dfs(i,0,1);
	for (int i=2,j=1;i<=n;i*=2,j++)
		for (int k=1;k<=n;k++){ft[k][j]=ft[ft[k][j-1]][j-1];ma[k][j]=max(ma[k][j-1],ma[ft[k][j-1]][j-1]);}
	for (int i=1;i<=q;i++){
		read(x);read(y);
		if (que(x)!=que(y))puts("-1");
		else printf("%d\n",lca(x,y));
	}
	return 0;
}
