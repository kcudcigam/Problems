#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int K, n, cnt;
bool flag;
int a[110][110], b[N], c[N], t[N];
vector<int> E[N];

bool check(int x, int y) {
	if (!y) return 1;
	for (int i=0;i<E[x].size();++i) {
		int v = E[x][i];
		if (x != v && c[v] == y) return 0;
	}
	return 1;
}

bool wujie() {
	for (int i=1;i<=31;++i) {
		if (!check(i, c[i])) return 1;
	}
	return 0;
}

void addl(int st, int ed, int beg, int las, int x) {
	for (int i=st;i<=ed;i+=x) {
		if (beg) { E[i].push_back(beg); E[beg].push_back(i); }
		if (las) { E[las].push_back(i); E[i].push_back(las); }
		for (int j=st;j<=ed;j+=x)
			if (i != j) E[i].push_back(j);
	}
}

void Print() {
	flag = 1;
	puts("Found");
	for (int i=1;i<32;++i) cout << c[i] << ' ';
}

void dfs(int dep) {
	if (flag) return;
	if (dep > 31) { ++cnt; if (cnt == n) Print(); return; }
	if (!c[dep]) {
		for (int i=1;i<=K;++i) {
			if (check(dep, i)) { c[dep] = i; dfs(dep + 1); c[dep] = 0; }
		}
	} else if (check(dep, c[dep])) dfs(dep + 1);
}

int main() {
	freopen("hexodoku.in", "r", stdin); freopen("hexodoku.out", "w", stdout);
	cin >> K >> n;
	for (int i=1;i<32;++i) cin >> c[i];
	b[1] = 5, b[2] = 9, b[3] = 12, b[4] = 16, b[5] = 20, b[6] = 23, b[7] = 27;
	a[5][0] = -4, a[5][1] = -3, a[5][2] = -1, a[5][3] = 1, a[5][4] = 5, a[5][5] = 6;
	a[27][0] = -6, a[27][1] = -5, a[27][2] = -1, a[27][3] = 1, a[27][4] = 3, a[27][5] = 4;
	for (int i=2;i<7;++i) {
		int x = b[i];
		a[x][0] = -6, a[x][1] = -5, a[x][2] = -1, a[x][3] = 1, a[x][4] = 5, a[x][5] = 6;
	}
	for (int i=1;i<8;++i) {
		int x = b[i];
		for (int j=0;j<7;++j) {
			int u = x + a[x][j];
			for (int k=0;k<7;++k) {
				int v = x + a[x][k];
				if (u != v) E[u].push_back(v);
			}
		}
	}
	for (int i=3;i<=25;i+=11) {
		for (int j=0;j<5;++j) {
			for (int k=0;k<5;++k)
				if (j != k) E[i + j].push_back(i + k);
		}
	}
	for (int i=8;i<=19;i+=11) {
		for (int j=0;j<6;++j) {
			for (int k=0;k<6;++k)
				if (j != k) E[i + j].push_back(i + k);
		}
	}
	E[2].push_back(1); E[31].push_back(30);
	E[1].push_back(2); E[30].push_back(31);
	E[8].push_back(3); E[29].push_back(24);
	E[3].push_back(8); E[24].push_back(29);
	addl(4, 19, 1, 0, 5); addl(5, 25, 2, 0, 5);
	addl(6, 26, 0, 0, 5); addl(7, 27, 0, 30, 5);
	addl(13, 28, 0, 31, 5);
	E[13].push_back(7); E[25].push_back(19);
	E[7].push_back(13); E[19].push_back(25);
	addl(6, 24, 2, 0, 6); addl(5, 29, 1, 0, 6);
	addl(4, 28, 0, 0, 6); addl(3, 27, 0, 31, 6);
	addl(8, 26, 0, 30, 6);
	if (wujie() || K < 7) { puts("No way"); return 0;}
	dfs(1);
	if (!flag) puts("No way");
	return 0;
}
