#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL>PLL;
const int MAXN = 260;
PLL a[MAXN];
bool f[MAXN], ft[MAXN];
int n, m, b[55], t[55];
LL g1, g2, g3, g4, g5;

LL pls(LL x, int s) {
	LL t = x;
	for (int i = 1; i < s; ++i) x *= t;
	return x;
}

LL nex(int x) {
	for (int i = 1; i <= m; ++i) t[i] = b[i];
	for (int i = 1; i <= n; ++i) ft[i] = f[i];
	for (int i = 1; i <= n; ++i) {
		LL l = a[i].first, r = a[i].second;
		if (l <= x && x <= r) f[i] = true;
	}
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; ++i) {
		if (f[i]) continue;
//		cerr << "      " << i << endl;
		LL l = a[i].first, r = a[i].second;
		b[l]++; b[r + 1]--;
	}
		
	LL mx = 0;
	for (int i = 1; i <= m; ++i) {
		b[i] += b[i - 1];
		if (b[i] > mx) mx = b[i];
	}
	//	for (int i = 1; i <= m; ++i)cerr << "b" << i << ":" << b[i] << endl;
	
	
	for (int i = 1; i <= n; ++i) f[i] = ft[i];
	for (int i = 1; i <= m; ++i) b[i] = t[i];
	
//	cerr <<x << "   " <<mx <<endl;
	return mx;
}

void part1() {
	LL cnt = 0, ans = 0;
	while (cnt < n) {
		memset(b, 0, sizeof(b));
//		for (int i = 1; i <= m; ++i) cerr << b[i] << " ";cerr << endl;
		
		for (int i = 1; i <= n; ++i) {
			if (f[i]) continue;
			LL l = a[i].first, r = a[i].second;
			b[l]++; b[r + 1]--;
		}
		for (int i = 1; i <= m; ++i) b[i] += b[i - 1];
		
		LL mx = 0, mx2 = 0, mxi;
		for (int i = 1; i <= m; ++i) {//cerr << "b" << i << ":" << b[i] << endl;
			if (b[i] > mx) {mx = b[i]; mxi = i; mx2 = nex(i);}
			else if (b[i] == mx) {
				LL x = nex(i);
				if (x > mx2) {mxi = i; mx2 = x;}
				}
		}
		
		cnt += mx; ans += g1*pls(mx, 1)+g2*pls(mx, 2)+g3*pls(mx, 3)+g4*pls(mx, 4)+g5*pls(mx, 5);
//		cerr << "mx2:" << mx2 << endl;
		for (int i = 1; i <= n; ++i) {
			LL l = a[i].first, r = a[i].second;
			if (l <= mxi && mxi <= r) f[i] = true;
		}
	}
	
	cout << ans << endl;
}

void part2() {
	sort(a + 1, a + n + 1);
	LL cnt = 0, ans = 0;
	while (cnt < n) {
		LL mx = 0, s, e;
		for (int i = 1; i <= n; ++i) {
			if (f[i]) continue;
			
			LL rr = a[i].second, l;int j;
			for (j = i + 1; j <= n; ++j) {
				if (f[j]) continue;
				
				l = a[j].first;
				if (l > rr) if (j - i > mx) {mx = j - i; s = i; e = j - 1; break;}
			}
			if (j - i > mx) {mx = j - i; s = i; e = j - 1; break;}
		}
		cnt += mx; ans += g1*pls(mx, 1)+g2*pls(mx, 2)+g3*pls(mx, 3)+g4*pls(mx, 4)+g5*pls(mx, 5);
		for (int i = s; i <= e; ++i) f[i] = true;
	}
	
	cout << ans << endl;
}

int main() {
	freopen("stand.in", "r", stdin);
	freopen("stand.out", "w", stdout);
	cin >> n >> m >> g1 >> g2 >> g3 >> g4 >> g5;
	
	bool f = true;
	for (int i = 1; i <= n; ++i) {
		LL x, y; cin >> x >> y;
		a[i] = make_pair(x, y);
		if (x != 1 || y != m) f = false;
	}
	if (f) {
		cout << g1*pls(n, 1)+g2*pls(n, 2)+g3*pls(n, 3)+g4*pls(n, 4)+g5*pls(n, 5) << endl;
		return 0;
	}
	
	if (m <= 50) part1();
	else part2();
 
	return 0;
}
/*
4 10
0 1 0 0 0
1 3
3 5
2 7
6 10
*/

