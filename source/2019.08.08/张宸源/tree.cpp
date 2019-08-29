#include<bits/stdc++.h>
using namespace std;
const int N=200000+5;
int to[N],nex[N],head[N],tot;
int dep[N],fa[N],low[N];
inline void add(int u,int v)
{
	to[++tot]=v;
	nex[tot]=head[u];
	head[u]=tot;
}
void dfs(int u)
{
	low[u]=dep[u];
	for(int i=head[u];i;i=nex[i])
	{
		if(to[i]!=1&&fa[to[i]]==0)
		fa[to[i]]=u,dep[to[i]]=dep[u]+1,dfs(to[i]),low[u]=max(low[u],low[to[i]]);
	}
}
int t[N]; //当前子树内深度为i的点被翻转了 t[i]次 
int sum[N]; //当前结点被下面的结点影响了几次 
int flag;
int n,k;
int a[N],c[N];
void check(int u)
{
//	t[dep[u]]=0;
	sum[u]=0;
	for(int i=head[u];i;i=nex[i])
	if(to[i]!=fa[u])
	check(to[i]),sum[u]=sum[u]+sum[to[i]]-t[dep[u]+k],t[dep[u]+k]=0;
	if((a[u]+sum[u])%2!=c[u])
	{
		if(dep[u]<k)
		flag=1;
		else t[dep[u]]++,sum[u]++;
	}
//	cout<<u<<' '<<sum[u]<<' '<<flag<<"* *";
//	for(int i=1;i<=n;i++)
//	cout<<' '<<t[i];
//	cout<<endl;
}
int T,u,v;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(head,0,sizeof(head));
		memset(fa,0,sizeof(fa));
		flag=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dep[1]=1;
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
		dfs(1);
		check(1);
		if(flag==1)
		puts("No");
		else puts("Yes");
	}
	return 0;
}
/*
2
3 2
1 2
2 3
0 0 0
1 0 1
3 2
1 2
2 3
0 0 0
1 1 1

1
7 2
1 2
1 3
2 4
2 5
3 6
3 7
0 0 0 0 0 0 0
1 1 1 1 0 1 1
Yes

1
8 2
1 2
1 3
2 4
2 5
3 6
3 7
7 8
0 0 0 0 0 0 1 0
1 1 1 1 0 1 1 1
Yes
*/
