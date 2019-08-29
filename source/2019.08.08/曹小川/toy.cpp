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
inline void chkmax(int &x, int y){
	x = x > y ? x : y;
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int f[1000010][3], n, m, a[1010], ans;
int main(){
	FO("toy");
	read(n), read(m);
	U(i, 1, n){
		read(a[i]);
		chkmax(f[a[i]][2], 1);
		D(j, m, 0){
			if (f[j - a[i]][0] && j >= a[i]) chkmax(f[j][2], f[j - a[i]][0] + 1);
			f[j][0] = f[j][1];
			f[j][1] = f[j][2];
		}
	}
	U(i, 1, m){
		chkmax(ans, f[i][2]);
		chkmax(ans, f[i][1]);
		chkmax(ans, f[i][0]);
	}
	cout << ans << endl;
	return 0;
}
