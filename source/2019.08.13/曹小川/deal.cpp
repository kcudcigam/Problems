#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
template <typename T> inline void read(T &n){
	n = 0; T f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
int n, X, Y;
int tl[10010], maxn;
struct mfs{
	int tot, w;
}ts[1010];
long long fs[10010], fl[20010];
long long ans;
int main(){
	FO("deal");
	read(n), read(X);
	for (int i = 1; i <= n; ++i){
		int a, b, c;
		read(a), read(b), read(c);
		tl[a] += b;
		ts[i].tot = c;
		ts[i].w = a;
		maxn = max(maxn, a);
	}
	fs[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = maxn; j >= 0; --j)
			if (fs[j])
				for (int k = 1; k <= ts[i].tot && j + k * ts[i].w <= maxn; ++k)
					fs[j + k * ts[i].w] = (fs[j + k * ts[i].w] + fs[j]) % mod;
	fl[0] = 1;
	for (int i = maxn + X - 1; i >= X; --i){
		int v = i - X + 1;
		if (tl[v]){
			for (int j = i; j >= 0; --j)
				if (fl[j])
					for (int k = 1; k <= tl[v] && j + k * v <= i; ++k)
						fl[j + k * v] = (fl[j + k * v] + fl[j]) % mod;
		}
		ans = (ans + fl[i] * fs[i - X]) % mod;
	}	
	cout << ans << endl;
	return 0;
}
