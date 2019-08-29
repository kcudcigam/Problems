#include<bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[300001];
vector<int> b[300001];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		b[v].push_back(u);
		b[u].push_back(v);
	}
	while(q--)
	{
		int o;
		scanf("%d",&o);
		if(o)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]+=y;
			for(int i=0;i<b[x].size();i++)
			a[b[x][i]]+=y;
		}
		else
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",a[x]);
		}
	}
	return 0;
}


