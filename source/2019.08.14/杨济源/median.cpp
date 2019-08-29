#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
template <typename T> inline void write(T x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> inline void writeln(T x) { write(x); puts(""); }
const int N = 5e5 + 5;
int a[N], b[N];
int n, m; 
inline int check(register int l1, register int r1, register int l2, register int r2)
{
	register int l, r, mid, ans, p;
	register int k = ((r2 - l2 + 1) + (r1 - l1 + 1)) / 2 + 1;
	
	l = l1, r = r1; ans = -1;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		p = lower_bound(b + l2, b + r2 + 1, a[mid]) - b - l2 + 1;
		
		if (mid - l1 + 1 + p - 1 == k) return a[mid];
		if (mid - l1 + 1 + p - 1 < k)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	l = l2; r = r2; ans = -1;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		p = lower_bound(a + l1, a + r1 + 1, b[mid]) - a - l1 + 1;
		
		if (mid - l2 + 1 + p - 1 == k) return b[mid];
		if (mid - l2 + 1 + p - 1 < k)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return b[ans];
}
int main(){
	freopen ("median.in", "r", stdin);
	freopen ("median.out", "w", stdout);
	read(n); read(m);
	for (register int i = 1; i <= n; i++) read(a[i]);
	for (register int i = 1; i <= n; i++) read(b[i]);
	
	register int op;
	register int x, y, z;
	register int l1, r1, l2, r2;
	for (register int i = 1; i <= m; i++)
	{
		read(op);
		if (op == 1)
		{
			read(x); read(y); read(z);
			if (x == 0) a[y] = z;
			else b[y] = z;
		}
		else
		{
			read(l1); read(r1); read(l2); read(r2);
			writeln(check(l1, r1, l2, r2));
		}
	}
  return 0;
}
