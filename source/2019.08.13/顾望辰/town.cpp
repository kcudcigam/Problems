#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
struct edge
{
	int v,nxt;
}e[300010];
int n,cnt,u_[300010],v_[300010],head[300010],dis[10010][10010],dis2[10010],vis[300010],vis2[300010];
void add(int u,int v)
{
	e[++cnt]=(edge){v,head[u]};
	head[u]=cnt;
	return ;
}
void bfs1(int s)
{
	memset(vis2,false,sizeof(vis2));
	queue<int> q;
	int now,v;
	vis2[s]=true;
	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].nxt)
		{
			v=e[i].v;
			if(vis2[v]) continue;
			dis[s][v]=min(dis[s][v],dis[s][now]+1);
			dis[v][s]=dis[s][v];
			q.push(v);
			vis2[v]=true;
		}
	}
	return ;
}
void bfs2(int s)
{
	memset(vis,false,sizeof(vis));
	queue<int> q;
	int now,v;
	vis[s]=true;
	q.push(s);
	bfs1(s);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].nxt)
		{
			v=e[i].v;
			if(vis[v]) continue;
			bfs1(v);
			q.push(v);
			vis[v]=true;
		}
	}
	return ;
}
int bfs3(int s,bool special=false)
{
	memset(vis,false,sizeof(vis));
	if(special) memset(dis2,0,sizeof(dis2));
	queue<int> q;
	int now,v,st,ans=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].nxt)
		{
			v=e[i].v;
			if(vis[v]) continue;
			if(special)
			{
				dis2[v]=dis2[now]+1;
				if(dis2[v]>ans)
				{
					ans=dis2[v];
					st=v;
				}
			}
			else
			{
				if(dis[s][v]>ans)
				{
					ans=dis[s][v];
					st=v;
				}
			}
			q.push(v);
			vis[v]=true;
		}
	}
	return st;
}
int bfs4(int s,bool special=false)
{
	memset(vis,false,sizeof(vis));
	if(special) memset(dis2,0,sizeof(dis2));
	queue<int> q;
	int now,v,ans=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=head[now];i;i=e[i].nxt)
		{
			v=e[i].v;
			if(vis[v]) continue;
			if(special)
			{
				dis2[v]=dis2[now]+1;
				ans=max(ans,dis2[v]);
			}
			else ans=max(ans,dis[s][v]);
			q.push(v);
			vis[v]=true;
		}
	}
	return ans;
}
void NormalTest()
{
	memset(dis,0x3f,sizeof(dis));
	int st;
	for(int i=1;i<n;i++)
	{
		add(u_[i],v_[i]);
		add(v_[i],u_[i]);
		dis[u_[i]][v_[i]]=1;
		bfs2(u_[i]);
		st=bfs3(u_[i]);
		printf("%d\n",bfs4(st));
	}
	return ;
}
void SpecialTest()
{
	int st;
	for(int i=1;i<n;i++)
	{
		add(u_[i],v_[i]);
		add(v_[i],u_[i]);
		st=bfs3(u_[i],true);
		printf("%d\n",bfs4(st,true));
	}
	return ;
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	bool Special=true;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u_[i],&v_[i]);
		if(u_[i]>i||v_[i]!=i+1) Special=false;
	}
	if(Special) SpecialTest();
	else NormalTest();
	return 0;
}
