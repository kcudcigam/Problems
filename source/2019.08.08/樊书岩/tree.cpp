#include <bits/stdc++.h>
#pragma GCC optimize("Ofast") 
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)

using namespace std;

template <typename T>
inline void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) {if(c == '-') f = -f;}
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

const int maxn = 200000 + 10;
int T, n, k, from[maxn], to[maxn], col[maxn], tar[maxn], fa[maxn], cnt;
vector<int> a[200010];
struct node {
	int num, dep;
} d[maxn];
#define num(i) d[i].num
#define dep(i) d[i].dep
void dfs(int s) {
	int l = a[s].size();
	_rep(i, 0, l - 1) {
		dep(a[s][i]) = dep(s) + 1;
		dfs(a[s][i]);
	}
}
bool cmp(node a, node b) {
	return a.dep > b.dep;
}

void modify(int x) {
	_rep(i, 1, k) {
		col[x] = 1 - col[x];
		cnt += (col[x] == tar[x] ? 1 : -1);
		x = fa[x];
	}
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(T);
	
	while(T--) {
		cnt = 0;
		_rep(i, 1, n) {
			a[i].clear();
		}
		
		read(n); read(k);
		_rep(i, 1, n - 1) {
			read(from[i]); read(to[i]);
			fa[to[i]] = from[i];
			a[from[i]].push_back(to[i]);
		}
		_rep(i, 1, n) {
			read(col[i]);
		}
		_rep(i, 1, n) {
			read(tar[i]);
			cnt += (col[i] == tar[i]);
		}
		_rep(i, 1, n) {
			num(i) = i; 
			if(fa[i] == 0) {dep(i) = 0; dfs(i);}
		}
		sort(d + 1, d + n + 1, cmp);
		bool flg = 0;
		_rep(i, 1, n) {
			if(dep(i) < k - 1) {
				break;
			}
			modify(num(i));
			if(cnt == n) {
				puts("Yes");
				flg = 1;
				break;
			} 
		}
		if(!flg) puts("No");
	}
	return 0;
}

