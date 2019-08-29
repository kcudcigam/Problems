//Program written by Liu Zhaozhou ~~~
#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <deque>
#include <string>

#define lowbit(x) x & -x

//#pragma GCC optimize(3)

using namespace std;

namespace Base {
inline char gc(void)
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

#define gc() getchar()

template <class T> inline void read(register T &x)
{
    static T flag = 1; x = 0;
    register char ch = gc();
    for (; !isdigit(ch); ch = gc()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = gc()) x = (x << 1) + (x << 3) + (ch ^ 48);
    x *= flag; return;
}

template <class T> inline void write(register T x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

template <class T> inline void writeln(register T x) {write(x); puts("");}
template <class T> inline void writeln(T x, char c) {write(x); putchar(c);}
template <class T> inline void writeln(char c, T x) {putchar(c); write(x);}

template <class T> inline void chkmax(T &x, const T y) {x > y ? x = x : x = y;}
template <class T> inline void chkmin(T &x, const T y) {x < y ? x = x : x = y;}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}

#define Ms(arr, opt) memset(arr, opt, sizeof(arr))

}

using namespace Base;

enum {
	maxpool = 1005
};

int f[maxpool][maxpool][2];

int n, m, a[maxpool], ans = 0;

int main(void)
{
	file("toy");
	read(n); read(m);
	for (register int i = 1; i <= n; i++)
		read(a[i]);
	
	Ms(f, 0x3f);
	f[1][1][1] = a[1]; f[0][0][0] = f[1][0][0] = 0;
	for (register int i = 2; i <= n; i++) {
		for (register int j = 0; j <= (i / 2) + (i % 2); j++)
		{
			f[i][j][1] = min(f[i - 1][j - 1][0],
			 f[i - 2][j - 1][1]) + a[i];
		//	cout << i << ' ' << j << ' ' << f[i][j][1] << endl;
			if (f[i][j][1] <= m) {
				chkmax(ans, j);
			}
			f[i][j][0] = min(f[i - 1][j][1], f[i - 1][j][0]);
		//	cout << i << ' ' << j << ' ' << f[i][j][0] << endl;
		}
	}
	writeln(ans);
    return 0;
}

/*

*/


