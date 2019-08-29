#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
#define re register int 
const int maxn=500005;
int fa[maxn],head[maxn],ver[2*maxn],nxt[2*maxn],tot,ans[maxn],v[maxn];
int n,q;
inline void add(int x,int y)
{
	ver[++tot]=y; nxt[tot]=head[x]; head[x]=tot;
}

int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

void dfs(int x,int z) 
{	
	v[x]=1;
	for(re i=head[x];i;i=nxt[i]) {
		int y=ver[i]; 
		if(v[y]) continue;
		dfs(y,z);
		ans[y]+=z;
	}
}

int main()
{
//	freopen("merge.in","r",stdin);
//	freopen("merge.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(re i=1;i<=n;i++) fa[i]=i;
	for(re i=1;i<=n;i++) {
		add(i,i);
	}
	while(q--) {
		int x; scanf("%d",&x);
		int a,b; scanf("%d%d",&a,&b);
		int x1=get(fa[a]); int y2=get(fa[b]);
		if(x==1) {
			fa[y2]=x1;
			add(x1,y2); //°Ñx1y2ºÏ²¢ 
		}
		else {
			memset(v,0,sizeof(v));
			dfs(a,b);
		}
	}
	cout<<ans[2]<<endl;
	for(int i=1;i<=n;i++) {
		printf("%d ",ans[i]);
	return 0;
	}
}
