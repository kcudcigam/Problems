#include<bits/stdc++.h>
#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)
#define mod 998244353
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (f == 0) n = -n;
}
inline void fo(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
long long n;
string s, c;
long long ss;
long long ans;
int check(){
	for (int i = 0; i < n; ++i){
		long long cd = n - ss;
		string tc = c;
		while (cd-- && tc.size() >= i + 1){
			tc.erase(tc.begin() + i);
		}
		if (tc == s) return 0;
	}
	return 1; 
}
inline void dfs(int dep){
	if (dep > n){
		ans += check();
		return ;
	}
	for (int i = 0; i <= 25; ++i){
		c.push_back('a' + i);
		dfs(dep + 1);
		c.erase(c.begin() + c.size() - 1);
	}
}
int main(){
	fo("magic");
	read(n);
	cin >> s;
	ss = s.size();
	dfs(1);
	cout << ans << endl;
	return 0;
}
