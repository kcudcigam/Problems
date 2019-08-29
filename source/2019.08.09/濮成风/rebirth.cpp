#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=2E5+5;
const ll inf=1E15;
int num;
int n,m;
int size=1,head[maxn*2],pre[maxn];
ll dis[maxn];
bool visE[maxn*2],vis[maxn];
struct edge
{
	int to,next;
	ll w;
}E[maxn*2];
inline ll min(ll x,ll y)
{
	return x<y?x:y;
}
inline ll max(ll x,ll y)
{
	return x>y?x:y;
}
inline void add(int u,int v,ll w)
{
	E[++size].to=v;
	E[size].next=head[u];
	E[size].w=w;
	head[u]=size;
}
inline int read()
{
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	int sum=ch-'0';
	ch=getchar();
	while('0'<=ch&&ch<='9')
	{
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
void write(ll x)
{
	if(x>=10)
		write(x/10);
	putchar('0'+x%10);
}
inline void writen(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	write(x);
	putchar(' ');
}
void spfa(bool flag=0)
{
	for(int i=1;i<=n;++i)
		dis[i]=inf;
	queue<int>Q;
	Q.push(1);
	dis[1]=0;
	vis[1]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=E[i].next)
		{
			if(visE[i])
				continue;
			int v=E[i].to;
			ll nw=E[i].w+dis[u];
			if(nw>=dis[v])
				continue;
			if(flag)
				pre[v]=u;
			dis[v]=nw;
			if(!vis[v])
				vis[v]=1,Q.push(v);
		}
	}
}
ll get(int u)
{
	if(u==1)
		return 0;
	ll ans=-1;
	for(int i=head[u];i;i=E[i].next)
	{
		visE[i]=visE[i^1]=1;
		spfa();
		ans=max(ans,dis[u]);
		visE[i]=visE[i^1]=0;
	}
	if(ans>=inf)
		return -1;
	return ans;
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	ios::sync_with_stdio(false);
	num=read(),n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	spfa(1);
	for(int i=1;i<=n;++i)
		writen(get(i));
	return 0;
}

