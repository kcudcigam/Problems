#include <bits/stdc++.h>
#define N 5000010
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
int n, m, ans[N];
struct be{
	int w, add;
};
vector<be> a[N];
struct en{
	int w, add;
}; 
vector<en> b[N];
int main(){
	FO("sequence");
	read(n), read(m);
	for (int i = 1; i <= m; i++){
		int l, r, s, e;
		read(l), read(r), read(s), read(e);
		be ta; en tb;
		int c = (e - s) / (r - l);
		tb.add = c;
		tb.w = e;
		ta.w = s;
		ta.add = c;
		a[l].push_back(ta);
		b[r].push_back(tb);  
	}
	int sum = 0, suma = 0;
	for (int i = 1; i <= n; i++){
		sum += suma;
		for (int j = 0; j < a[i].size(); ++j)
			sum += a[i][j].w, suma += a[i][j].add;
		ans[i] = sum;
		for (int j = 0; j < b[i].size(); ++j)
			sum -= b[i][j].w, suma -= b[i][j].add;
	}
	int tans = 0;
	for (int i = 1; i <= n; i++){
		tans = tans ^ ans[i];
	}
	writeln(tans);
	return 0;
}
