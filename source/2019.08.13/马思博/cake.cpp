#include<bits/stdc++.h>
using namespace std;

const long long mo=1e9+7;
long long f[305][305];

int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
    int n,m;
    cin>>n>>m;
    f[1][1]=1;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
    {
    	for(int k=1;k<j;k++)
    	   f[i][j]=(f[i][j]+f[i][k]*f[i][j-k]%mo)%mo;
    	for(int k=1;k<i;k++)
    	   f[i][j]=(f[i][j]+f[k][j]*f[i-k][j]%mo)%mo;
	}
	cout<<f[n][m];
	return 0;
}


