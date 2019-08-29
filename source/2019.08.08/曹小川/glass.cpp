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
LL P2[31];
LL n, ans, del; int k, s;
int main(){
	FO("glass");
	read(n), read(k);
	if (k > n){
		cout << k - n << endl;
		return 0;
	}
	if (k > n / 2){
		cout << 0 << endl;
		return 0;
	}
	U(i, 0, 30) if (n & (1 << i)) P2[i] = 1, s += 1;
	if (s <= k){
		cout << 0 << endl;
		return 0;
	}
	U(i, 0, 30){
		if (s + 1 == k){
			cout << (1 << i) - del;
			return 0;
		} 
		if (P2[i]){
			del += (1 << i);
			--s;
		}
	}
	return 0;
}
