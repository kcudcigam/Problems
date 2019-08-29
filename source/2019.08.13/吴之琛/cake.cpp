#include<bits/stdc++.h>
#define Mod 1000000007
#define ll long long
#define N 310
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int n,m;
ll f[N][N];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	read(n);read(m);
	f[1][1]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			for (int k=1;k<i;k++) f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%Mod;
			for (int k=1;k<j;k++) f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%Mod;
		}
	printf("%lld\n",f[n][m]);
	return 0;
}

