#include<bits/stdc++.h>
#define LL long long
#define RG register
#define U(x, y, z) for (RG int x = y; x <= z; ++x)
#define D(x, y, z) for (RG int x = y; x >= z; --x)
using namespace std;
template <typename T> inline void read(T &n){
	bool f = 1; char c; n = 0;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (f == 0) n = -n;
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int a[5], k, t[16], ans;
bool check(int a, int b, int c, int d){
	U(i, 1, k * k + 1){
		if (a) --a;
		if (a){
			if (b == 0) b = t[a];
			else if (c == 0) c = t[a];
			else if (d == 0) d = t[a];
		}
		if (b) --b;
		if (b){
			--a;
			if (a == 0) b = t[b];
			else if (c == 0) c = t[b];
			else if (d == 0) d = t[b];
		}
		if (c) --c;
		if (c){
			if (a == 0) b = t[a];
			else if (b == 0) c = t[c];
			else if (d == 0) d = t[c];
		}
		if (d) --d;
		if (d){
			if (a == 0) b = t[a];
			else if (b == 0) c = t[d];
			else if (c == 0) d = t[d];
		}
		if (a == b == c == d == 0) return 0;
	}
	return 1;
}
inline void dfs(int dep){
	if (dep > 4){
		if(check(a[1], a[2], a[3], a[4])) ++ans;
		return ;
	}
	U(i, 0, k){
		a[dep] = i;
		dfs(dep + 1);
	}
}
int main(){
	FO("bob");
	read(k);
	U(i, 1, k - 1) read(t[k]);
	dfs(1);
	cout << ans << endl;
	return 0;
}
