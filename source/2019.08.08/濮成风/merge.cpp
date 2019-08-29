#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=5E5+5;
int n,q;
int size,head[maxn*2],fa[maxn],tag[maxn],ans[maxn],sum[maxn];
bool vis[maxn];
struct edge
{
	int to,next;
}E[maxn];
inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void add(int u,int v)
{
	E[++size].to=v;
	E[size].next=head[u];
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
void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar('0'+x%10);
}
inline void writen(int x)
{
	write(x);
	putchar(' ');
}
void dfs(int u,ll sum,bool flag)
{
	sum+=tag[u];
	tag[u]=0;
	ans[u]+=sum;
	vis[u]=flag;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		dfs(v,sum,flag);
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		sum[i]=1;
	}
	while(q--)
	{
		int opt=read(),x=read(),y=read();
		if(opt==1)
		{
			if(find(x)==find(y))
				continue;
			sum[find(x)]+=sum[find(y)];
			tag[find(y)]-=tag[find(x)];
			add(find(x),find(y));
			fa[find(y)]=find(x);
		}
		else
			tag[find(x)]+=y;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])
			dfs(i,0,1);
	for(int i=1;i<=n;++i)
		writen(ans[i]);
	return 0;
}

