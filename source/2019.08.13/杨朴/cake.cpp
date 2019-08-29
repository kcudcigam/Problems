#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL HA=1000000007;
LL n,m,f[305][305];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	f[1][1]=f[1][2]=f[2][1]=1;
	for(int i=1;i<=300;i++)
		for(int j=1;j<=300;j++)
		{
			if(f[i][j])
				continue;
			for(int k=1;k<i;k++)
				f[i][j]=(f[i][j]+(f[k][j]*f[i-k][j])%HA)%HA;
			for(int k=1;k<j;k++)
				f[i][j]=(f[i][j]+(f[i][k]*f[i][j-k])%HA)%HA;
		}
	scanf("%lld%lld",&n,&m);
	printf("%lld",f[n][m]);
	return 0;
}
