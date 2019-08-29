#include<bits/stdc++.h>
using namespace std;
long long ans2,n,m,maxx,g[10],l,r,a[10000005];
int sum(int x)
{
	long long ans;
	ans=0;
	int i,z;
	z=x;
	for(i=1;i<=5;i++)
	{
		ans+=z*g[i];
		z=z*x;
	}
	return ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=5;i++)
	{
		scanf("%d",&g[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		for(j=l;j<=r;j++)
		{
			a[j]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		if(a[i]==n) break;
		else
		{
			maxx=max(a[i],maxx);
		}
	}
	if(i>m)
	{
		ans2=sum(maxx)+sum(n-maxx);
		printf("%lld",ans2);
	}
	else printf("%lld",sum(n));
	return 0;
}
