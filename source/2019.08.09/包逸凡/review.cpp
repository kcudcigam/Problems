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
#define MP make_pair
#define fi first
#define se second
#define PB push_back
#define SZ(a) (int)(a.size())

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
	T f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
	x *= f;
}

int main() {
	
	#ifndef evenbao
	freopen("review.in" , "r" , stdin);
	freopen("review.out" , "w" , stdout);
	#endif
	
	LL Y;
	read(Y);
	if (Y == 1) {
		puts("2 1");
		puts("1 2");
		return 0;
	}
	vector< pii > res; res.clear();
	int now = 1;
	for (int i = 2; i <= 63; ++i) {
	    for (int j = 1; j < i; ++j) {
	    	res.PB(MP(j , i));
		}
	}
	for (int i = 0; i < 64; ++i) {
		if (Y & (1LL << i)) 
			res.PB(MP(i + 2 , 64));
	}
	printf("%d %d\n" , 64 , SZ(res));
	for (unsigned i = 0; i < SZ(res); ++i)
		printf("%d %d\n" , res[i].fi , res[i].se);
		
	return 0;
} 
