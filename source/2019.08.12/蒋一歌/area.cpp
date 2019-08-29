#include <bits/stdc++.h>
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bitset <22000> vis[22000];
//map <int, bool> vis[50000];

bool a[1050][1050];
int n, m, Cnt, Flag;

void solve(int x){
	if (x > 500) return;
	for (int i = 0; i < x; i++)
	for (int j = 0; j < x; j++){
		a[i + x][j] = a[i][j + x] = a[i][j];
		a[i + x][j + x] = a[i][j] ^ 1;
	}
	solve(x << 1);
}

int calc(int x, int y){
	int p1 = x / 1024, p2 = y / 1024;
	int r1 = x & 1023, r2 = y & 1023;
	return a[p1][p2] ^ a[r1][r2];
}

void search(int x, int y, int tag){
	if (x == 0 || y == 0){ Flag = true; return; }
	for (int i = 0; i < 4; i++){
		int tx = x + dx[i], ty = y + dy[i];
		if (calc(tx, ty) != tag || vis[tx][ty]) continue;
		vis[tx][ty] = true, Cnt++, search(tx, ty, tag);
	}
}

int main(){
	freopen("area.in", "r", stdin); freopen("area.out", "w", stdout);
	read(n), read(m), vis[n][m] = Cnt = 1;
	if (n >= 20000){ puts("infinity"); return 0; } 
	a[0][0] = a[0][1] = a[1][0] = 1, a[1][1] = 0;
	solve(2), search(n, m, calc(n, m));
	if (Flag) cout << "infinity\n";
	else cout << Cnt << '\n';
	return 0;
}
