#include<bits/stdc++.h>
#define il inline
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;i++)
#define Rep(i,x,y) for(re int i=x;i>=y;i--)
#define ll long long
#define inf 0x3f3f3f3f
#define lnf 0x3f3f3f3f3f3f3f3f
using namespace std;
template <typename T> il void read(T &x)
{
	int f=1;
	x=0;
	char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int N=500005;
int to[N<<1],nex[N<<1],head[N],tot;
void add(int u,int v)
{
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
int ans[N],vis[N];
void dfs(int u,int v,int tim)
{
	vis[u]=tim;
	ans[u]+=v;
	for(int i=head[u];i;i=nex[i])
	if(vis[to[i]]!=tim)
	dfs(to[i],v,tim);
}
int n,q,opt,x,y;
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(q);
	rep(i,1,q)
	{
		read(opt),read(x),read(y);
		if(opt&1)
		add(x,y),add(y,x);
		else dfs(x,y,i);
	}
	rep(i,1,n)
	printf("%d ",ans[i]);
	return 0;
}


