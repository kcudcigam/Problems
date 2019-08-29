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
const int N = 5e5 + 10;
const int INF = 2e9;

int n , q;
int a[N] , b[N];

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
 	freopen("median.in" , "r" , stdin);
 	freopen("median.out" , "w" , stdout);
 	#endif
 	
 	read(n); read(q);
 	for (int i = 1; i <= n; ++i) read(a[i]);
 	for (int i = 1; i <= n; ++i) read(b[i]);
 	while (q--) {
 		int type;
		read(type);
		if (type == 1) {
			int x , y , z;
			read(x); read(y); read(z);
			if (!x) a[y] = z;
			else b[y] = z;
		} else {
			int l1 , r1 , l2 , r2;
			read(l1); read(r1); read(l2); read(r2);
			int goal = (r1 - l1 + 1 + r2 - l2 + 1) / 2 + 1;
			int lef = 1 , rig = min(goal , r1 - l1 + 1) , res = INF;
			while (lef <= rig) {
				int mid = (lef + rig) >> 1;
				int pos = l2 + goal - mid - 1;
				if (pos < l2 || (pos <= r2 && b[pos] <= a[l1 + mid - 1])) {
					chkmin(res , a[l1 + mid - 1]);
					rig = mid - 1;
				} else lef = mid + 1;
			}
			lef = 1 , rig = min(goal , r2 - l2 + 1);
			while (lef <= rig) {
				int mid = (lef + rig) >> 1;
				int pos = l1 + goal - mid - 1;
				if (pos < l1 || (pos <= r1 && a[pos] <= b[l2 + mid - 1])) {
					chkmin(res , b[l2 + mid - 1]);
					rig = mid - 1;
				} else lef = mid + 1;
			}
			printf("%d\n" , res);
		}
	}
	return 0;
} 
