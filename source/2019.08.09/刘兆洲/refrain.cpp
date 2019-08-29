//Program by Liu Zhaozhou
#include <bits/stdc++.h>

#define lowbit(x) x & -x

using namespace std;

namespace Base {
	inline char gc(void) {
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}

	#define gc() getchar()

	template <class T> void read(T &x) {
		T flg = 1; x = 0; static char ch = gc();
		for (; !isdigit(ch); ch = gc()) if (ch == '-') flg = -flg;
		for (; isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + ch - '0';
		x *= flg; return;
	}

	template <class T> inline void write(T x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) write(x / 10);
		putchar(x % 10 + 48);
	}

	template <class T> inline void writeln(T x, char c = '\n') { write(x), putchar(c); }

	template <class T> inline void chkmax(T&x, const T y) { x = x > y ? x : y; }
	template <class T> inline void chkmin(T&x, const T y) { x = x < y ? x : y; }
	template <class T> inline T max(const T x, const T y, const T z) { return max(x, max(y, z)); }

	inline void file(string str) {
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}

	#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
	#define Mp(x, y) make_pair(x, y)

	typedef long long ll;
	typedef unsigned long long ull;
	typedef long double lb;
}

using namespace Base;

enum {
	Maxn = 1005
};

const int mod = 1e9 + 7;

int num, n, m1, m2, p[Maxn], s[Maxn];
int g[Maxn][Maxn]; int ans = 0;
int db[55] = {0,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,227020758,178290591,674358851,789741546,425606191,660911389,557316307,146326063,72847302,602640637,860734560,657629300,440732388,459042011,394134213,35757887,36978716,109361473,390205642,486580460,57155068,943272305,14530444,523095984,354551275,472948359,444985875,799434881,776829897,626855450,954784168,10503098,472639410,741412713,846397273,627068824,726372166,318608048};

int main(void) {
	file("refrain");
	read(num);
	read(n), read(m1), read(m2);
	for (int i = 1, x, y; i <= m1; i++)
		read(x), read(y), s[x] = s[y] = g[x][y] = g[y][x] = 1;
	for (int i = 1, x, y; i <= m2; i++)
		read(x), read(y), s[x] = s[y] = g[x][y] = g[y][x] = 2;
	for (int i = 1; i <= n; i++) p[i] = i;
	
	if (n <= 10) {
		do {
			bool flg = false;
			for (int i = 1; i <= n; i++) {
			if (flg) break;
			for (int j = i + 1; j <= n; j++)
				if (g[i][j] ^ g[p[i]][p[j]]) {
					ans++; flg = true; break;
				}
			}
			if (ans > mod) ans -= mod;
		} while (next_permutation(p + 1, p + n + 1));
		writeln(ans); return 0;
	} else {
		for (int k = 1; k <= min(500000, db[n] + 1); k++) {
			bool flg = false;
			for (int i = 1; i <= n; i++) {
			if (flg) break;
			for (int j = i + 1; j <= n; j++)
				if (g[i][j] ^ g[p[i]][p[j]]) {
					ans++; flg = true; break;
				}
			}
			if (ans > mod) ans -= mod;
			random_shuffle(p + 1, p + n + 1);
		} writeln(ans);
	}
	
	

	return 0;
}


