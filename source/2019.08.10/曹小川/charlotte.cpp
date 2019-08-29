#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &n){
	n = 0; bool f = 1; char c;
	for (c = getchar(); !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) n = (n << 1) + (n << 3) + (c ^ 48);
	if (!f) c = -c;
}
int T;
struct plan{
	int t, x, y;
}p[100010];
bool cmp(const plan &a, const plan &b){
	return a.t < b.t;
}
int main(){
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	read(T);
	while (T--){
		int n;
		bool f = 1;
		read(n);
		for (int i = 1; i <= n; ++i)
			read(p[i].t), read(p[i].x), read(p[i].y);
		int ut = 0, lx = 0, ly = 0;
		sort(p + 1, p + n + 1, cmp);
		for (int i = 1; i <= n; ++i){
			ut += abs(p[i].x - lx) + abs(p[i].y - ly);
			if (ut > p[i].t || (p[i].t - ut) % 2 == 1){
				cout << i << endl;
				f = 0;
				break;
			}
			ut = p[i].t;
			lx = p[i].x;
			ly = p[i].y;
		}
		if (f == 1){
			puts("Yes");
		}
		else{
			puts("No");
		}
	}
	return 0;
}
