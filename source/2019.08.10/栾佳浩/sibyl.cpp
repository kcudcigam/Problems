#include<bits/stdc++.h>
using namespace std;
int n,m,q;
const int maxn=300005;
int ans[maxn]; 
int fst[maxn];
int nxt[maxn<<1];
int v[maxn];
int edge;
int d[maxn];
void add(int x,int y)
{
	edge++;
	nxt[edge]=fst[x];
	fst[x]=edge;
	v[edge]=y;
}
int fa[maxn];
int tag[maxn];
int b[maxn];
void dfs(int x,int pre)
{
	fa[x]=pre;
	b[x]=1;
	for(int i=fst[x];i;i=nxt[i])
	{
		if(v[i]!=pre)
		{
			dfs(v[i],x);
		}
	}
}
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		d[x]++,d[y]++;
	}
	if(n<=3000&&m<=3000&&q<=3000)
	{
		while(q--)
		{
			int typ;
			scanf("%d",&typ);
			int x,y;
			if(typ==0)
			{
				scanf("%d",&x);
				printf("%d\n",ans[x]);
			}
			else 
			{
				scanf("%d%d",&x,&y);
				for(int i=fst[x];i;i=nxt[i])
				{
					ans[v[i]]+=y;
				}
				ans[x]+=y;
			}
		}
	}
	else 
	{
	int flag=0;
	for(int i=2;i<=n;i++)
	{
		if(d[i]>10)flag=1;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		if(!b[i])dfs(i,0);
		while(q--)
		{
			int typ;
			scanf("%d",&typ);
			int x,y;
			if(typ==0)
			{
				scanf("%d",&x);
				printf("%d\n",ans[x]+tag[fa[x]]);
			}
			else 
			{
				scanf("%d%d",&x,&y);
				ans[fa[x]]+=y;
				ans[x]+=y;
				tag[x]+=y;
			}
		}
	}
	else
	{
		for(int i=fst[1];i;i=nxt[i])
		{
			b[v[i]]=1;
		}
		int tg=0;
		while(q--)
		{
			int typ;
			scanf("%d",&typ);
			int x,y;
			if(typ==0)
			{
				scanf("%d",&x);
				if(b[x])printf("%d\n",ans[x]+tg);
				else printf("%d\n",ans[x]);
			}
			else 
			{
				scanf("%d%d",&x,&y);
				if(x==1)
				{
					ans[x]+=y;
					tg+=y;
				}
				else 
				{
				for(int i=fst[x];i;i=nxt[i])
				{
					ans[v[i]]+=y;
				}
				ans[x]+=y;
				}
			}
		}		
	}
	}
}
