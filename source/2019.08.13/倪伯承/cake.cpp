#include<bits/stdc++.h>
using namespace std;

int n,m;
long long f[310][310];
long long my_mod = 1000000007;

int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	f[1][1] = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			for(int z = 1;z < i;z++)
			{
				f[i][j] = (f[i][j] + f[z][j] * f[i - z][j]) % my_mod;
			}
			for(int z = 1;z < j;z++)
			{
				f[i][j] = (f[i][j] + f[i][z] * f[i][j - z]) % my_mod;
			}
		}
	}
	cout<<f[n][m];
	return 0;
}


