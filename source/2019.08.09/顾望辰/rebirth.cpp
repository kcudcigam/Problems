#include<cstdio>
#include<queue>
using namespace std;
const long long INF=23333333333333333;
long long num,n,m,head[1010],cnt,ans;
struct edge
{
	long long v,w,nxt;
}e[2010];
void add(long long u,long long v,long long w)
{
	e[++cnt]=(edge){v,w,head[u]};
	head[u]=cnt;
	return ;
}
long long op(long long x)
{
	if(x&1ll==1) return x+1;
	return x-1;
}
long long ItDied(long long s)
{
	long long d[1010];
	bool inq[1010];
	queue<long long> q;
	for(long long i=0;i<1010;i++)
	{
		d[i]=INF;
		inq[i]=false;
	}
	d[s]=0;
	inq[s]=true;
	q.push(s);
	while(!q.empty())
	{
		long long u=q.front();
		q.pop();
		inq[u]=false;
		for(long long i=head[u];i;i=e[i].nxt)
		{
			long long v=e[i].v,w=e[i].w;
			if(d[u]+w<d[v])
			{
				d[v]=d[u]+w;
				if(!inq[v])
				{
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
	return d[1];
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%lld%lld%lld",&num,&n,&m);
	long long x,y,z;
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	long long temp;
	for(long long i=1;i<=n;i++)
	{
		ans=-INF;
		for(long long j=head[i];j;j=e[j].nxt)
		{
			temp=e[j].w;
			e[j].w=INF;
			e[op(j)].w=INF;
			ans=max(ans,ItDied(i));
			e[j].w=temp;
			e[op(j)].w=temp;
		}
		if(ans==-INF||ans==INF) printf("-1 ");
		else printf("%lld ",ans);
	}
	return 0;
}
