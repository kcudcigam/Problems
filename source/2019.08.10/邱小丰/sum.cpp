#include<iostream>
#include<cstdio>
#define ll long long
const int maxn=100005;
const ll inf=-0x3f3f3f3f;
using namespace std;
int n;
ll a[maxn],sum[maxn],maxD[maxn],minA_1[maxn],maxB_A_1[maxn],max_maxB_A_1[maxn],ans=inf;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	
	maxD[n+1]=inf;
	for(int i=n;i>=2;i--)
	maxD[i]=max(maxD[i+1],sum[i]);
	
	minA_1[0]=-inf;
	for(int i=1;i<=n-2;i++)
	minA_1[i]=min(minA_1[i-1],sum[i]);
	
	minA_1[0]=0;
	for(int i=1;i<=n-1;i++)
	maxB_A_1[i]=sum[i]-minA_1[i-1];
	
	max_maxB_A_1[0]=inf;
	for(int i=1;i<=n-1;i++)
	max_maxB_A_1[i]=max(max_maxB_A_1[i-1],maxB_A_1[i]);
	
	for(int i=1;i<=n-1;i++)
	ans=max(ans,-sum[i]+maxD[i+1]+max_maxB_A_1[i]);
	
	cout<<ans<<endl;
	return 0;
}
