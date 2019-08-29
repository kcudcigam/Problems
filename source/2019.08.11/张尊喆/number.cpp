#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
long long n, T;
int v[20];
ll hh[20];
bool dfs(ll tmp, int ti) {
	if (ti == 0 && tmp == 0) return true;
	if (ti == 0) return false;
	memset(v, 0, sizeof(v));
	int cnt = 0, low = 10;
	int w[30], tot = 0;
	while (tmp) {
		int x = tmp % 10;
		w[++tot] = x;
		low = min(low, x);
		if (!v[x]) v[x] = 1, cnt++;
		tmp /= 10;
	}
	if (cnt > ti * 2 + 1) return false;
	for (int i = low;i <= 9; i++) {
		ll k = 0;
		for (int j = 1;j <= tot; j++) {
			int p = w[j];
			if (p >= i)  p -= i;
			else p -= low;
			k += hh[j-1] * p;
		}
		if (dfs(k, ti - 1)) return true;
	}
	return false;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	hh[0] = 1;
	for (int i = 1;i <= 18; i++) hh[i] = hh[i-1] * 10;
	cin >> T;
	while (T--) {
		scanf ("%lld", &n);
		for (int i = 1;i <= 10; i++)
			if (dfs(n, i)) {
				cout << i << endl;
				break;
			}
	}
	return 0;
}
/*
1
269105
*/
		
