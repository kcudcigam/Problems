#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[305][305];
const int mod=1000000007;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(i==1&&j==1)continue;
		for(int k=1;k<=i-1;k++)
		f[i][j]=(f[i][j]+f[k][j]*f[i-k][j]%mod)%mod;
		for(int k=1;k<=j-1;k++)
		f[i][j]=(f[i][j]+f[i][k]*f[i][j-k]%mod)%mod;		
	}
	printf("%lld\n",f[n][m]);
} 
