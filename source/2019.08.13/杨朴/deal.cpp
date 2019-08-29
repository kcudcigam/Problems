#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5;
const int HA=1000000007;
int n,X,a[MAXN],b[MAXN],c[MAXN],f1[MAXN],f2[MAXN],ans;
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&X);
	f1[0]=f2[0]=1;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",a+i,b+i,c+i);
	for(int i=n;i;i--)
		for(int k=X+a[n]-1;k>=1;k--)
			for(int j=1;j<=b[i]&&k-a[i]*j>=0;j++)
			{
				if(k-j*a[i]>=X)
					break;
				f1[k]=(f1[k]+f1[k-j*a[i]])%HA;
			}
	for(int i=n;i;i--)
		for(int k=X+a[n]-1;k>=1;k--)	
			for(int j=1;j<=c[i]&&k-a[i]*j>=0;j++)
				f2[k]=(f2[k]+f2[k-j*a[i]])%HA;
	for(int i=0;i<=X+a[n]-1;i++)
		ans=(ans+(1LL*f1[X+i]*f2[i])%HA)%HA;
	printf("%d",ans);
	return 0;
}
