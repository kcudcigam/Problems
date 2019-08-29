#include<cstdio>
#include<cctype>
#include<algorithm>
#include<vector>
#include<cstring>
#define MaxN 1010

typedef long long LL;

struct node {
	int left, right;
	bool operator < (const node &rhs) const {
		return right == rhs.right ? left < rhs.left : right < rhs.right;
	}
} man[MaxN];

int n, m, a[10];
bool vis[MaxN];
std::vector<int> v[MaxN];
LL ans;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}

LL calc(int x) {
	LL num1 = 0, num2;
	for (int i = 1; i <= 5; ++i) {
		if (a[i]) {
			num2 = a[i];
			for (int j = 1; j <= i; ++j) num2 *= x;
			num1 += num2;
		}
	}
	return num1;
}

void dfs(int dep, LL now) {
	if (dep == n) ans = std::max(ans, now);
	else {
		for (int i = 1; i <= m; ++i) v[i].clear();
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (man[j].left <= i && man[j].right >= i && !vis[j])
					v[i].push_back(j);
			}
		}
		int _max = 0, mpos = 0, t[MaxN];
		for (int i = 1; i <= m; ++i) {
			if (v[i].size() > _max) _max = v[i].size(), mpos = i;
		}
		t[0] = v[mpos].size();
		for (int i = 0; i < v[mpos].size(); ++i) 
			vis[v[mpos][i]] = 1, t[i + 1] = v[mpos][i];
		dfs(dep + v[mpos].size(), now + calc(t[0]));
		for (int i = 1; i <= t[0]; ++i) vis[t[i]] = 0;
	 }
}

int main() {
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= 5; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) {
		man[i].left = read(); man[i].right = read();
	}
	std::sort(man + 1, man + n + 1);
	memset(vis, 0, sizeof vis);
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
