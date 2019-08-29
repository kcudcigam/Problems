#include<bits/stdc++.h>
#define R register
using namespace std;
const int N=200000+7;
int a[N];
int n=0;
long long d1[N],d2[N];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	long long ans=0;
	long long sum=0;
	for(R int i=1;i<=n;i++)
	{
		if(sum<0)sum=0;
		sum+=a[i];
		d1[i]=max(d1[i-1],sum);
	}
	sum=0;
	for(R int i=n;i>=1;i--)
	{
		if(sum<0)sum=0;
		sum+=a[i];
		d2[i]=max(d2[i+1],sum);
	}
	ans=0;
	for(R int i=2;i<=n-1;i++)
	{
		ans=max(ans,d1[i-1]+d2[i+1]);
	}
	printf("%lld",ans);
	return 0;
}
