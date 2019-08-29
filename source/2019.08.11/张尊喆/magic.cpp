#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int P = 998244353;
char s[1000500];
long long n, len;
long long f[5000];

ll mi(int di,int m) {
	if (m == 0) return 1;
	if (m == 1) return di;
	ll tmp = mi(di, m >> 1) % P;
	tmp *= tmp;
	tmp %= P;
	if (m & 1) return tmp * di % P;
	return tmp;
}

int main() {
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin >> n;
	scanf ("%s", s + 1);
	len = strlen(s + 1);
	if (len == n) {
		cout << (mi(26, n) - 1) % P << endl;
		return 0;
	}
	if (n == 2) {
		cout << 625 << endl;
		return 0;
	}
	if (len == 1) {
		cout << (mi(26, n - 1) - mi(26, n - 2)) % P << endl;
		return 0;
	}
	if (n == 3) {
		int ans = 0;
		int tmp[6];
		for (int i = 1;i <= 26; i++) {
			tmp[1] = 1;
			for (int j = 1;j <= 26; j++) {
				tmp[2] = j;
				for (int k = 1;k <= 26; k++) {
					tmp[3] = k;
					int cnt = 0;
					for (int p = 1;p <= 3 && p <= len; p++) if (tmp[p] == s[p] - 'a' + 1) cnt++; else break;
					for (int p = 3;p >= 1 && 3 - p <= len; p--) if (tmp[p] == s[4 - p] - 'a' + 1) cnt++; else break;
					
					if (cnt >= len) ans++;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	if (n <= 4) {
		int ans = 0;
		int tmp[6];
		for (int i = 1;i <= 26; i++) {
			tmp[1] = 1;
			for (int j = 1;j <= 26; j++) {
				tmp[2] = j;
				for (int q = 1;q <= 26; q++) {
					tmp[3] = q;
				for (int k = 1;k <= 26; k++) {
					tmp[4] = k;
					int cnt = 0;
					for (int p = 1;p <= 4 && p <= len; p++) if (tmp[p] == s[p] - 'a' + 1) cnt++; else break;
					for (int p = 4;p >= 1 && 4 - p <= len; p--) if (tmp[p] == s[4 - p + 1] - 'a' + 1) cnt++; else break;
					
					if (cnt >= len) ans++;
				}
			}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3
abc

*/ 



