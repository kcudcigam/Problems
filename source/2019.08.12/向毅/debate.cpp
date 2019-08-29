#include <bits/stdc++.h>
using namespace std;
const int maxn = 40010;
int n, bot[maxn], fir[maxn], sec[maxn], non[maxn];
bool comp(int x, int y) { return x > y; }
int main() {
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string st;
		int act;
		cin >> st >> act;
		if (st[0] == '1' && st[1] == '1') bot[++bot[0]] = act;
		if (st[0] == '1' && st[1] == '0') fir[++fir[0]] = act;
		if (st[0] == '0' && st[1] == '1') sec[++sec[0]] = act;
		if (st[0] == '0' && st[1] == '0') non[++non[0]] = act;
	}
	sort(fir + 1, fir + fir[0] + 1, comp);
	sort(sec + 1, sec + sec[0] + 1, comp);
	sort(non + 1, non + non[0] + 1, comp);
	int ans = 0;
	for (int i = 1; i <= bot[0]; i++) ans += bot[i];
	int en = min(fir[0], sec[0]);
	for (int i = 1; i <= en; i++) ans += fir[i] + sec[i];
	int tot = bot[0] + (en << 1), sup_fir = bot[0] + en, sup_sec = bot[0] + en;
	if (en == fir[0]) {
		int i = en + 1, j = 1;
		while (sup_fir >= ((tot + 2) >> 1)) {
			if (i <= sec[0] && j <= non[0]) {
				tot++;
				if (sec[i] > non[j]) {
					ans += sec[i++];
				} else {
					ans += non[j++];
				}
			} else if (i > sec[0] && j <= non[0]){
				tot++;
				ans += non[j++];
			} else if (i <= sec[0] && j > non[0]) {
				tot++;
				ans += sec[i++];
			} else {
				break;
			}
		}
	} else if (en == sec[0]) {
		int i = en + 1, j = 1;
		while (sup_sec >= ((tot + 2) >> 1)) {
			if (i <= fir[0] && j <= non[0]) {
				tot++;
				if (fir[i] > non[j]) {
					ans += fir[i++];
				} else {
					ans += non[j++];
				}
			} else if (i > fir[0] && j <= non[0]){
				tot++;
				ans += non[j++];
			} else if (i <= fir[0] && j > non[0]) {
				tot++;
				ans += fir[i++];
			} else {
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}


