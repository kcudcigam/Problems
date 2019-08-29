#include <bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;

int rd(){
	int x = 0; bool f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int P = 1e9 + 7;
int n, m, f[400][400];

inline int dw(int x) {return x < P ? x : x - P;}

int ddd(int x, int y) {
	if (x > y) swap(x, y);
	if (x == 1 && y == 1) return 1;
	if (f[x][y]) return f[x][y];
	int res = 0;
	fox (i, 1, x - 1) res = dw(res + 1LL * ddd(i, y) * ddd(x - i, y) % P);
	fox (i, 1, y - 1) res = dw(res + 1LL * ddd(x, i) * ddd(x, y - i) % P);
	return f[x][y] = res;
}

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n = rd(), m = rd();
	printf("%d\n", ddd(n, m));
	return 0;
}
