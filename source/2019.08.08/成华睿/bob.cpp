#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 0;
int h[16][16][16][16];
int f[16];
int k, ans;
int dfs(int a, int b, int c, int d){
	if (h[a][b][c][d]) return h[a][b][c][d]%2;
	bool p = false;
	int A = a, B = b, C = c, D = d;
	if (a){
		if (!b) b = f[a]; else
			if (!c) c = f[a]; else
				if (!d) d = f[a];
		a--;
		if (!a) p = true;
	}
	if (b){
		if (!a) a = f[b]; else
			if (!c) c = f[b]; else
				if (!d) d = f[b];
		b--;
		if (!b) p = true;
	}
	if (c){
		if (!a) a = f[c]; else
			if (!b) b = f[c]; else
				if (!d) d = f[c];
		c--;
		if (!c) p = true;
	}
	if (d){
		if (!a) a = f[d]; else
			if (!b) b = f[d]; else
				if (!c) c = f[d];
		d--;
		if (!d) p = true;
	}
	if (p){
		h[A][B][C][D] = 3;
		h[A][B][C][D] = dfs(a, b, c, d);
	}else h[A][B][C][D] = 2;
	return h[A][B][C][D];
}
int main(){
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	cin >> k;
	for (int i = 2; i <= k; i++) cin >> f[i];
	for (int a = 0; a <= k; a++)
		for (int b = 0; b <= k; b++)
			for (int c = 0; c <= k; c++)
				for (int d = 0; d <= k; d++)
					ans += dfs(a, b, c, d)%2;
	cout << ans << endl;
	return 0;
}

