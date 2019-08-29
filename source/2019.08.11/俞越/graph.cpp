#include<bits/stdc++.h>
#define LL long long
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=6e5+10;
struct node{
	int x,y,v;
}a[M]; 
bool cmp(node A,node B){
	return A.v<B.v;
}
int f[M],n,m,q;
int Find(int x){
	if (f[x]==x) return x;
	return f[x]=Find(f[x]);
}
int head[M],nxt[M],to[M],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; head[x]=cnt; to[cnt]=y;
}
int dep[M],ff[M][20],gg[M][20],lg[M];
void dfs(int x){
	F(i,1,lg[dep[x]]) ff[x][i]=ff[ff[x][i-1]][i-1];
	F(i,1,lg[dep[x]]) gg[x][i]=max(gg[ff[x][i-1]][i-1],gg[x][i-1]);
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		dep[y]=dep[x]+1;	
		ff[y][0]=x;
		gg[y][0]=a[x-n].v; 
		dfs(y);
	}
}
int query(int x,int y){
	int ans=0;
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]){
		if (del>>i&1){
			ans=max(ans,gg[x][i]);
			x=ff[x][i];
		}
	}
	if (x==y) return ans;
	DF(i,lg[dep[x]],0){
		if (ff[x][i]!=ff[y][i]){
			ans=max(ans,gg[x][i]);
			ans=max(ans,gg[y][i]);
			x=ff[x][i]; y=ff[y][i];
		}
	}
	return max(ans,a[ff[x][0]-n].v);
}
bool used[M];
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read(); m=read(); q=read();
	F(i,1,m){
		a[i]=(node){read(),read(),read()};
	}
	sort(a+1,a+m+1,cmp);
	F(i,1,n+m) f[i]=i;
	int ct=0,rt=0;
	F(i,1,m){
		int u=Find(a[i].x),v=Find(a[i].y);
		if (u==v) continue;
		ct++; add(i+n,u); add(i+n,v); 
		f[u]=f[v]=i+n; used[i]=1;
		if (ct==n-1) break;
	}
	F(i,2,n+m) lg[i]=lg[i>>1]+1;
	F(i,1,m){
		if (used[i] && Find(i+n)==i+n) {
			dfs(i+n);
		}
	}
	while (q--){
		int x=read(),y=read();
		if (Find(x)!=Find(y)){
			cout<<"-1\n";
			continue;
		}
		cout<<query(x,y)<<"\n";
	}
	return 0;
}

