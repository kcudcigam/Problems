#include<bits/stdc++.h>
#define N 305
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,m;
LL f[N][N];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			if (i==1&&j==1) f[i][j]=1;
			for (int k=1;k<i;++k) f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%mod;
			for (int k=1;k<j;++k) f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%mod;
		}
	cout<<f[n][m]<<'\n';
	return 0;
}
