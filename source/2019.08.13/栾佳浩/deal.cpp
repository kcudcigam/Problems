#include<bits/stdc++.h>
using namespace std;
int n,x;
int v[10005];
int m1[10005];
int m2[10005];
long long f1[105][205][105];
long long f2[105][205];
long long s1[20005],s2[20005];
const int mod=1000000007;
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	scanf("%d%d",&n,&x);
	if(n>100)
	{
	puts("0");	
	return 0;
	}
	int maxval=-1;
	for(int i=1;i<=n;i++)
	{
		int val,num1,num2;
		scanf("%d%d%d",&val,&num1,&num2);
		maxval=max(maxval,val);
		v[i]=val;
		m1[i]=num1;
		m2[i]=num2;
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=0;j<=m1[i];j++)
	f1[i][j*v[i]][i]=1;	
	for(int k=1;k<i;k++)
	for(int j=1;j<x+v[k];j++)
	{
	f1[i][j][k]=f1[i-1][j][k];
	for(int l=1;l<=m1[i];l++)
	{
		if(j-l*v[i]<=0)continue;
		f1[i][j][k]=(f1[i][j][k]+f1[i-1][j-l*v[i]][k])%mod;	
	}
	}
	}
	f2[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m2[i];j++)
		{
			
		for(int k=0;k<x+maxval;k++)
		{
			if(k<j*v[i])continue;
			f2[i][k]=(f2[i][k]+f2[i-1][k-j*v[i]])%mod;
		}
		}
	}
	long long ans=0;	
	for(int i=x;i<x+maxval;i++)
	{
		long long r1=0,r2=0;
		for(int j=1;j<=n;j++)
		{
			r1=(r1+f1[n][i][j])%mod;
		}
		ans=(ans+1ll*r1*f2[n][i-x]%mod)%mod;
	}
	printf("%lld",ans);
}
