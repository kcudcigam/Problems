#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
#define N 500500
#define ll long long
int n,q;
int fa[N],son[N];
inline int getfather(int x){
	if(fa[x]==x) return x;
	return fa[x]=getfather(fa[x]);
}
int juice[N],siz[N];
struct node{
	int nxt,to,age;
}s[2*N];
int head[N],tot=0;
inline void edge(int x,int y,int z){
	s[++tot].to=y,s[tot].nxt=head[x],head[x]=tot,s[tot].age=z;
	return ;
}
int ans[N];
bool vis[N];
inline void dfs(int x,int f,int k){
	vis[x]=1;
	ans[x]=k;
	for(int i=head[x];i;i=s[i].nxt){
		int y=s[i].to;
		if(y!=f){
			dfs(y,x,k+juice[y]+s[i].age);
		}
	}
	return ;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++) siz[i]=1,juice[i]=0,fa[i]=i;
	while(q--){
		int opt;
		read(opt);
		if(opt==1){
			int x,y;
			read(x),read(y);
			int fax=getfather(x),fay=getfather(y);
			if(fax!=fay){
				if(siz[fax]<siz[fay]) swap(fax,fay);
				fa[fay]=fax,edge(fax,fay,-juice[fax]),edge(fay,fax,-juice[fax]);
			}
		}
		if(opt==2){
			int a,b;
			read(a),read(b);
			int x=getfather(a);
			juice[x]+=b;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int x=getfather(i);
			dfs(x,0,juice[x]);
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
