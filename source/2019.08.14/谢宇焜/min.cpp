#include<bits/stdc++.h>
#define ll long long
#define fir(a, b, c) for(register ll a = b; a <= c; a ++)
using namespace std;
inline int read(){
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

const int N = 2e5;
ll n, A, B, C, D;
ll a[N+5] , b[3005][3005];
ll dp[3005];

inline ll work(ll p){
	return (p*p*p*A+p*p*B+p*C+D);
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n = read(); A = read(); B = read(); C = read(); D = read();
	
	fir(i, 0, n)
		fir(j, 0, n)
			b[i][j] = INT_MAX;
	fir(i, 1, n) {
		a[i] = read();
		b[i][i] = a[i];
		fir(j, 1, i-1)
			b[i][j] = b[j][i] = min(b[j][i-1], a[i]); 
	}
	
	fir(i, 1, n){
		dp[i] = work(b[1][i]);
		fir(j, 1, i-1)
			dp[i] = max(dp[j] + work(b[j+1][i]), dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}

