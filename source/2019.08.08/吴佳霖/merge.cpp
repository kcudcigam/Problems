#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+5;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
vector<int>G[maxn];
int n,q;
int a[maxn];
int fa[maxn];
int ans[maxn];
int f(int x){
	if(x==fa[x])return x;
	return fa[x]=f(fa[x]);
}
void hb(int x,int y){
	x=f(x);y=f(y);
	fa[y]=x;
	G[x].push_back(y);
	return;
}
void dfs(int x,int y){
	for(int i=0;i<G[x].size();++i){
		if(x==G[x][i])ans[x]+=y;
		else dfs(G[x][i],y);
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int i;
	read(n);read(q);
	for(i=1;i<=n;++i){fa[i]=i;G[i].push_back(i);};
	for(i=1;i<=q;++i){
		int flag,x,y;
		read(flag);read(x);read(y);
		if(flag==1)hb(f(x),f(y));
		if(flag==2){
			x=f(x);
			dfs(x,y);
		}
	}
	for(i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
