#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int p=1000000007;
const int MAXN=1010;

int n,x;
int a[MAXN],b[MAXN],c[MAXN];
int dp[MAXN][20010];

int main()
{
    freopen("deal.in","r",stdin);
    freopen("deal.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;++i)
    {
    	scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	if(n==1)
	{
		printf("1\n");
	}
	else
	{
		for(int i=1;i<=2*x+5;++i)
		{
			dp[1][i]=1;
		}
		for(int i=2;i<=n;++i)
		{
			for(int k=1;k<=2*x+5;++k)
			{
				for(int j=0;a[i]*j<=k;++j)
				{
					dp[i][k]=(dp[i][k]+dp[i-1][k-a[i]*j])%p;
				}
			}
		}
		printf("%d\n",dp[n][x]-1);
	}
	return 0;
}


