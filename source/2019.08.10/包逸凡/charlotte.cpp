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
#define mp make_pair
#define fi first
#define se second

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}
inline bool sol() {
	int n , px = 0 , py = 0 , stp = 0 , ret = 1;
	read(n);
	while (n--) {
		int t , x , y;
		read(t); read(x); read(y);
		int cst = abs(x - px) + abs(y - py);
		px = x , py = y;
		if (stp + cst > t) ret = false;
		stp += cst;
		if ((t - stp) & 1) ret = false;
	}
	return ret;
}

int main() {
	
	#ifndef evenbao
	freopen("charlotte.in" , "r" , stdin);
	freopen("charlotte.out" , "w" , stdout);
	#endif
	
	int T;
	read(T);
	while (T--) {
		if (sol()) puts("Yes");
		else puts("No");
	}
	
	return 0;
} 
