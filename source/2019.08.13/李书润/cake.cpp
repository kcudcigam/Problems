#include<bits/stdc++.h>
using namespace std;
int const p=1e9+7;
long long f[301][301];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	f[1][1]=1;
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++)
		{
			if(i==1&&j==1)continue;
			for(register int k=1;k<=i-1;k++)f[i][j]+=f[k][j]*f[i-k][j],f[i][j]%=p;
			for(register int k=1;k<=j-1;k++)f[i][j]+=f[i][k]*f[i][j-k],f[i][j]%=p;
		}
	printf("%lld",f[n][m]%p);
	return 0;
 } 
