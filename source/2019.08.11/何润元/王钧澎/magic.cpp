#include<bits/stdc++.h>
#define ll long long
#define pmod 998244353

using namespace std;

ll n;
string st;
int len;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
} 

template <typename T> inline void chkmax(T &x , T y) {x = x > x ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

ll ksm(ll x , ll y) {
	ll s = 1;
	while(y) {
		if (y & 1) s = s * x % pmod;
		x = x * x % pmod;
		y >>= 1;
	}
	return s % pmod;
}

int main() {
	
	freopen("magic.in" , "r" , stdin);
	freopen("magic.out" , "w" , stdout);
	
	read(n);
	char c = getchar();
	for (; c >= 'a' && c <= 'z'; c = getchar()) st = st + c;
	len = st.size();
	
	if (len == n) {
		cout << (ksm(26 , n) - 1 + pmod) % pmod;
		return 0;
	}
	ll ans = ksm(26 , n);
	ans = (ans - 25 * ksm(26 , n - len - 1) % pmod * len % pmod + pmod) % pmod;
	ans = (ans - ksm(26 , n - len) + pmod) % pmod;
	
	cout << ans << endl;
	
	return 0;
	
}
