#include<bits/stdc++.h>
using namespace std;
int const p=1e9+7;
int ans=0;
int n,pri;
int now[1001],a[1001],b[1001],c[1001];
void dfs(int x)
{
	for(now[x]=-c[x];now[x]<=b[x];now[x]++)
	{
		if(x!=1)dfs(x-1);
		else
		{
			int t=0,t2=0,t3=1000000001;
			for(int i=1;i<=n;i++)
			{
				t+=a[i]*now[i],t2+=a[i]*max(0,now[i]);
				if(now[i]>0)t3=min(t3,a[i]);
			}
			if(t==pri&&t3>(t2-t))ans++,ans%=p;
		}
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&pri);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	dfs(n);
	printf("%d",ans);
	return 0;
}
