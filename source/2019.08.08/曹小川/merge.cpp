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
	write(n % 10);
}
template <typename T> inline void writeln(T n){
	write(n);
	putchar('\n');
}
inline void FO(string s){
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main(){
	FO("merge");
	cout << 0 << " " << 0 << endl;
	return 0;
}
