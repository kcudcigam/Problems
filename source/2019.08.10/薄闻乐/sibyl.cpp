#include<bits/stdc++.h>
using namespace std;
vector <int> v[300001];
int n,m,q,a,b,c,ans[300001],Hash[300001];
int main()
{
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		if(a==0)
		{
			scanf("%d",&b);
			cout<<ans[b]<<endl;
			continue;
		}
		memset(Hash,0,sizeof(Hash));
		scanf("%d%d",&b,&c);
		for (int j=0;j<v[b].size();j++)
		{
			if(Hash[v[b][j]])
			continue;
			Hash[v[b][j]]=1;
			ans[v[b][j]]+=c;
		}
		ans[b]+=c;
	}
	return 0;
}
