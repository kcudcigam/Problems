//Program written by Liu Zhaozhou ~~~
#include <bits/stdc++.h>

#define lowbit(x) x & -x
#pragma GCC optimize("Ofast,inline")

using namespace std;

namespace Base {
	inline char gc(void)
	{
		static char buf[100000], *p1 = buf, *p2 = buf;
		return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
	}

	#define gc() getchar()

	template <class T> inline void read(T &x)
	{
		T flag = (T) 1; x = 0; static char ch = gc();
		for (; ch > '9' || ch < '0'; ch = gc())
			flag = ch == '-' ? -1 : 1;
		for (; ch >= '0' && ch <= '9'; ch = gc())
			x = (x << 1) + (x << 3) + (ch & 15);
		x *= flag; return;
	}

	inline void readstr(string&x) {
		x = ""; static char ch;
		while (isspace(ch = gc()));
		while (x += ch, !isspace(ch = gc()));
	}

	inline void readstr(char *s) {
		do *s = gc(); while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
		do *(++s) = gc(); while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
		*s = 0; return;
	}

	inline void printstr(string x, int num = 0, char ch = '\n') {
		for (int i = num; i < x.size(); ++i)
			putchar(x[i]); putchar(ch);
	}

	inline void readch(char&x) {while (isspace(x = gc()));}

	char pf[100000], *o1 = pf, *o2 = pf + 100000;
	#define ot(x) (o1 == o2 ? fwrite(pf, 1, 100000, stdout), *(o1 = pf) ++= x : *o1 ++= x)
	template <class T>
	inline void println(T x, char c = '\n') {
		if (x < 0) ot(45), x = -x;
		static char s[15], *b; b = s;
		if (!x) *b ++= 48;
		for (; x; * b ++= x % 10 + 48, x /= 10);
		for (; b-- != s; ot(*b)); ot(c);
	}

	template <class T> inline void write(T x)
	{
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0'); return;
	}

	template <class T> inline void writeln(T x) {write(x); puts("");}
	template <class T> inline void writeln(T x, char c) {write(x); putchar(c);}
	template <class T> inline void writeln(char c, T x) {putchar(c); write(x);}

	template <class T> inline void chkmax(T &x, const T y) {x > y ? x = x : x = y;}
	template <class T> inline void chkmin(T &x, const T y) {x < y ? x = x : x = y;}
	template <class T> inline T max(const T&x, const T&y, const T&z) {
		return x > y ? (x > z ? x : z) : (y > z ? y : z);
	}

	typedef long long ll;
	typedef unsigned long long ull;
	typedef long double ld;

	#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
	#define Mp(x, y) make_pair(x, y)

	inline void file(string str) {
		freopen((str + ".in").c_str(), "r", stdin);
		freopen((str + ".out").c_str(), "w", stdout);
	}
}

using namespace Base;

enum {
	Maxn = 410005
};

int n, a[Maxn], f[Maxn];
string str; int tmp, tnp, opt, sze, ret;
bool flg[Maxn];
priority_queue <int> Q[5], q[5];

int main(void) {
	file("debate");
//	f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - tmp[i]][k - tnp[i]] + a[i]);
	read(n);
	for (int i = 1; i <= n; i++) {
		readstr(str), read(a[i]);
		if (str[0] =='0' && str[1] == '0') q[0].push(a[i]);
		else if (str[0] == '1' && str[1] == '1') q[1].push(a[i]);
		else if (str[0] == '1' && str[1] == '0') q[2].push(a[i]);
		else q[3].push(a[i]);
	}
	opt = sze = 0;
	while (!q[2].empty() && !q[3].empty()) {
		++opt; sze += 2; ret += q[2].top() + q[3].top();
		q[2].pop(), q[3].pop();
	}// cout << opt << ' ' << sze << endl;

	while (!q[1].empty()) { ++opt; ++sze; ret += q[1].top(); q[1].pop(); }
//	if (!q[1].empty()) puts("1");
//	cout << opt << ' ' << sze << endl;
	tmp = opt * 2 - sze;// writeln(tmp);
//	for (int i = 0; i < 4; i++) writeln(q[i].size());
	while (tmp) {
		tnp = 0;// puts("1");
		if (q[0].empty() && q[1].empty() && q[2].empty() && q[3].empty()) break;
		for (int i = 0; i < 4; i++)
			if (!q[i].empty()) chkmax(tnp, q[i].top());
		for (int i = 0; i < 4; i++)
			if (!q[i].empty() && q[i].top() == tnp) { q[i].pop(); break; }
		--tmp; ret += tnp;
	} writeln(ret);

//	fwrite(pf, 1, o1 - pf, stdout);
	return 0;
}

/*
10
11 41
00 15
11 65
11 81
10 25
01 69
11 48
10 96
10 15
11 25
*/


