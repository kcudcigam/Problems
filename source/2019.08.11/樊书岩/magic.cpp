#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
#define LL long long
#define ULL unsigned long long
template <typename T>
inline void read(T &x) {
    x = 0;
    LL f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
    x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) {putchar('-'); x = -x;}
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp = '\n') {
	write(x); putchar(sp);
}
const int maxn = 1000010, p = 998244353;
LL n;
int len, ans;
char s[maxn];
bool check(std::string str) {
	bool flg = true;
	_rep(i, 0, len) {
		flg = true;
		_rep(j, 0, i - 1) {
			if(str[j] != s[j + 1]) flg = false;
		//	printf("%c%c%d\n", str[j], s[j + 1], flg);
		}
		_rep(j, 0, len - i - 1) {
			if(str[n - j - 1] != s[len - j]) flg = false;
		//	printf("%c%c%d\n", str[j], s[j + 1], flg);
		}
		if(flg) {
		//	std::cout << str << std::endl;
			return true;
		}
	}
	return false;
}
void bf(int dep, std::string s) {
	if(dep == n) {
		ans += (!check(s));
		return;
	}
	_rep(i, 0, 25) {
		std::string t = ""; 
		t.push_back('a' + i);
		bf(dep + 1, s + t);
	} 
}
int qpow(int a, LL b, int p) {
	if(b <= 0) return 1;
	LL res = 1;
	while(b) {
		if(b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return res;
}
int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout); 
	read(n);
	scanf("%s", s + 1);
	len = strlen(s + 1);

//	if(n <= 4) {
//		ans = 0;
//		bf(0, "");
//		writesp(ans);
//	} else {
		ans = ((qpow(26, n, p) - 1ll * qpow(26, n - len, p) * (len + 1) % p + p) % p + 1ll * qpow(26, n - len - 1, p) * len % p) % p;
		writesp(ans < 0 ? ans + p : ans);
//	}
	return 0;
}

