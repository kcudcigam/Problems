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

int k, a[25], _i[5], ans = 0;

bool h[17][17][17][17];

int t[1000005];

vector <int> vec[1000005];

inline void dfs() {
	
	if (_i[1] == 0 && _i[2] == 0 && _i[3] == 0 && _i[4] == 0)
		return;
	h[ _i[1] ][ _i[2] ][ _i[3] ][ _i[4] ] = 1;
	int s = 0;
	for (int e = 1; e <= 4; e++)
		s += _i[e] * pow(k + 1, e - 1);
		
	for (register int j = 1; j <= 4; j++) {
		if (_i[j] > 0)_i[j]--;
		if (_i[j] != 0) {
			for (register int k = j + 1; k <= 4; k++)
				if (_i[k] == 0) {
					_i[k] = a[_i[j]]; break;
				}
		}
	}
	int ss = 0;
	for (int e = 1; e <= 4; e++)
		ss += _i[e] * pow(k + 1, e - 1);
		cout <<s << ' ' <<ss << endl;
		
	if (ss != 0 && s != 0) vec[s].push_back(ss);
	if (h[ _i[1] ][ _i[2] ][ _i[3] ][ _i[4] ] == 1)
		return; dfs();
}

bool h2[1000005]; int du[1000005];

int cnt = 0, n;

inline void topposort(int dep) {
	queue <int> q;
	for (register int i = 1; i <= n; i++)
		if (du[i]) q.push(i);
	
	while (q.size()) {
		int u = q.front();
		q.pop(); ++cnt;
		writeln(cnt);
		for (register int i = 0; i < vec[u].size(); i++) {
			--du[vec[u][i]]; if (!du[vec[u][i]] && vec[u][i] != 0) q.push(vec[u][i]);
		}
	}
}

int main(void)
{
	file("bob");
	read(k);
	for (register int i = 1; i < k; i++)
		read(a[i]);
		
	for (_i[1] = 0; _i[1] <= k; _i[1]++)
	for (_i[2] = 0; _i[2] <= k; _i[2]++)
	for (_i[3] = 0; _i[3] <= k; _i[3]++)
	for (_i[4] = 0; _i[4] <= k; _i[4]++)
		if (!h[ _i[1] ][ _i[2] ][ _i[3] ][ _i[4] ]) dfs();
	n = k + k * (k + 1) + k * (k + 1) * (k + 1) + k * (k + 1) * (k + 1) * (k + 1);
	for (register int i = 1; i <= n; i++)
		for (register int e = 0; e < vec[i].size(); e++)
		du[vec[i][e]]++;
		
	
	writeln(cnt);
    return 0;
}

/*

*/


