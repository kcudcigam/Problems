#include<bits/stdc++.h>
#define N 300005
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
P a[N],s[N];
vector<int> e[N];
int n,x,y,dep[N],top[N],son[N],fa[N],sz[N],f[N],l[N];
int Get(int x){return x==f[x]?x:f[x]=Get(f[x]);}
void Merge(int x,int y){f[Get(x)]=Get(y);}
void Dfs(int x){
	sz[x]=1;
	for (int y:e[x]){
		if (dep[y]) continue;
		dep[y]=dep[x]+1;fa[y]=x;Dfs(y);
		if (sz[y]>sz[son[x]]) son[x]=y;
		sz[x]+=sz[y];
	}
}
void Dfs(int x,int t){
	top[x]=t;
	if (!son[x]) return;Dfs(son[x],t);
	for (int y:e[x]) if (y!=fa[x]&&y!=son[x]) Dfs(y,y);
}
int Lca(int x,int y){
	for (;top[x]^top[y];x=fa[top[x]]) if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int Calc(int x,int y){
	return dep[x]+dep[y]-2*dep[Lca(x,y)];
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	read(n);
	for (int i=1;i<n;++i){
		read(x);read(y);a[i]=make_pair(x,y);
		e[x].push_back(y);e[y].push_back(x);
	}
	dep[1]=1;Dfs(1);Dfs(1,1);
	for (int i=1;i<=n;++i) f[i]=i,s[i]=make_pair(i,i);
	for (int i=1;i<n;++i){
		int f=Get(a[i].first),g=Get(a[i].second),mx=0,ss;
		P X=s[f],Y=s[g],Z;int A=X.first,B=X.second,C=Y.first,D=Y.second;
		if (l[f]>l[g]) mx=l[f],Z=X;
		else mx=l[g],Z=Y;
		ss=Calc(A,C);if (ss>mx) mx=ss,Z=make_pair(A,C);
		ss=Calc(A,D);if (ss>mx) mx=ss,Z=make_pair(A,D);
		ss=Calc(B,C);if (ss>mx) mx=ss,Z=make_pair(B,C);
		ss=Calc(B,D);if (ss>mx) mx=ss,Z=make_pair(B,D);
		printf("%d\n",mx);Merge(a[i].first,a[i].second);
		int p=Get(a[i].first);s[p]=Z;l[p]=mx;
	}
	return 0;
}
