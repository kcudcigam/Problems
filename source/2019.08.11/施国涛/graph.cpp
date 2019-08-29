#include<bits/stdc++.h>
using namespace std;
int dis[300001],vis[300001];	int n,m,Q;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
vector< pair<int,int> > g[300001];
void spfa(int s)
{
	for(int i=0;i<=n;i++)
	{
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	queue<int> q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(q.size())
	{
		int from=q.front();
		q.pop();
		vis[from]=0;
		for(int i=0;i<g[from].size();i++)
		{
			int to=g[from][i].first;
			int len=g[from][i].second;
			if(max(dis[from],len)<dis[to])
			{
				dis[to]=max(dis[from],len);
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);
	read(m);
	read(Q);
	while(m--)
	{	
		int from,to,len;
		read(from);
		read(to);
		read(len);
		g[from].push_back(make_pair(to,len));
		g[to].push_back(make_pair(from,len));
	 } 
	 while(Q--)
	 {
	 	int x,y;
	 	read(x);
	 	read(y);
	 	spfa(x);
	 	printf("%d\n",dis[y]==INT_MAX?-1:dis[y]);
	 }
}

