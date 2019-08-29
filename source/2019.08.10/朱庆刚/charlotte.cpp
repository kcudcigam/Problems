#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(;T--;) {
		int n, t = 0, x = 0, y = 0;
		bool flag = true;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) {
			int ti, xi, yi;
			scanf("%d %d %d", &ti, &xi, &yi);
			if(!flag) continue;
			int dis = abs(xi - x) + abs(yi - y);
			int tj = ti - t;
			t = ti;
			x = xi;
			y = yi;
			if(tj < dis || (tj > dis && ((tj - dis) & 1))) flag = false;
		}
		printf(flag ? "Yes\n" : "No\n");
	}
	return 0;
}
