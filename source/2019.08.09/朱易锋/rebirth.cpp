#include<bits/stdc++.h>
#define ll long long
#define V void
#define R register
#define I inline
#define swap(x,y) (x^=y^=x^=y)
#define int long long
using namespace std;
const int N=200000+7;
const int M=500000+7;
const ll inf=1e15+7; 
int tot=0,head[N],to[N],nxt[N],edge[N];
int n=0,m=0;
I V add(R int x,R int y,R int z)
{
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y,edge[tot]=z;
}
I V Add(R int x,R int y,R int z)
{
	add(x,y,z);add(y,x,z);
}
struct node
{
	ll x,y,w,id;
}e[M];
int num=0;
bool v[M];
priority_queue<pair<ll,ll> >q;
bool vis[N];
ll dist[N],pre[N];
I V dij(R int s)
{
	for(R int i=1;i<=n;i++)
	{
		dist[i]=inf;
	}
	q.push(make_pair(0,s));
	dist[s]=0;
	while(q.size())
	{
		R ll x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(R int i=head[x];i;i=nxt[i])
		{
			R int y=to[i],z=edge[i];
			if(dist[y]>dist[x]+z)
			{
				dist[y]=dist[x]+z;pre[y]=i;
				if(!vis[y])
				{
					q.push(make_pair(-dist[y],y));
				}
			}
		}
	}
}
ll ans[N];
main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%lld",&num);
	scanf("%lld %lld",&n,&m);
	for(R int i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&e[i].x,&e[i].y,&e[i].w);
		add(e[i].x,e[i].y,e[i].w);
		e[i].id=tot;
		add(e[i].y,e[i].x,e[i].w);
	}
	tot=0;
	dij(1);
	ans[1]=0;
	for(R int i=2;i<=n;i++)ans[i]=inf;
	for(R int i=1;i<=m;i++)
	{
		R int z=e[i].w;
		R int x=e[i].x,y=e[i].y;
		if(e[i].id!=pre[x]&&e[i].id+1!=pre[x]&&e[i].id!=pre[y]&&e[i].id+1!=pre[y])
		{
			ans[x]=min(ans[x],dist[y]+z);
			ans[y]=min(ans[y],dist[x]+z);
		}
	}
	printf("0 ");
	for(R int i=2;i<=n;i++)
	{
		if(ans[i]==inf)ans[i]=-1;
		printf("%lld ",ans[i]);
	}
	return 0;
}
