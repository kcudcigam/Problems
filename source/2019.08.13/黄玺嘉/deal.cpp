#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,x,a[1010],b[1010],c[1010],ans,pay,back,tot,cnt;
long long f[310][310];

template <typename T> void read(T &x){
	x = 0; T f = 1; char c = getchar();
	for(;!isdigit(c); c = getchar()) if (c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = (x<<3)+(x<<1)+c-'0';
	x *= f;
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);
	read(x);
	for(int i = 1; i <= n; ++i){
		read(a[i]);
		read(b[i]);
		read(c[i]);
	}
	m = x;
	n %= 301;
	m %= 301;
	f[1][1] = 1; 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			for(int k = 1; k <= j/2-1; ++k) 
				f[i][j] += (f[i][k] * f[i][j-k]) % MOD + (f[i][k] * f[i][j-k]) % MOD;
			if(j & 1) 
				f[i][j] += (f[i][j/2] * f[i][j/2+1]) % MOD + (f[i][j/2] * f[i][j/2+1]) % MOD;
			else
				f[i][j] += (f[i][j/2] * f[i][j/2]) % MOD;
			for(int k = 1; k <= i/2-1; ++k)
				f[i][j] += (f[k][j] * f[i-k][j]) % MOD + (f[k][j] * f[i-k][j]) % MOD;
			if(i & 1)
				f[i][j] += (f[i/2][j] * f[i/2+1][j]) % MOD + (f[i/2][j] * f[i/2+1][j]) % MOD;
			else
				f[i][j] += (f[i/2][j] * f[i/2][j]) % MOD;
		}
	}
	return 0;
}


