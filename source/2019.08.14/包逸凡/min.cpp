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
#define MP make_pair
#define fi first
#define se second
#define int LL
const int N = 2e5 + 10;
const int MAXLOG = 20;
const LL INF = 1e18;

int n;
int p[N][MAXLOG] , lg[N];
LL st[N][MAXLOG] , a[N];
LL mx[N << 2] , tag[N << 2] , dp[N];
LL A , B , C , D;

template <typename T> inline void chkmax(T &x , T y) { x = y > x ? y : x; }
template <typename T> inline void chkmin(T &x , T y) { x = y > x ? y : x; }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
} 
inline LL F(LL x) {
	return A * x * x * x + B * x * x + C * x + D;
}
inline int query(int l , int r) {
	int k = lg[r - l + 1];
	if (st[l][k] < st[r - (1 << k) + 1][k]) return p[l][k];
	else return p[r - (1 << k) + 1][k];
}
inline void build(int now , int l , int r) {
	tag[now] = mx[now] = -INF;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(now << 1 , l , mid);
	build(now << 1 | 1 , mid + 1 , r);
}
inline void pushup(int now) {
	mx[now] = max(max(tag[now] , mx[now << 1]) , mx[now << 1 | 1]);
}
inline void modify(int now , int l , int r , int ql , int qr , LL val) {
	if (ql > qr) return;
	if (l == ql && r == qr) {
		chkmax(tag[now] , val);
		chkmax(mx[now] , val);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= qr) modify(now << 1 , l , mid , ql , qr , val);
	else if (mid + 1 <= ql) modify(now << 1 | 1 , mid + 1 , r , ql , qr , val);
	else {
		modify(now << 1 , l , mid , ql , mid , val);
		modify(now << 1 | 1 , mid + 1 , r , mid + 1 , qr , val);
	}
	pushup(now);
} 
inline LL query(int now , int l , int r , int ql , int qr) {
	if (ql > qr) return -INF;
	if (l == ql && r == qr) 
		return max(mx[now] , tag[now]);
	int mid = (l + r) >> 1;
	if (mid >= qr) return max(tag[now] , query(now << 1 , l , mid , ql , qr));
	else if (mid + 1 <= ql) return max(tag[now] , query(now << 1 | 1 , mid + 1 , r , ql , qr));
	else return max(max(query(now << 1 , l , mid , ql , mid) , query(now << 1 | 1 , mid + 1 , r , mid + 1 , qr)) , tag[now]);	
}
inline void solve(int l , int r) {
	if (l > r) return;
	int mid = query(l , r);
	LL val = F(a[mid]);
	if (l == r) {
		if (!l) return;
		dp[l] = max(query(1 , 0 , n , 0 , l - 1) + val , query(1 , 0 , n , l , l));
		modify(1 , 0 , n , l , l , dp[l]);
		return;
	}
	solve(l , mid - 1);
	LL dpv = query(1 , 0 , n , l , mid - 1);
	modify(1 , 0 , n , mid , r , dpv + val);
	if (mid) 
		dp[mid] = max(query(1 , 0 , n , 0 , mid - 1) + val , query(1 , 0 , n , mid , mid));
	modify(1 , 0 , n , mid , mid , dp[mid]);
	solve(mid + 1 , r);
}

signed main() {
	
	#ifndef evenbao
	freopen("min.in" , "r" , stdin);
	freopen("min.out" , "w" , stdout);
	#endif
	
	read(n); read(A); read(B); read(C); read(D);
	for (int i = 1; i <= n; ++i) read(a[i]);
	for (int i = 0; i <= n; ++i) { 
		st[i][0] = i ? a[i] : INF;
		p[i][0] = i;
	}
	for (int j = 1; j < MAXLOG; ++j) {
	for (int i = 0; i + (1 << j) - 1 <= n; ++i) {
		if (st[i][j - 1] <= st[i + (1 << (j - 1))][j - 1]) p[i][j] = p[i][j - 1];
		else p[i][j] = p[i + (1 << (j - 1))][j - 1];
		st[i][j] = min(st[i][j - 1] , st[i + (1 << (j - 1))][j - 1]);
	}
	}
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) dp[i] = -INF;
	for (int i = 1; i <= n + 1; ++i) lg[i] = (int)((double)log(i) / log(2.0));
	for (int i = 1; i <= n; ++i)
	for (int j = i - 1; j >= 0; --j)
		chkmax(dp[i] , dp[j] + F(a[query(j + 1 , i)]));
	if (n <= 1000) {
		cout<<dp[n]<<endl;
		return 0;
	}
	for (int i = 1; i <= n; ++i) dp[i] = -INF;
	build(1 , 0 , n);
	modify(1 , 0 , n , 0 , 0 , 0);
	solve(0 , n);
	LL ans = 0;
	printf("%lld\n" , dp[n]);
	
	return 0; 
}
