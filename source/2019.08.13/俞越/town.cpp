#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int head[M],nxt[M<<1],to[M<<1],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
int dep[M];
int lg[M],f[M][20];
void dfs1(int x,int ff){
	dep[x]=dep[ff]+1;
	f[x][0]=ff;
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==ff) continue;
		dfs1(y,x);
	}
}
int Lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]){
		if (del>>i&1) x=f[x][i];
	}
	if (x==y) return x;
	DF(i,lg[dep[x]],0) {
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[Lca(x,y)];
}
int n;
int len[M],l[2][M],fi[M];
int Find(int x){
	if (fi[x]==x) return x;
	return fi[x]=Find(fi[x]);
}
int X[M],Y[M];
short le,stk[30];
void out(int x){
	if (!x) return putchar('0'),putchar('\n'),void();
	le=0;
	while (x) stk[le++]=x%10,x/=10;
	while (le--) putchar('0'+stk[le]);
	putchar('\n');
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read(); 
	F(i,1,n-1){
		int x=read(),y=read();
		X[i]=x; Y[i]=y;
		add(x,y); add(y,x);
	}
	F(i,2,n) lg[i]=lg[i>>1]+1; 
	dfs1(1,0);
//	cout<<dis(3,7)<<"\n";
	F(i,1,n) fi[i]=l[0][i]=l[1][i]=i;
	F(i,1,n-1) {
		int u=Find(X[i]),v=Find(Y[i]);
		fi[v]=u;
		int aa=len[u],bb=len[v];
		int qq=dis(l[0][u],X[i]),ww=dis(l[1][u],X[i]),ee=dis(l[0][v],Y[i]),rr=dis(l[1][v],Y[i]);
		bool opt0=0,opt1=0; int mx0=0,mx1=0;
		if (qq>ww) mx0=qq,opt0=0;
		else mx0=ww,opt0=1;
		if (ee>rr) mx1=ee,opt1=0;
		else mx1=rr,opt1=1;
		int cc=mx1+mx0+1;
		if (aa>=bb && aa>=cc){
			len[u]=aa;
		}
		else if (bb>=aa && bb>=cc){
			len[u]=bb;
			l[0][u]=l[0][v];
			l[1][u]=l[1][v];
		}
		else {
			len[u]=cc;
			int tmp0=l[opt0][u],tmp1=l[opt1][v];
			l[0][u]=tmp0; l[1][u]=tmp1;
		}
//		cout<<len[u]<<"\n";
		out(len[u]);
	}
	return 0;
}
