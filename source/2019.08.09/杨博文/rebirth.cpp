#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
const int maxm=5e5+100;
struct io{
	template<typename T> void read(T &n)
	{
		n=0;
		char c;bool f=0;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T> io operator >> (T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
struct edge{
	int v,w,nxt,del;
}e[maxm<<1];
int tot,head[maxn];
inline void __ADD(int x,int y,int z)
{
	e[++tot].v=y;
	e[tot].w=z;
	e[tot].nxt=head[x];
	head[x]=tot;
}
inline void add(int x,int y,int z)
{
	__ADD(x,y,z);
	__ADD(y,x,z);
}
long long mind1[maxn],mind2[maxn];
bool vis[maxn];
int n,m;
int fa[maxn];
void dij(int t)
{
	memset(vis,0,sizeof(vis));
	for(register int i=2;i<=n;i++)mind1[i]=LLONG_MAX>>2;
	priority_queue<pair<long long,int> >q;
	while(!q.empty())q.pop();
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		register int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(register unsigned int i=head[u];i;i=e[i].nxt)
		{
			if(e[i].del)continue;
			register int v=e[i].v;
			register long long w=(long long)e[i].w+mind1[u];
			if(mind1[v]>w)
			{
				mind1[v]=w;
				if(t)fa[v]=i;
				q.push(make_pair(-mind1[v],v));
			}
		}
	}
}
int in[maxn];
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int num;
	yin>>num;
	yin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		yin>>x>>y>>z;
		++in[x];
		++in[y];
		if(x^y)add(x,y,z);
	}
	dij(1);
	for(int i=1;i<=n;i++)
	{
		if(in[i]==1){printf("-1 ");continue;}
		e[fa[i]].del=1;
		dij(0);
		if(mind1[i]!=LLONG_MAX>>2)
			printf("%lld ",mind1[i]);
		else printf("-1 ");
		e[fa[i]].del=0;
	}
	return 0;
}
