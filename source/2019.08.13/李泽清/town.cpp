#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=600010;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int n;
int to[N],ne[N],st[N],sl,a[N],b[N];
int fa[20][300010],dep[N];
int f[N];
int g1[N],g2[N];
void Ads(int x,int y){to[++sl]=y;ne[sl]=st[x];st[x]=sl;}
int Lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int lft=dep[x]-dep[y];
	for(int i=0;lft;lft>>=1,++i)
		if(lft&1)x=fa[i][x];
	if(x==y)return x;
	D(i,18,0)
		if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void Build(int u){
	for(int i=st[u];i;i=ne[i])
		if(to[i]!=fa[0][u]){
			fa[0][to[i]]=u;
			dep[to[i]]=dep[u]+1;
			Build(to[i]);
		}
}
int Find(int x){return (f[x]==0)?x:(f[x]=Find(f[x]));}
int Dis(int x,int y){return dep[x]+dep[y]-2*dep[Lca(x,y)];}
struct Node{
	int w,a,b;
	void Mk(int x,int y){w=Dis(x,y);a=x;b=y;}
}p[10];
bool cmpp(Node a,Node b){return a.w>b.w;}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=R();
	F(i,1,n-1){
		int x=R(),y=R();
		a[i]=x;b[i]=y;
		Ads(x,y);Ads(y,x);
	}
	
	dep[1]=1;Build(1);
	F(i,1,18)
		F(j,1,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	//cout<<Lca(3,5)<<'\n';
	//cout<<Dis(3,5)<<'\n';
	F(i,1,n)g1[i]=g2[i]=i;
	F(i,1,n-1){
		int fx=Find(a[i]),fy=Find(b[i]);
		p[1].Mk(g1[fx],g2[fx]);
		p[2].Mk(g1[fy],g2[fy]);
		p[3].Mk(g1[fx],g1[fy]);
		p[4].Mk(g1[fx],g2[fy]);
		p[5].Mk(g2[fx],g1[fy]);
		p[6].Mk(g2[fx],g2[fy]);
		sort(p+1,p+7,cmpp);
		f[fx]=fy;
		g1[fy]=p[1].a;g2[fy]=p[1].b;
		cout<<Dis(p[1].a,p[1].b)<<'\n';
	}
	return 0;
}
