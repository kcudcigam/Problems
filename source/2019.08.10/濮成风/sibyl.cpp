#include<bits/stdc++.h>
using namespace std;
const int maxn=3E5+5;
int n,m,Q;
int size,head[maxn*2];
int tag[maxn],receive[maxn];
int deg[maxn];
int limit;
vector<int>wait[maxn];
struct edge
{
	int to,next;
}E[maxn*2];
inline void addE(int u,int v)
{
	E[++size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
void init()
{
	for(int u=1;u<=n;++u)
		for(int i=head[u];i;i=E[i].next)
		{
			int v=E[i].to;
			if(deg[v]>=limit)
				wait[u].push_back(v);
		}
}
inline int ask(int u)
{
	int sum=0;
	for(int i=0;i<wait[u].size();++i)
		sum+=tag[wait[u][i]];
	return sum+receive[u];
}
inline void add(int u,int x)
{
	receive[u]+=x;
	if(deg[u]<limit)
		for(int i=head[u];i;i=E[i].next)
		{
			int v=E[i].to;
			receive[v]+=x;
		}
	else
		tag[u]+=x;
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>Q;
	limit=sqrt(m)+5;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		addE(x,y);
		addE(y,x);
		++deg[x],++deg[y];
	}
	init();
	while(Q--)
	{
		int opt,x,y;
		cin>>opt;
		if(opt==0)
		{
			cin>>x;
			cout<<ask(x)<<endl;
		}
		else
		{
			cin>>x>>y;
			add(x,y);
		}
	}
	return 0;
}

