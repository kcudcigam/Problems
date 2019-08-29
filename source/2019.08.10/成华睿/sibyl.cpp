#include <bits/stdc++.h>
#define ll long long
#define rui register unsigned int
using namespace std;
const int N = 600005;
int head[N], nxt[N], to[N], a[N], h[N];
int n, m, q, x, y, ans, k, sum1;
int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		if (x > y) swap(x, y);
		cin >> x >> y;
		nxt[i*2-1] = head[x];
		head[x] = i*2-1;
		to[i*2-1] = y;
		nxt[i*2] = head[y];
		head[y] = i*2;
		to[i*2] = x;
		if (x == 1) h[y] = 1;
	}
	h[1] = 1;
	for (int i = 1; i <= q; i++){
		cin >> k;
		if (k == 0){
			cin >> x;
			if (x == 1){
				cout << sum1 << endl;
				continue;
			}
			ans = a[x];
			for (int j = head[x]; j; j = nxt[j]) ans += a[to[j]];
			cout << ans << endl;
		}
		if (k == 1){
			cin >> x >> y;
			a[x] += y;
			if (h[x] == 1) sum1 += y;
		}
	} 
	return 0;
}


