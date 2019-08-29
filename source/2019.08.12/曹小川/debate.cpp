#include<bits/stdc++.h>
#define RG register
#define U(x, y, z) for (RG int x = y; x <= z; ++x)
#define D(x, y, z) for (RG int x = y; x >= z; --x)
#define N 400010
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; char c; T f = 1;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	n *= f;
}
template <typename T> inline void write(T n){
	if (n < 0){
		putchar('-');
		n = -n;
	}
	if (n > 9) write(n / 10);
	putchar(n % 10 + '0');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int n;
int a11[N], a01[N], a10[N], a00[N], t11, t01, t10, t00, ans, j, k;
bool cmp(const int &a, const int &b){
	return a > b;
}
int main(){
	FO("debate");
	read(n);
	U(i, 1, n){
		char fr, sc;
		cin >> fr >> sc;
		int x;
		read(x);
		if (fr == '1')
			if (sc == '1') a11[++t11] = x;
			else a10[++t10] = x;
		else 
			if (sc == '1') a01[++t01] = x;
			else a00[++t00] = x;
	}
	sort(a10 + 1, a10 + t10 + 1, cmp);
	sort(a00 + 1, a00 + t00 + 1, cmp);
	sort(a01 + 1, a01 + t01 + 1, cmp);
	U(i, 1, t11) ans += a11[i];
	if (t10 < t01){
		j = t10;
		U(i, 1, t10) ans += a10[i] + a01[i];
	}
	else{
		j = t01;
		U(i, 1, t01) ans += a10[i] + a01[i];
	}
	RG int i = 1;
	++j;
	U(l, 1, t11){
		if (a00[i] > max(a10[j], a01[j])){
			ans += a00[i];
			++i;
		}
		else{
			ans += max(a10[j], a01[j]);
			++j;
		}
	}
	write(ans);
	return 0;
}
