#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define ULL unsigned long long
//#pragma GCC optimize("Ofast")
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
const LL mod = 1e9 + 7;
const int maxm = 1e5, maxn = 2e5;
int num, n, m1, m2, tot;
struct Edge {
	int from, to, nxt, d;
} edge[maxm * 4];
bool cmp(Edge x, Edge y) {
	return x.from < y.from || (x.from == y.from && x.to < y.to);
}
int head[maxn][3], f[maxn], iden[maxn], cnt[maxn];
void add_edge(int u, int v, int d) {
	edge[++tot].d = d; edge[tot].from = u;
	edge[tot].to = v; edge[tot].nxt = head[u][d]; head[u][d] = tot;
}
int rel[15][15], perm[15];
//int chains, loops;
LL fac[200020];
int getf(int x) {
	if(f[x] == x) return x;
	return f[x] = getf(f[x]);
}
bool check() {
	_rep(i, 1, n) {
		_rep(j, 1, n) {
			if(i == j) continue;
			if(rel[i][j] != rel[perm[i]][perm[j]]) return false;
		}
	}
	return true;
}
void sub1() {
	int ans = 0;
	_rep(i, 1, n) perm[i] = i;
	_rep(i, 1, tot) {
		rel[edge[i].from][edge[i].to] = edge[i].d;
		rel[edge[i].to][edge[i].from] = edge[i].d;
	}
	do {
		if(!check()) {
			ans++;
		} 
	} while(std::next_permutation(perm + 1, perm + n + 1));
	writesp(ans);
}
LL qpow(int a, int b, int p) {
	LL sum = 1;
	while(b) {
		if(b & 1) sum = 1ll * sum * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return sum;
}
int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	read(num); read(n); read(m1); read(m2);
	_rep(i, 1, n) f[i] = i;
	_rep(i, 1, m1) {
		int u, v; read(u); read(v);
		add_edge(u, v, 1);
	}
	_rep(i, 1, m2) {
		int u, v; read(u); read(v);
		add_edge(u, v, 2);
	}
	if(num <= 2) {
		printf("0\n");
		return 0;
	} else if(num >= 3 && num <= 6) {
		sub1(); return 0;
	} else {
		fac[1] = 1;
		_rep(i, 2, n) fac[i] = (1ll * fac[i - 1] * i) % mod; 
		if(num >= 11 && num <= 14) {
			printf("%d\n", (fac[n] - n + mod) % mod);
			return 0;
		} else if(num >= 7 && num <= 10) {
			int ans = (1ll * fac[n] - 1ll * fac[m1] * qpow(2, m1, mod) % mod * fac[m2] % mod * qpow(2, m2, mod) % mod + mod) % mod;
			printf("%d\n", ans);
			return 0;
		} else {
		//	std::sort(edge + 1, edge + tot + 1, cmp);
			_rep(i, 1, tot) {
				int fx = getf(edge[i].from), fy = getf(edge[i].to);
				if(fx == fy) {
					iden[fx] = 2;
				}
				f[fx] = fy;
			}
			LL ans = fac[n], acu = 1;
			_rep(i, 1, n) {
				if(getf(i) == i && !iden[i]) {
					iden[i] = 1;
				}
				cnt[getf(i)]++;
			//	std::cout << getf(i) << " ";
			}
			int x = 0;
			_rep(i, 1, n) {
				if(cnt[i]) {
				//	std::cout << i << " " << cnt[i] << " " << iden[i] << std::endl;
					if(iden[i] == 1) acu = (1ll * acu * (cnt[i] & 1? 1 : 2) % mod);
					else acu = (1ll * acu * cnt[i]) % mod;
					x++;
				//	std::cout << cnt[i] << " " << acu << std::endl;
				}
			}
		//	std::cout << ans << " " << x << std::endl;
			writesp((ans - acu + mod) % mod);
			return 0;
		}
	}
	return 0;
}

