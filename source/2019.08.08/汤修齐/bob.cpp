#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 18;

int k, a[maxn], to[maxn];
int s[4];
int vis[maxn];

int getnum(int a, int b, int c, int d){
	return (d << 12) + (c << 8) + (b << 4) + a;
}

bool getp(int t){
	bool re = 0;
	for (int i = 0; i < 4; i++){
		s[i] = t & 15;
		t >>= 4;
		if (s[i] > k) return 0;
		re |= s[i] == 1;
	}
	return re;
}

int work(){
	for (int i = 0; i < 4; i++)
		if (s[i]){
			s[i]--;
			if (s[i]){
				for (int j = 0; j < 4; j++)
					if (!s[j]){
						s[j] = a[s[i]];
						break;
					}
			} 
		}
	return getnum(s[0], s[1], s[2], s[3]);
}

void dfs(int x){
	if (vis[x]) return;
	vis[x] = 1;
	if (!vis[to[x]]) dfs(to[x]);
	vis[x] = vis[to[x]];
}

int main(){
	freopen("bob.in", "r", stdin);
	freopen("bob.out", "w", stdout);
	scanf("%d", &k);
	for (int i = 1; i < k; i++) scanf("%d", a + i);
	for (int i = 1; i <= getnum(k, k, k, k); i++){
		if (!getp(i)) continue;
		to[i] = work();
	}
	vis[0] = 2;
	int ans = 0;
	for (int i = 1; i <= getnum(k, k, k, k); i++){
		if (!getp(i)) continue;
		dfs(i);
		if (vis[i] == 1) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
