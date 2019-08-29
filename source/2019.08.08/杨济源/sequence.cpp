#include<bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
	int f = 1; x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}
const int N = 5e5 + 5;
int n, m;
LL sum[N];
struct BIT
{
	LL tree[N << 2];
	
	inline int lowbit(int x) { return x & (-x); }
	
	inline void add(int x, int val)
	{
		for (; x <= n; x += lowbit(x)) tree[x] += val;
	}
	
	inline void add(int l, int r, int val) { add(l, val); add(r + 1, -val); }
	
	inline LL query(int x)
	{
		LL ans = 0;
		for (; x; x -= lowbit(x)) ans += tree[x];
		
		return ans;
	}
}sol;
int main(){
	freopen ("sequence.in", "r", stdin);
	freopen ("sequence.out", "w", stdout);
	
	read(n); read(m);
	
	int l, r, s, e;
	for (int i = 1; i <= m; i++)
	{
		read(l); read(r); read(s); read(e);
		
		sum[l] += s;
		sum[r + 1] -= e;
		
		sol.add(l + 1, (e - s) / (r - l));
		sol.add(r + 1, -(e - s) / (r - l));
	}
	
	LL ans = 0, now = 0;
	
	for (int i = 1; i <= n; i++)
	{
		now += sum[i] + sol.query(i);
		
		ans ^= now;
	}
	
	printf("%lld\n", ans);
  return 0;
}
