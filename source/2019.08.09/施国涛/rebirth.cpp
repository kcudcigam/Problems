#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn  200005
LL dis[maxn];
int num,n,m;
char vis[maxn];
vector<pair<int,int> > g[maxn]; 
void spfa(int s)
{
	for(int i=0;i<=n;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=false;
	}
	queue<int> q;
	q.push(s);
	vis[s]=true;
	dis[s]=0; 
	while(q.size())
	{
		int from=q.front();
		q.pop();
		vis[from]=false;
		for(int i=0;i<g[from].size();i++)
		{
			int to=g[from][i].first;
			int len=g[from][i].second;
			if(len==INT_MAX)
			{
				continue; 
			}
			if(dis[to]>dis[from]+len)
			{
				dis[to]=dis[from]+len;
				if(!vis[to])
				{
					vis[to]=true;
					q.push(to);	
				}
			}
		}
	}
}
int main()
{
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	cin>>num>>n>>m;
	for(int i=0;i<m;i++)
	{
		int from,to,len;
		scanf("%d%d%d",&from,&to,&len);
		g[from].push_back(make_pair(to,len));
		g[to].push_back(make_pair(from,len));
	}
	for(int i=1;i<=n;i++)
	{			
	//	cout<<i<<endl;
		if(i==1)
		{
			putchar('0');
			putchar(' ');
			continue;
		}
		LL ans=-INT_MAX;
		for(int j=0;j<g[i].size();j++)
		{
			//cout<<i<<endl;
			int tmp=g[i][j].second;
			int _=g[i][j].first;
			int __;
			g[i][j].second=INT_MAX;
			for(int k=0;k<g[_].size();k++)
			{
				if(g[_][k].first==i)
				{
					g[_][k].second==INT_MAX;
					__=k;
					break;
				}
			}
			spfa(i);
			g[i][j].second=tmp;
			g[_][__].second=tmp;
			if(dis[1]==INT_MAX)
			{
				putchar('-');
				putchar('1');
				putchar(' ');
				break;
			}
			else
			{
				ans=max(ans,dis[1]);
			}
		}
		if(dis[1]!=INT_MAX)printf("%d ",ans);
	}
	
}


