#include<cstdio>
const long long DWT=1000000007;
int n,m;
long long f[310][310][5];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[1][1][1]=f[1][1][2]=f[1][1][3]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) continue;
			for(int k=1;k<i;k++) f[i][j][2]=(f[i][j][2]+f[k][j][1]*f[i-k][j][1]%DWT)%DWT;
			for(int k=1;k<j;k++) f[i][j][3]=(f[i][j][3]+f[i][k][1]*f[i][j-k][1]%DWT)%DWT;
			f[i][j][1]=(f[i][j][2]+f[i][j][3])%DWT;
		}
	}
	printf("%lld\n",f[n][m][1]);
	return 0;
}
