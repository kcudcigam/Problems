#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll n,m,f[305][305];
inline void add(ll&x,ll y)
{
	x=(x+y%mod+mod)%mod;
}
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	f[1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			for(int k=1;k<j;++k)
				add(f[i][j],f[i][k]*f[i][j-k]);
			for(int k=1;k<i;++k)
				add(f[i][j],f[k][j]*f[i-k][j]);
		}
	cout<<f[n][m]<<endl;
	return 0;
}

