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
const int N = 1e5 + 5;
const LL INF = 1e18;
LL a[N];
LL sum[N], ans = -INF;
int n, nowpla;

struct SegMentTree
{
	struct node
	{
		LL maxs, mins;
		int pla, l, r;
	}seg_tree[N << 2];
	
	#define lchild s << 1
	#define rchild s << 1 | 1
	
	inline void build(int s, int l, int r)
	{
		seg_tree[s].l = l;
		seg_tree[s].r = r;
		if (l == r)
		{
			seg_tree[s].maxs = seg_tree[s].mins = sum[l];
			seg_tree[s].pla = l;
			return;
		}
		int mid = (l + r) >> 1;
		build(lchild, l, mid);
		build(rchild, mid + 1, r);
		
		seg_tree[s].maxs = max(seg_tree[lchild].maxs, seg_tree[rchild].maxs);
		seg_tree[s].mins = min(seg_tree[lchild].mins, seg_tree[rchild].mins);
		
		if (seg_tree[lchild].maxs > seg_tree[rchild].maxs) seg_tree[s].pla = lchild;
		else seg_tree[s].pla = rchild;
	}
	
	inline LL querymin(int s, int l, int r)
	{
		if (seg_tree[s].l > r || seg_tree[s].r < l) return INF;
		
		if (seg_tree[s].l >= l && seg_tree[s].r <= r) return seg_tree[s].mins;
		
		return min(querymin(lchild, l, r), querymin(rchild, l, r));
	}
	
	inline LL querymax(int s, int l, int r)
	{
		if (seg_tree[s].l > r || seg_tree[s].r < l) return -INF;
		
		if (seg_tree[s].l >= l && seg_tree[s].r <= r) return seg_tree[s].maxs;
		
		return max(querymax(lchild, l, r), querymax(rchild, l, r));
	}
}sol;

inline void solve_60pts()
{
	for (int b = 1; b <= n - 1; b++)
	 for (int d = b + 1; d <= n; d++)
	  ans = max(ans, sum[b] + sum[d] - sol.querymin(1, 0, b - 1) - sol.querymin(1, b, d - 1));
}
inline void solve()
{
	ans = 0;
	for (int i = 1; i <= n; i++) if (a[i] >= 0) ans += a[i];
	printf("%lld\n", ans);
}
int main(){
	freopen ("sum.in", "r", stdin);
	freopen ("sum.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	
	sol.build(1, 0, n);
	
	
	if (n <= 1000) solve_60pts();
	else solve();
	
	printf("%lld\n", ans);
  return 0;
}
