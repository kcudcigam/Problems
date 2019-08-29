#include<cstdio>
int n,a[100010];
long long ans;
void getAns()
{
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k;l<=n;l++)
					if(a[j]-a[i-1]+a[l]-a[k-1]>ans) ans=a[j]-a[i-1]+a[l]-a[k-1];
	return ;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	getAns();
	printf("%lld\n",ans);
	return 0;
}
