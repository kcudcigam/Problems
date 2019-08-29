#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c= getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (f == 0) c = -c;
}
template <typename T> inline void write(T n){
	if (n < 0){
		n = -n;
		putchar('-');
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int T, n, p;
long long w[10000010];
long long f[10000010];
int main(){
	FO("mod");
	for (int i = 2; i <= 10000000; ++i){
		 if (i % 2 == 1) w[i] = i;
		 else w[i] = i - 1; 
	}
	read(T);
	while (T--){
		read(n), read(p);
		f[1] = 0;
		for (int i = 2; i <= n; ++i){
			f[i] = (f[i - 1] + w[i]) % p;
			f[i] = (f[i] * i - w[i]) % p;
			if (i % 2 == 0) f[i] += 1;
		}
		writeln(f[n]);
	}
	return 0;
}

