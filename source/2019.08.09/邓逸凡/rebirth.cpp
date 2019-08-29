#include<bits/stdc++.h>
#define da 500000000000000
typedef long long ll;
using namespace std;
int read()
{
	int a=0;char c=getchar();
	for  (;!isdigit(c);c=getchar());
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
struct edge{
	int to_,value_,next_;
} e[1000010];
int head[200010];
int tot;
void Add(int x,int y,int z)
{
	e[++tot].to_=y;
	e[tot].value_=z;
	e[tot].next_=head[x];
	head[x]=tot;
}
ll dist[200050];
int dfn[200050],low[200050];
int tt=1;
int ok[200050];
void dfs(int x)
{
	for  (int i=head[x];i;i=e[i].next_)
		{
			int y=e[i].to_,z=e[i].value_;
			if  (!dfn[y])
				{
					dist[y]=dist[x]+z;
					dfn[y]=low[y]=y;
					dfs(y);
					continue;
				}
			low[y]=min(low[y],dfn[x]);
			if  (low[y])
			if  (dist[x]+z<dist[y])
				{
					dist[y]=dist[x]+dist[z];
					low[y]=min(low[y],)
					dfs(y);
				}
		}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num=read();
	int N=read(),M=read();
	for  (int i=1;i<=M;i++)
		{
			int xx=read(),yy=read(),zz=read();
			Add(xx,yy,zz);
			Add(yy,xx,zz);
		}
	for  (int i=1;i<=N;i++)
		dist[i]=da;
	dist[1]=0;
	dfn[1]=0;
	dfs(1);
	printf("0");
	for  (int i=2;i<=N;i++)
		{
			if  (low[i]==dfn[i])
				printf(" %d",-1);
			long long ans=da;
			for  (int j=head[x];j;j=e[j].next_)
				{
					int 
				}
		}
	return 0;
}

