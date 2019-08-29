#include<bits/stdc++.h>

#define FILE "rebirth"
#define LLM LONG_LONG_MAX

using namespace std;

typedef long long ll;
typedef pair<long long,int> P;

template<typename T>
void read(T &x)
{
	bool f=0;char c=getchar();x=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=1;
	for(; isdigit(c);c=getchar()) x=x*10+c-'0';
	if(f) x=-x;
}

int Num,n,m;
tuple<ll,int,int> mark[200005];
ll dis[200005];
bool book[200005];
vector<P> g[200005];

void dijk(int x)
{
	priority_queue<P,vector<P>,greater<P>> q;
	fill(dis+2,dis+n+1,LLM);
	q.push(make_pair(0LL,x));
	while(!q.empty())
	{
		auto v=q.top().second;
		q.pop();
		if(!book[v])
		{
			book[v]=1;
			for(auto i=g[v].begin();i!=g[v].end();++i)
				if(dis[i->second]>dis[v]+i->first)
				{
					dis[i->second]=dis[v]+i->first;
					mark[i->second]=make_tuple(i->first,v,i->second);
					q.push(make_pair(dis[i->second],i->second));
				}
		}
	}
}

void dijk2(int x)
{
	priority_queue<P,vector<P>,greater<P>> q;
	fill(dis+1,dis+n+1,LLM);
	memset(book,0,sizeof(book));
	dis[x]=0;
	q.push(make_pair(0LL,x));
	while(!q.empty())
	{
		auto v=q.top().second;
		q.pop();
		if(!book[v])
		{
			book[v]=1;
			for(auto i=g[v].begin();i!=g[v].end();++i)
				if(!(i->first==get<0>(mark[x])
					&&(i->second==get<1>(mark[x])||i->second==get<2>(mark[x])))
					&&dis[i->second]>dis[v]+i->first)
				{
					dis[i->second]=dis[v]+i->first;
					q.push(make_pair(dis[i->second],i->second));
				}
		}
	}
}

int main()
{
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	read(Num),read(n),read(m);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		read(u),read(v),read(w);
		g[u].emplace_back(make_pair(w,v));
		g[v].emplace_back(make_pair(w,u));
	}
	dijk(1);
	printf("0 ");
	for(auto i=2;i<=n;++i)
	{
		dijk2(i);
		if(dis[1]==LLM)
			printf("-1 ");
		else
			printf("%lld ",dis[1]);
	}
	return 0;
}
