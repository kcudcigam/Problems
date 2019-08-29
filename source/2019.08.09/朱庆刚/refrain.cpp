#include<cstdio>
#include<set>
using namespace std;

const int MAXN = 2e5 + 5;
const int MO = 1e9 + 7;

int n, m1, m2, ans = 0;
int x[MAXN] = {0}; // 位置的状态 0无 1阴 2阳 3阴阳 

int jc(int x) {
	int res = 1;
	for(int i = 2; i <= x; ++i) {
		res *= i;
		res %= MO;
	}
	return res;
}

void dfs(int pos, set<int>s) {
	if(pos > n) return;
	set<int>sn = s;
	for(set<int>::iterator i = s.begin(); i != s.end(); ++i) {
		int p = (*i); // 将x[p](原本)状态的单位放在x[pos]状态的位置 
		if(x[p] == 3 || x[p] == x[pos] || x[pos] == 0) { // 不会爆炸 
			sn.erase(p);
			dfs(pos + 1, sn);
			sn.insert(p);
		} else {
			ans += jc(n - pos);
			ans %= MO;
		}
	}
}

int main() {
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	int fuck;
	scanf("%d", &fuck);
	scanf("%d %d %d", &n, &m1, &m2);
	set<int>s;
	s.clear();
	for(int i = 1; i <= n; ++i)
		s.insert(i);
	for(int i = 1; i <= m1; ++i) {
		int ra, rb;
		scanf("%d %d", &ra, &rb);
		x[ra] = 1;
		x[rb] = 1;
	}
	for(int i = 1; i <= m2; ++i) {
		int ra, rb;
		scanf("%d %d", &ra, &rb);
		x[ra] += 2;
		x[rb] += 2;
	}
	dfs(1, s);
	printf("%d", ans);
	return 0;
}

