#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
int f[maxn];
int fst[maxn];
int nxt[maxn<<1];
int v[maxn<<1];
int k[maxn<<1];
int edge;
int inf;
int n,m,qq;
void add(int x,int y,int val)
{
	edge++;
	nxt[edge]=fst[x];
	fst[x]=edge;
	v[edge]=y;
	k[edge]=val;
}
struct node
{
	int max_dis,num;
	bool operator<(const node &x)const
	{
		return max_dis>x.max_dis;
	}
};
priority_queue<node> q;
int dist[maxn];
int fa[maxn][20];
int ans[maxn][20];
inline int find(int x)
{
	return (f[x]==x)?x:f[x]=find(f[x]);
}
int dep[maxn];
void dij()
{
	for(int i=1;i<=n;i++)
	{
		if(dist[i]!=inf)continue;
		node ss;
		ss.max_dis=0;
		ss.num=i;
		q.push(ss);
		dist[i]=0;
		while(!q.empty())
		{
		node x=q.top();
//		cout<<x.max_dis<<" "<<dist[x.num]<<endl;
		q.pop();
		if(dist[x.num]<x.max_dis)continue;
		for(int i=fst[x.num];i;i=nxt[i])
		{
			if(dist[v[i]]>max(dist[x.num],k[i]))
			{
				dist[v[i]]=max(dist[x.num],k[i]);
				fa[v[i]][0]=x.num;
				ans[v[i]][0]=k[i];
				dep[v[i]]=dep[x.num]+1;
				node now;
				now.num=v[i];
				now.max_dis=dist[v[i]];
				q.push(now);
			}
		}
		}	
	}
}
int query(int x,int y)
{
	int anss=0;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)
	{
		if(dep[fa[x][i]]>=dep[y])
		{
			anss=max(anss,ans[x][i]);
			x=fa[x][i];
		}
	}
	for(int i=19;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			anss=max(anss,ans[x][i]);
			x=fa[x][i];			
			anss=max(anss,ans[y][i]);
			x=fa[y][i];
		}
	}
	return max(anss,max(ans[x][0],ans[y][0]));
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	inf=dist[0];
	scanf("%d%d%d",&n,&m,&qq);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		add(x,y,val);
		add(y,x,val);
		int fx=find(x);
		int fy=find(y);
		if(fx!=fy)f[fx]=fy;
	}
	dij();
	for(int j=1;j<=19;j++)
	{
		for(int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1],ans[i][j]=max(ans[i][j-1],ans[fa[i][j-1]][j-1]);
	}
	while(qq--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(find(x)!=find(y))puts("-1");
		else 
		{
			printf("%d\n",query(x,y));
		}
	}
}
