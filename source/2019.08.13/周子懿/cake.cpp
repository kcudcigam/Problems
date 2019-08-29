#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int N=310;
ll f[N][N];
int n,m;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<j;k++)
			{
				f[i][j]=(f[i][j]+f[i][k]*f[i][j-k]%MOD)%MOD;
			}
			for(int k=1;k<i;k++)
			{
				f[i][j]=(f[i][j]+f[k][j]*f[i-k][j]%MOD)%MOD;
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}



