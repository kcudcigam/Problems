#include<bits/stdc++.h>
#define int long long
using namespace std;
int x1,x2,x3,x4,x5;
int n,m,l[300],r[300];
inline int g(int x)
{
	return x*x*x*x*x*x5+x*x*x*x*x4+x*x*x*x3+x*x*x2+x1*x;
}
bool a[300];
int dfs()
{
	int Max=-1;
	for(int i=1;i<=m;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(l[j]<=i && r[j]>=i && a[j]==0)	sum++;
		}
		Max=max(Max,sum);
	}
	if(Max==0)  return 0;
	int ans=-1;
	for(int i=1;i<=m;i++)
	{
		int sum=0;bool temp[300]={0};
		for(int j=1;j<=n;j++)
		{
			if(l[j]<=i && r[j]>=i && a[j]==0)
			{
				sum++;
				temp[j]=true;
			}
		}
		if(sum==Max)
		{
			for(int i=1;i<=n;i++)
			{
				if(temp[i]==1)  a[i]=1;
			}
			ans=max(ans,g(sum)+dfs());
			for(int i=1;i<=n;i++)
			{
				if(temp[i]==1)  a[i]=0;
			}
		}
	}
	return ans;
}
signed main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld%lld%lld%lld%lld",&x1,&x2,&x3,&x4,&x5);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		if(l[i]!=1 || r[i]!=m)  flag=false;
	}
	if(flag==true)
	{
		printf("%lld\n",g(m));
		return 0;
	}
	printf("%lld\n",dfs());
	return 0;
}
