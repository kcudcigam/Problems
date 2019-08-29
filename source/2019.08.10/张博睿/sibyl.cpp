#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v,t,a;
long long ans,s[300002],b;
vector<int> g[300002];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&t);
		if(t==0)
		{
			scanf("%d",&a);
			ans=0+s[a];
			for(int j=0;j<g[a].size();j++) ans+=s[g[a][j]];
			printf("%lld\n",ans);
		}
		else
		{
			scanf("%d%lld",&a,&b);
			s[a]+=b;
		}
	}
	return 0;
}


