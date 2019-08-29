#include<bits/stdc++.h>
using namespace std;
vector<int> m[300002];
map<int,int> add;
int val[300002];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,M,Q;
	scanf("%d%d%d",&n,&M,&Q);
	int u,v;
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d",&u,&v);
		m[u].push_back(v);
		m[v].push_back(u);
	}
	int op,x,y;
	for(int i=1;i<=Q;i++)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			add[x]+=y;
			val[x]+=y;
		}
		if(op==0)
		{
			scanf("%d",&x);
			if(!add.empty())
			{
				map<int,int> :: iterator it;
				for(it=add.begin();it!=add.end();it++)
				{
					int t1=it->first,t2=it->second;
					for(int j=0;j<m[t1].size();j++)
					{
						val[m[t1][j]]+=t2;
					}
				}
				add.clear();
			}
			printf("%d\n",val[x]);
		}
	}
	return 0;
}

