#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > m[300001];
template <typename T> void R(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int dis[300001];
bool vis[300001];
priority_queue<pair<int,int> > q;
void di(int s)
{
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int dep=q.top().first,pos=q.top().second;
		q.pop();
		if(vis[pos]==1)  continue;
		vis[pos]=1;
		for(int i=0;i<m[pos].size();i++)
		{
			dis[m[pos][i].first]=min(dis[m[pos][i].first],max(dep,m[pos][i].second));
			q.push(make_pair(dis[m[pos][i].first],m[pos][i].first));
		}
	}
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,M,Q,x,y,z;
	R(n);R(M);R(Q);
	for(int i=1;i<=M;i++)
	{
		R(x);R(y);R(z);
		m[x].push_back(make_pair(y,z));
	}
	int s,e;
	for(int i=1;i<=Q;i++)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		R(s);R(e);
		di(s);
		if(dis[e]==0x3f3f3f3f)  printf("-1\n");
		else printf("%d\n",dis[e]);
	}
	return 0;
}

