#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007

ll f[305][305];
ll n,m;

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin >> n >> m;
	f[1][1] = 1;
	ll i,j,k;
	for(i = 1;i <= n;i++)
		for(j = 1;j <= m;j++){
			if(i == 1 && j == 1)continue;
			f[i][j] = 0;
			for(k = 1;k < i;k++)f[i][j] = (f[i][j] + f[k][j] * f[i-k][j] % mod) % mod;
			for(k = 1;k < j;k++)f[i][j] = (f[i][j] + f[i][k] * f[i][j-k] % mod) % mod;
	}
/*	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++)cout<<f[i][j]<<" ";cout<<endl;
	}*/
	cout<<f[n][m]<<endl;
	return 0;
}

