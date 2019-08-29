#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
struct sb{
	int to;
	int next;
}s[2000010];
int n,q,head[1000010],tot;
int sum[1000010],fa[1000010],cnt;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
inline void add(int x,int y){
	s[++tot].next=head[x];
	s[tot].to=y;
	head[x]=tot;
}
inline int find(int x){
	if(fa[x]==x){
		return x;
	}
	else fa[x]=find(fa[x]);
	return fa[x];
}
inline void dfs(int x,int fa){
	for(register int i=head[x];i;i=s[i].next){
		int y=s[i].to;
		if(y==fa) continue;
		sum[y]+=sum[x];
		dfs(y,x);
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for(register int i=1;i<=n;i++){
		fa[i]=i;
	}
	cnt=n;
	for(register int i=1;i<=q;i++){
		int opt;
		read(opt);
		if(opt==1){
			int x,y;
			read(x);
			read(y);
			int fx=find(x),fy=find(y);
			if(fx==fy){
				continue;
			}
			fa[fx]=++cnt;
			fa[fy]=cnt;
			fa[cnt]=cnt;
			add(cnt,fx);
			add(fx,cnt);
			add(cnt,fy);
			add(fy,cnt);
		}
		else if(opt==2){
			int x,y;
			read(x);read(y);
			sum[find(x)]+=y;
		}
	}
	for(register int i=1;i<=cnt;i++){
		if(fa[i]==i){
			dfs(i,0);
		}
	}
	for(register int i=1;i<=n;i++){
		printf("%d ",sum[i]);
	}
}
