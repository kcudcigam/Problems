#include<bits/stdc++.h>
using namespace std;
long long f[310][310];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	f[1][1]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			for (int k=1;k<i;++k)	f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%1000000007;
			for (int k=1;k<j;++k)	f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%1000000007;
		}
	printf("%lld\n",f[n][m]);
	return 0;
}
