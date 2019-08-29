#include <bits/stdc++.h>
#define LL  	long long
#define Maxn	450
using namespace std;
template <typename tn> void read(tn &a){
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const int mod = 1000000007;
int Mod(int x){ return x >= mod ? x - mod : x; }
void Inc(int &x, int y){ x = Mod(x + y); }

int f[Maxn][Maxn], n, m;

int calc(int x, int y){
	if (f[x][y] != -1) return f[x][y];
	if (x == 1 && y == 1) return f[x][y] = 1;
	int ret = 0;
	for (int i = 1; i < x; i++)
		Inc(ret, (LL) calc(i, y) * calc(x - i, y) % mod);
	for (int i = 1; i < y; i++)
		Inc(ret, (LL) calc(x, i) * calc(x, y - i) % mod);
	return f[x][y] = ret;
}

int main(){
	freopen("cake.in", "r", stdin); freopen("cake.out", "w", stdout);
	memset(f, -1, sizeof f);
	read(n), read(m);
	cout << calc(n, m) << '\n';
	return 0;
}
