#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
const int inf = INT_MAX / 2;
int n, ans, cnt, tota, totb, totc;
int a[N], b[N], c[N], sa[N], sb[N], sc[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("debate.in", "r", stdin); freopen("debate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i=1;i<=n;++i) {
		string st; int x;
		cin >> st >> x;
		if (st == "11") ans += x, ++cnt;
		if (st == "10") a[++tota] = x;
		if (st == "01") b[++totb] = x;
		if (st == "00") c[++totc] = x;
	}
	sort(a + 1, a + tota + 1, cmp); 
	sort(b + 1, b + totb + 1, cmp);
	sort(c + 1, c + totc + 1, cmp);
	for (int i=1;i<=tota;++i) sa[i] = sa[i - 1] + a[i];
	for (int i=1;i<=totb;++i) sb[i] = sb[i - 1] + b[i];
	for (int i=1;i<=totc;++i) sc[i] = sc[i - 1] + c[i];
	int tmp = 0;
	for (int i=0;i<=min(totc, cnt);++i) {
		int x = min(totb + cnt - i, tota), y = max(x + i - cnt, min(totb, x + cnt - i));
		tmp = max(tmp, sa[x] + sb[y] + sc[i]);
	}
	cout << tmp + ans << endl;
	return 0;
}
