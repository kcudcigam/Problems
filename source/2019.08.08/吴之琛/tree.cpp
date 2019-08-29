#include<bits/stdc++.h>
#define N 200010
#define D 21
using namespace std;
struct edge{
	int u,v,last;
};
edge c[N<<1];
int head[N],fa[N][D],tag[N],leaf[N],dep[N],a[N],f[N],m[N];
int T,n,k,len;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
void put(int x,int y){
	c[++len].u=x;
	c[len].v=y;
	c[len].last=head[x];
	head[x]=len;
	return;
}
void dfs(int p){
	for (int i=head[p];i;i=c[i].last)
		if (fa[p][0]!=c[i].v){
			leaf[p]=1;
			fa[c[i].v][0]=p;
			for (int j=1,s=2;s<dep[p];j++,s<<=1) fa[c[i].v][j]=fa[fa[c[i].v][j-1]][j-1];
			dep[c[i].v]=dep[p]+1;
			dfs(c[i].v);
		}
	return;
}
void add(int p){
	a[p]^=1;
	tag[fa[p][0]]++;
	int pos=p;
	for (int i=D-1;i>=0;i--){
		if (dep[pos]-m[i]<=dep[p]-k) continue;
		pos=fa[pos][i];
	}
	tag[fa[pos][0]]--;
	return;
}
void check(int p){
	if (!leaf[p]){
		if (a[p]==f[p]) return;
		if (dep[p]<k) return;
		add(p);
	}
	for (int i=head[p];i;i=c[i].last){
		if (c[i].v==fa[p][0]) continue;
		check(c[i].v);
		tag[p]+=tag[c[i].v];
	}
	a[p]=(a[p]+tag[p])%2;
	if (a[p]==f[p]) return;
	if (dep[p]<k) return;
	add(p);
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(T);
	m[0]=1;
	for (int i=1;i<=20;i++) m[i]=m[i-1]<<1;
	while (T--){
		read(n);read(k);
		memset(c,0,sizeof(c));
		memset(head,0,sizeof(head));
		for (int i=1;i<n;i++){
			int t1,t2;
			read(t1);read(t2);
			put(t1,t2);
			put(t2,t1);
		}
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(f[i]);
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
		memset(leaf,0,sizeof(leaf));
		dep[1]=1;
		dfs(1);
		memset(tag,0,sizeof(tag));
		check(1);
		bool flag=true;
		for (int i=1;i<=n;i++) if (a[i]!=f[i]) flag=false;
		if (flag) printf("Yes\n");else printf("No\n");
	}
	return 0;
}

