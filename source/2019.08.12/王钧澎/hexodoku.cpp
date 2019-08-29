#include<bits/stdc++.h>
#define P(x , y) v[x].push_back(y);

using namespace std;

const int fh[32] = {0 , 1 , 1 , 2 , 2 , 2 , 2 , 2 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 5 , 5 , 5 , 5 , 5 , 5 , 6 , 6 , 6 , 6 , 6 , 7 , 7};
const int fl[32] = {0 , 2 , 3 , 1 , 2 , 3 , 4 , 5 , 1 , 2 , 3 , 4 , 5 , 6 , 2 , 3 , 4 , 5 , 6 , 2 , 3 , 4 , 5 , 6 , 7 , 3 , 4 , 5 , 6 , 7 , 5 , 6};
const int fr[32] = {0 , 3 , 2 , 5 , 4 , 3 , 2 , 1 , 6 , 5 , 4 , 3 , 2 , 1 , 6 , 5 , 4 , 3 , 2 , 7 , 6 , 5 , 4 , 3 , 2 , 7 , 6 , 5 , 4 , 3 , 6 , 5};
 
int k , n;
int a[35];
bool h[10][32] , l[10][32] , r[10][32] , g[32][32];
vector <int> v[32];
int cnt;
int ans[32];

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

bool chck(int x , int y) {
	if (h[fh[x]][y]) return 0;
	if (l[fl[x]][y]) return 0;
	if (r[fr[x]][y]) return 0;
	if (v[x].size() == 6) {
		for (int i = 0; i < v[x].size(); i++) {
			if (y == a[v[x][i]]) return 0;
		}
	}
	else { 
		for (int i = 0; i < v[x].size(); i++) {
			int p = v[x][i];
			if (y == a[p]) return 0;
			for (int j = 0; j < v[p].size(); j++) {
				if (y == a[v[p][j]]) return 0;
			}
		}
	}
	
	return 1;
}

inline void dfs(int dep) {
	if (cnt == n) return;
	if (dep > 31) {
		cnt++;
		if (cnt == n) {
			for (int i = 1; i <= 31; i++) ans[i] = a[i];
		}
		return;
	}
	if (a[dep] != 0) {
		dfs(dep + 1);
		return;
	}
	for (int i = 1; i <= k; i++) {
		if (chck(dep , i)) {
			h[fh[dep]][i] = 1;
			l[fl[dep]][i] = 1;
			r[fr[dep]][i] = 1;
			a[dep] = i;
			dfs(dep + 1);
			h[fh[dep]][i] = 0;
			l[fl[dep]][i] = 0;
			r[fr[dep]][i] = 0;
			a[dep] = 0;
		}
	}
}
 
int main() {

	freopen("hexodoku.in" , "r" , stdin);
	freopen("hexodoku.out" , "w" , stdout);

	read(k); read(n);
	
	for (int i = 1; i <= 31; i++) read(a[i]);
	
	P(1 , 5);
	P(2 , 5);
	P(3 , 9);
	P(4 , 5); P(4 , 9);
	P(6 , 5); P(6 , 12);
	P(7 , 12);
	P(8 , 9);
	P(10 , 5); P(10 , 9); P(10 , 16);
	P(11 , 5); P(11 , 12); P(11 , 16);
	P(13 , 12);
	P(14 , 9); P(14 , 20);
	P(15 , 9); P(15 , 16); P(15 , 20);
	P(17 , 12); P(17 , 16); P(17 , 23);
	P(18 , 12); P(18 , 23);
	P(19 , 20);
	P(21 , 16); P(21 , 20); P(21 , 27);
	P(22 , 16); P(22 , 23); P(22 , 27);
	P(24 , 23);
	P(25 , 20);
	P(26 , 20); P(26 , 27);
	P(28 , 23); P(28 , 27);
	P(29 , 23);
	P(30 , 27); P(31 , 27);
	
	P(5 , 1); P(5 , 2); P(5 , 4); P(5 , 6); P(5 , 10); P(5 , 11);
	P(9 , 3); P(9 , 4); P(9 , 8); P(9 , 10); P(9 , 14); P(9 , 15);
	P(12 , 6); P(12 , 7); P(12 , 11); P(12 , 13); P(12 , 17); P(12 , 18);
	P(16 , 10); P(16 , 11); P(16 , 15); P(16 , 17); P(16 , 21); P(16 , 22);
	P(20 , 14); P(20 , 15); P(20 , 19); P(20 , 21); P(20 , 25); P(20 , 26);
	P(23 , 17); P(23 , 18); P(23 , 22); P(23 , 24); P(23 , 28); P(23 , 29);
	P(27 , 21); P(27 , 22); P(27 , 26); P(27 , 28); P(27 , 30); P(27 , 31);
	
	dfs(1);
	
	if (cnt == n) {
		cout << "Found" << endl;
		for (int i = 1; i < 31; i++) cout << ans[i] << " ";
		cout << ans[31] << endl;
	}
	else {
		cout << "No way" << endl;
	}

	return 0;
}

