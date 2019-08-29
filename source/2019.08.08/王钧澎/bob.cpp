#include<bits/stdc++.h>
#define MAXN 20

using namespace std;

int n , a[MAXN];
map <int , bool> m;
int byf[5] , wzy[5];
bool h[17][17][17][17];
int ans;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

bool chck() {
	memset(h , 0 , sizeof(h));
	for (int i = 1; i <= 4; i++) byf[i] = wzy[i];
	h[byf[1]][byf[2]][byf[3]][byf[4]] = 1;
	bool t = 1;
	while(t) {
		t = 0;
		for (int i = 1; i <= 4; i++) {
			int p = byf[i];
			if (p == 0) continue;
			if (p == 1) {
				byf[i] = 0;
				t = 1;
				continue;
			}
			for (int j = 1; j <= 4; j++) {
				if (byf[j] == 0) {
					byf[j] = a[p - 1];
					break;
				}
			}
			byf[i]--;
		}
		if (t && h[byf[1]][byf[2]][byf[3]][byf[4]]) return 1;
		h[byf[1]][byf[2]][byf[3]][byf[4]] = 1;
	}
	return 0;
}

void dfs(int dep) {
	if (dep > 4) {
		if (chck()) ans++;
		return;
	}
	for (int i = 0; i <= n; i++) {
		wzy[dep] = i;
		dfs(dep + 1);
		wzy[dep] = 0;
	}
}

int main(){

	freopen("bob.in" , "r" , stdin);
	freopen("bob.out" , "w" , stdout);

	read(n);
	for (int i = 1; i < n; i++) read(a[i]);
	
	dfs(1);

	cout << ans << endl;

	return 0;
}


