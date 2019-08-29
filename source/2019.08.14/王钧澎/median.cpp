#include<bits/stdc++.h>
#define MAXN 500010

using namespace std;

int n , m;
int a[MAXN] , b[MAXN];
bool f;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f; 
} 

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> inline void print(T x) {
	if (x / 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void write(T x) {
	print(x);
	putchar('\n');
}

inline int chcka(int l , int r , int s) {
	int ll = l , rr = r;
	int ans = 0;
	while(ll <= rr) {
		int mid = (ll + rr + 1) >> 1;
		if (a[mid] <= s) {
			chkmax(ans , mid - l + 1);
			ll = mid + 1;
		}
		else {
			rr = mid - 1;
		}
	}
	return ans;
}

inline int chckb(int l , int r , int s) {
	int ll = l , rr = r;
	int ans = 0;
	while(ll <= rr) {
		int mid = (ll + rr + 1) >> 1;
		if (b[mid] < s) {
			chkmax(ans , mid - l + 1);
			ll = mid + 1;
		}
		else {
			rr = mid - 1;
		}
	}
	return ans;
}

inline int fd(int l , int r , int ll , int rr) {
	int aa = l , bb = r;
	int t = (r - l + rr - ll + 3) >> 1;
	while(aa <= bb) {
		int mid = (aa + bb + 1) >> 1;
		int p = chckb(ll , rr , a[mid]) + mid - l;
		if (p == t - 1) {
			f = 0; return mid;
		}
		else {
			if(p < t - 1) {
				aa = mid + 1;
			}
			else bb = mid - 1;
		}
	}
	aa = ll; bb = rr;
	while(aa <= bb) {
		int mid = (aa + bb + 1) >> 1;
		int p = chcka(l , r , b[mid]) + mid - ll;
		if (p == t - 1) {
			f = 1; return mid;
		}
		else {
			if(p < t - 1) {
				aa = mid + 1;
			}
			else bb = mid - 1;
		}
	}
}

int main() {
	
	freopen("median.in" , "r" , stdin);
	freopen("median.out" , "w" , stdout);
	
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		read(b[i]);
	}
	
	while(m--) {
		int opt;
		read(opt);
		if (opt == 1) {
			int x , y , z;
			read(x); read(y); read(z);
			if (x) b[y] = z;
			else a[y] = z;
		}
		else {
			int l , r , ll , rr;
			read(l); read(r); read(ll); read(rr);
			int pcf = fd(l , r , ll , rr);
			if (f) {
				write(b[pcf]);
			}
			else write(a[pcf]);
		}
	}
	
	return 0;
}
