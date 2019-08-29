#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

int main() {
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	int T; read(T);
	while (T--) {
		int n; read(n);
		int t1 = 0, x1 = 0, y1 = 0;
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			int t2, x2, y2;read(t2);read(x2);read(y2);
			if (flag) continue;
			int dis = abs(x1 - x2) + abs(y1 - y2), t = t2 - t1;
		//	cerr << "d t x1 y1 x2 y2:"<<dis << " " << t <<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
			if (dis > t) {flag = true; continue;}
			if ((t - dis) % 2) flag = true;
			else {t1 = t2; x1 = x2; y1 = y2;}
		}
		if (flag) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	
	return 0;
} 
/*
3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/
