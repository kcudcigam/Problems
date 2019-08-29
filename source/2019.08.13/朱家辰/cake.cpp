#include<bits/stdc++.h>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll f[310][310];
int m,n;
void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	fread(n),fread(m);
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<i;k++)
			f[i][j]=(f[i][j]+(f[k][j]*f[i-k][j])%mod)%mod;
			for(int k=1;k<j;k++)
			f[i][j]=(f[i][j]+(f[i][k]*f[i][j-k])%mod)%mod;
		}
	}
	printf("%lld",f[n][m]);
	return 0;
}


