#include<bits/stdc++.h>
#define ll long long
#define MAXN 310
#define pmod 1000000007

using namespace std;

ll f[MAXN][MAXN];
int n , m;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
} 

template <typename T> inline void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> inline void chkmin(T &x , T y) {x = x < y ? x : y; }

ll dfs(int x , int y) {
	if (f[x][y]) return f[x][y];
	for (int i = 1; i < x; i++) 
		f[x][y] = (f[x][y] + dfs(i , y) * dfs(x - i , y)) % pmod;
	for (int i = 1; i < y; i++) 
		f[x][y] = (f[x][y] + dfs(x , i) * dfs(x , y - i)) % pmod;
	return f[x][y];
}

int main() {
	
	freopen("cake.in" , "r" ,stdin);
	freopen("cake.out" , "w" , stdout);
	
	read(n); read(m);
	
	f[1][2] = f[2][1] = f[1][1] = 1;
	
	cout << dfs(n , m) % pmod << endl;
	
	return 0;
}
