#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,Q,opt,x,y;
vector <int> c[500000];
int p[500000];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		c[x].push_back(y);c[y].push_back(x);
	}
	for (int i=1;i<=Q;i++)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			scanf("%d%d",&x,&y);
			for (int t=0;t<c[x].size();t++)
			{
				p[c[x][t]]+=y;
			}
		}
		else
		if (opt==0)
		{
			scanf("%d",&x);
			cout << p[x] << endl;
		}
	}
	return 0;
}

