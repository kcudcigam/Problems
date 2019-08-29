#include <iostream>
#include <cstdio>
using namespace std;

const long long mod=1e9+7;

long long f[305][305][5];

int main(void) {
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	//不切也是一种方案 
	f[1][1][0]=f[1][1][1]=f[1][1][2]=1ll;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) {
			if(i==1&&j==1)continue;
			//横切 
			for(int k=1;k<i;++k)f[i][j][1]=(f[i][j][1]+f[k][j][0]*f[i-k][j][0]%mod)%mod;
			//竖切 
			for(int k=1;k<j;++k)f[i][j][2]=(f[i][j][2]+f[i][k][0]*f[i][j-k][0]%mod)%mod;
			//统计 
			f[i][j][0]=(f[i][j][1]+f[i][j][2])%mod;
		}
	cout<<f[n][m][0];
	
	fclose(stdin);
	fclose(stdout);
}
