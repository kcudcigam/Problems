#include<bits/stdc++.h>
#define P 1000000007
using namespace std;
long long f[301][301];
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<i;k++)
			{
				f[i][j]+=f[k][j]*f[i-k][j];
				f[i][j]=f[i][j]%P;
			}
			for(int k=1;k<j;k++)
			{
				f[i][j]+=f[i][k]*f[i][j-k];
				f[i][j]=f[i][j]%P; 
			}
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
