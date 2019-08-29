#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<LL , int> pli;
typedef pair<LL , LL> pll;
#define MP make_pair
#define fi first
#define se second

inline bool check_1(LL n) {
	set< int > s;
	while (n > 0) {
		s.insert(n % 10);
		n /= 10LL;
	}
	return (int)s.size() <= 2;
}
inline bool check_2(LL n) {
	int len = 0;
	int dig[22] , a[5] , b[5] , c[5] , d[5] , dp[22][5];
	while (n > 0) {
		dig[len++] = n % 10;
		n /= 10LL; 
	}
	for (int a1 = 0; a1 <= 9; ++a1)
	for (int a2 = 0; a2 <= 9; ++a2) 
	for (int b1 = 0; b1 <= 9; ++b1)
	for (int b2 = 0; b2 <= 9; ++b2) {
		a[1] = a1 , a[2] = a2 , b[1] = b1 , b[2] = b2;
		memset(dp , 0 , sizeof(dp));
		for (int i = 0; i < len; ++i) {
			for (int x = 0; x < 2; ++x)
			for (int y = 0; y < 2; ++y) {
				if ((a[x] + b[y] + 1) % 10 == dig[i]) {
					if (a[x] + b[y] + 1 >= 10) dp[i][1] |= (i ? dp[i - 1][1] : false);
					else dp[i][0] |= (i ? dp[i - 1][1] : false);
				} 
				if ((a[x] + b[y]) % 10 == dig[i]) {
					if (a[x] + b[y] >= 10) dp[i][1] |= (i ? dp[i - 1][0] : true);
					else dp[i][0] |= (i ? dp[i - 1][0] : true);
				} 
			}
			if (!dp[i][0] && !dp[i][1]) break;
		}
		if (dp[len - 1][0] || dp[len - 1][1])  
			return true;
	}
	return false;
}
inline bool check_3(LL n) {
	int len = 0;
	int dig[22] , a[5] , b[5] , c[5] , d[5] , dp[19][3];
	while (n > 0) {
		dig[len++] = n % 10;
		n /= 10LL;
	}
	for (int a1 = 0; a1 <= 9; ++a1)
	for (int a2 = 0; a2 <= 9; ++a2)
	for (int b1 = 0; b1 <= 9; ++b1)
	for (int b2 = 0; b2 <= 9; ++b2) 
	for (int c1 = 0; c1 <= 9; ++c1)
	for (int c2 = 0; c2 <= 9; ++c2) {
		a[1] = a1 , a[2] = a2 , b[1] = b1 , b[2] = b2 , c[1] = c1 , c[2] = c2;
		memset(dp , 0 , sizeof(dp));
		for (int i = 0; i < len; ++i) {
			for (int x = 0; x < 2; ++x)
			for (int y = 0; y < 2; ++y)
			for (int z = 0; z < 2; ++z) {
				if ((a[x] + b[y] + c[z] + 2) % 10 == dig[i]) {
					if (a[x] + b[y] + c[z] + 2 >= 20) dp[i][2] |= (i ? dp[i - 1][2] : false);
					else if (a[x] + b[y] + c[z] + 2 >= 10) dp[i][1] |= (i ? dp[i - 1][2] : false);
					else dp[i][0] |= (i ? dp[i - 1][2] : false);
				}
				if ((a[x] + b[y] + c[z] + 1) % 10 == dig[i]) {
					if (a[x] + b[y] + c[z] + 1 >= 20) dp[i][2] |= (i ? dp[i - 1][1] : false);
					else if (a[x] + b[y] + c[z] + 1 >= 10) dp[i][1] |= (i ? dp[i - 1][1] : false);
					else dp[i][0] |= (i ? dp[i - 1][1] : false);
				} 
				if ((a[x] + b[y] + c[z]) % 10 == dig[i]) {
					if (a[x] + b[y] + c[z] >= 20) dp[i][2] |= (i ? dp[i - 1][0] : true);
					else if (a[x] + b[y] + c[z] >= 10) dp[i][1] |= (i ? dp[i - 1][0] : true);
					else dp[i][0] |= (i ? dp[i - 1][0] : true);
				}
			}
			if (!dp[i][0] && !dp[i][1] && !dp[i][2]) break;
		}
		if (dp[len - 1][0] || dp[len - 1][1] || dp[len - 1][2]) return true;
	}
	return false;
} 
inline void chkmax(LL &x , LL y) {
	x = max(x , y);
}
inline LL sol(LL n) {
	int len = 0;
	LL tn = n;
	int dig[22];
	while (n > 0) {
		dig[len++] = n % 10;
		n /= 10LL;
	}
	reverse(dig , dig + len);
	LL ret = 0;
	for (int i = 0; i < dig[1]; ++i) {
		LL res = 1ll * dig[0] * 10 + i;
		for (int j = 2; j < len; ++j) res = 10ll * res + max(dig[0] , i);
		if (res <= tn) chkmax(ret , res);
	}
	LL res = dig[0];
	for (int i = 1; i < len; ++i) res = 10ll * res + max(i , dig[0]);
	if (res <= tn) chkmax(ret , res);
       res = dig[0];
	for (int i = 1; i < len; ++i) res = 10ll * res + dig[1];
	if (res <= tn) chkmax(ret , res);
	return ret;
} 
inline LL solve(LL n) {
	if (check_1(n)) return 1;
	else if (check_2(n)) return 2;
	else if (check_3(n)) return 3;
	else return solve(n - (LL)sol(n)) + 1;
}

int main() { 
	
	#ifndef evenbao
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	#endif
	
	int T;
	scanf("%d" , &T);
	while (T--) {
		LL n;
		scanf("%lld" , &n);
		if (check_1(n)) printf("1\n");
		else if (check_2(n)) printf("2\n");
		else if (check_3(n)) printf("3\n");
		else printf("%d\n" , solve(n));
	}

	return 0;
}
