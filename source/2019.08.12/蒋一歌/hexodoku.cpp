#include <bits/stdc++.h>
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

vector <int> lmt[55];
int a[55], val[55], used[55][55];
int K, n, Cnt;

void add(int u, int v){ lmt[v].push_back(u); }
void add(int id, int a, int b, int c, int d, int e, int f = 0, int g = 0){
	add(id, a), add(id, b), add(id, c), add(id, d), add(id, e);
	if (f) add(id, f); if (g) add(id, g);
}
void build(){
	add(1, 3, 4, 5, 6, 7);
	add(2, 14, 15, 16, 17, 18);
	add(3, 25, 26, 27, 28, 29);
	add(4, 1, 4, 9, 14, 19);
	add(5, 6, 11, 16, 21, 26);
	add(6, 13, 18, 23, 28, 31);
	add(7, 3, 9, 15, 21, 27, 31);
	add(8, 1, 5, 11, 17, 23, 29);
	add(9, 1, 2, 4, 5, 6, 10, 11);
	add(10, 3, 4, 8, 9, 10, 14, 15);
	add(11, 6, 7, 11, 12, 13, 17, 18);
	add(12, 10, 11, 15, 16, 17, 21, 22);
	add(13, 14, 15, 19, 20, 21, 25, 26);
	add(14, 17, 18, 22, 23, 24, 28, 29);
	add(15, 21, 22, 26, 27, 28, 30, 31);
	add(16, 8, 9, 10, 11, 12, 13);
	add(17, 19, 20, 21, 22, 23, 24);
	add(18, 2, 5, 10, 15, 20, 25);
	add(19, 7, 12, 17, 22, 27, 30);
	add(20, 8, 14, 20, 26, 30);
	add(21, 4, 10, 16, 22, 28);
	add(22, 2, 6, 12, 18, 24);
}

bool check(int u, int x){
	for (auto id : lmt[u]) 
		if (used[id][x]) return false;
	return true;
}
void push(int u, int x){
	for (auto id : lmt[u])
		used[id][x] = true;
	a[u] = x;
}
void pop(int u, int x){
	for (auto id : lmt[u])
		used[id][x] = false;
}
void print(){
	cout << "Found\n";
	for (int i = 1; i <= 30; i++)
		cout << a[i] << ' ';
	cout << a[31] << '\n';
}

void dfs(int dep){
	if (dep > 31){ Cnt++; if (Cnt == n) print(), exit(0); return; }
	if (val[dep]){ if (check(dep, val[dep])) push(dep, val[dep]), dfs(dep + 1), pop(dep, val[dep]); return; }
	for (int i = 1; i <= K; i++)
		if (check(dep, i)) push(dep, i), dfs(dep + 1), pop(dep, i);
}

int main(){
	 freopen("hexodoku.in", "r", stdin), freopen("hexodoku.out", "w", stdout);
	read(K), read(n);
	for (int i = 1; i <= 31; i++)
		read(val[i]);
	build(), dfs(1);
	cout << "No way\n";
	return 0;
}
