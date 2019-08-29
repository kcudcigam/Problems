#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+5;
#define ll long long
int n,m,head[MAXN],nxt[4*MAXN],len[4*MAXN],to[4*MAXN],tot=-1,last[MAXN];
queue <int> Q;
bool del[4*MAXN],in[MAXN];
ll dist[MAXN];
void add_edge(int x,int y,int z)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	len[tot]=z;
}
void bell()
{
	dist[1]=0;
	for(int i=1;i<=n;i++)
		for(int e=head[i];~e;e=nxt[e])
			if(dist[i]+len[e]<dist[to[e]])
				last[to[e]]=e,dist[to[e]]=dist[i]+len[e];
}
void spfa()
{
	memset(dist,0x7f,sizeof(dist));
	memset(in,0,sizeof(in));
	dist[1]=0,in[1]=1;;
	Q.push(1);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=head[x];~i;i=nxt[i])
		{
			if(del[i])
				continue;
			if(dist[x]+len[i]<dist[to[i]])
			{
				dist[to[i]]=dist[x]+len[i];
				if(!in[to[i]])
				{
					in[to[i]]=1;
					Q.push(to[i]);
				}
			}
		}
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(dist,0x7f,sizeof(dist));
	cin>>n>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	bell();
	cout<<0<<' ';
	for(int i=2;i<=n;i++)
	{
		del[last[i-1]]=del[last[i-1]^1]=0;
		del[last[i]]=del[last[i]^1]=1;
		spfa();
		if(dist[i]==9187201950435737471)
			cout<<-1<<' ';
		else
			cout<<dist[i]<<' ';
	}
	return 0;
}
