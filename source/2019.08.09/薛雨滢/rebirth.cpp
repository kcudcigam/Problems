#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=200005;
const ll MAXM=500005;
const ll MAXX=1e18;
ll n,m,tail,head[MAXN],mem[MAXN],dis[MAXN],mar[MAXN];

struct Edge
{
	ll x,y,c,nex;
}e[MAXM*2];

struct Node
{
	ll x,dep;
	bool operator <(const Node &b)
	const{
		return dep>b.dep;
	}
};
void read(ll &p)
{
	p=0;char s=getchar();ll flag=1;
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
}


Node make_node(ll x,ll dep)
{
	Node tem;
	tem.x=x;tem.dep=dep;
	return tem;
}

priority_queue<Node> q;

void add(ll x,ll y,ll c)
{
	e[++tail].x=x;e[tail].y=y;e[tail].c=c;
	e[tail].nex=head[x];head[x]=tail;
}

void dij()
{
	for(int i=1;i<=n;i++) dis[i]=mem[i]=MAXX;
	dis[1]=0;mem[1]=0;
	q.push(make_node(1,0));
	while(q.size())
	{
		ll x=q.top().x,dep=q.top().dep;q.pop();
		if(dep>dis[x]) continue;
		for(ll i=head[x];i;i=e[i].nex)
		{
			ll y=e[i].y;
			if(mar[y]!=x&&dis[y]+e[i].c>dis[x]) mem[x]=min(mem[x],dis[y]+e[i].c);
			if(mar[x]!=y&&dis[y]+e[i].c==dis[x]&&mar[y]!=x) mem[x]=min(mem[x],dis[x]);
			ll tem=e[i].c+dep;
			if(tem>dis[y]&&mar[x]!=y) mem[y]=min(tem,mem[y]);
			if(tem==dis[y]&&mar[y]!=x&&mar[x]!=y) mem[y]=min(mem[y],tem);
			if(dis[y]>tem)
			{
				if(mar[x]!=y) mem[y]=min(dis[y],mem[y]);
				dis[y]=tem;mar[y]=x;
				q.push(make_node(y,tem));
			}
		}
	}
}


int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(n);read(n);read(m);
	ll x,y,c;
	for(ll i=1;i<=m;i++)
	{
		read(x);read(y);read(c);if(x==y) continue;
		add(x,y,c);add(y,x,c);
	}
	
	dij();
	for(ll i=1;i<=n;i++) 
	{
		if(mem[i]==MAXX) printf("-1 ");
		else printf("%lld ",mem[i]);
	}
	return 0;
 } 
