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

int n;

int main(void)
{
	file("tree");
	read(n);
	while (n--) puts("No");
    return 0;
}

/*

*/


