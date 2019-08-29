#include<bits/stdc++.h>
#define U(x, y, z) for (int x = y; x <= z; ++x)
#define D(x, y, z) for (int x = y; x >= z; --x)
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
bool hsh[10];
int main(){
	//fo("number");
	int t;
	read(t);
	while (t--){
		string s = "";
		memset(hsh, 0, sizeof hsh);
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); ++i){
			if (!hsh[int(s[i] ^ 48)]){
				++ans;
				hsh[int(s[i] ^ 48)] = 1;
			}
		}
		int nwans = ans / 2 + ans % 2;
		if (nwans > 2) cout << 3 << endl;
		else cout << nwans << endl;
	}
	return 0;
}

