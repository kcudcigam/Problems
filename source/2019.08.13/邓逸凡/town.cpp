#include<bits/stdc++.h>
using namespace std;
int bing[300005];
int maxx[300005];
struct edge{
	int to_,next_;
} e[600010];
int head[300005];
int tot;
void Add(int x,int y)
{
	e[++tot].to_=y;
	e[tot].next_=head[x];
	head[x]=tot;
}
int read()
{
	int a=0; char c=getchar();
	for  (;!isdigit(c);c=getchar());
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
int Find_(int x)
{
	if  (bing[x]!=x)
		bing[x]=Find_(bing[x]);
	return bing[x];
}
int _max(int a,int b)
{
	return a>b?a:b; 
}
int Father,deep;
int w[300005];
void dfs(int x,int cc,int dep)
{
	w[x]=cc;
	if  (dep>deep)
		{
			Father=x;
			deep=dep;
		}
	for  (int i=head[x];i;i=e[i].next_)
		{
			int y=e[i].to_;
			if  (w[y]!=cc)
				dfs(y,cc,dep+1);
		}
}
int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int N=read();
	for  (int i=1;i<=N;i++)
		bing[i]=i;
	int Ans=0;
	for  (int i=1;i<N;i++)
		{
			int xx=read(),yy=read();
			if  (bing[xx]==xx&&bing[yy]==yy&&maxx[xx]==0&&maxx[yy]==0)
				{
					bing[yy]=xx;
					maxx[xx]=1;
					Add(xx,yy);
					Add(yy,xx);
					printf("%d\n",1);
					continue;
				}
			Add(xx,yy);
			Add(yy,xx);
			Father=0; deep=0;
			dfs(xx,i*2-1,0);
			int zz=Father;
			Father=0; deep=0;
			dfs(zz,i*2,0);
			printf("%d\n",deep);
		}
	return 0;
}
