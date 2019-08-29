#include<iostream>
#include<cstdio>
#define Mod 1000000007
using namespace std;
int n,m;
long long f[309][309];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d %d",&n,&m);
	f[1][1]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			for(int k=1;k<i;++k) f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%Mod;
			for(int k=1;k<j;++k) f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%Mod;
		}
	printf("%lld",f[n][m]);
	return 0;
}
