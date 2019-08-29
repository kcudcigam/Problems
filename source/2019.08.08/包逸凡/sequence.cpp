#include<bits/stdc++.h>
using namespace std;

#ifndef LOCAL
	#define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int , int> pii;
typedef pair<ll , int> pli;
typedef pair<int , ll> pil;
typedef pair<ll , ll> pll;
#define MP make_pair
#define fi first
#define se second
#define int ll
const int N = 5e5 + 10;

int n , m , size , rt;
int lc[N << 2] , rc[N << 2] , fir[N << 2] , sec[N << 2];

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline void pushdown(int now , int l , int r) {
	int mid = (l + r) >> 1;
	if (!lc[now]) lc[now] = ++size;
	if (!rc[now]) rc[now] = ++size;
	int dt = (r - l) ? (sec[now] - fir[now]) / (r - l) : 0;
	fir[lc[now]] += fir[now];
	sec[lc[now]] += fir[now] + dt * (mid - l);
	fir[rc[now]] += fir[now] + dt * (mid - l + 1);
	sec[rc[now]] += sec[now];
	fir[now] = sec[now] = 0;
	return; 
}
inline void modify(int &now , int l , int r , int ql , int qr , int s , int e) {
	if (!now) now = ++size;
	if (l == ql && r == qr) {
		fir[now] += s;
		sec[now] += e;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(now , l , r);
	int dt = (qr - ql) ? (e - s) / (qr - ql) : 0;
	if (mid >= qr) modify(lc[now] , l , mid , ql , qr , s , e);
	else if	(mid + 1 <= ql) modify(rc[now] , mid + 1 , r , ql , qr , s , e);
	else {
		modify(lc[now] , l , mid , ql , mid , s , s + dt * (mid - l));
		modify(rc[now] , mid + 1 , r , mid + 1 , qr , s + dt * (mid - l + 1) , e);
	}
}
inline int query(int now , int l , int r) {
	if (l == r) return fir[now]; 
	pushdown(now , l , r);
	int mid = (l + r) >> 1;
	return query(now << 1 , l , mid) ^ query(now << 1 | 1 , mid + 1 , r);
}

signed main() {
	
	#ifndef evenbao
	freopen("sequence.in" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	#endif
	
	read(n); read(m);
	rt = 0;
	while (m--) {
		int l , r , s , e;
		read(l); read(r); read(s); read(e);
		modify(rt , 1 , n , l , r , s , e);
	}
	printf("%lld\n" , query(rt , 1 , n));
	
	return 0;
}


