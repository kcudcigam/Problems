#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int A = 63, maxm = 2e5 + 10;

int n, siz, len;
int ans[maxm];
LL Y;
LL f[A];
int S[maxm], E[maxm], tot;

int Find(LL x){
	int l = 0, r = A - 1, mid;
	while (l + 1 < r){
		mid = l + r >> 1;
		if (f[mid] >= x) r = mid;
		else l = mid;
	}
	return r;
}

void dfs(int dep){
	if (dep > tot) return;
	int now = siz;
	if (ans[dep] == -1){
		siz++;
		dfs(dep + 1);
		S[++len] = now;
		E[len] = now + 1;
		S[++len] = now;
		E[len] = siz;
		return;
	}
	for (int i = siz; i < siz + ans[dep] - 1; i++)
		for (int j = i + 1; j < siz + ans[dep]; j++){
			S[++len] = i;
			E[len] = j;
		}
	siz += ans[dep] - 1;
	dfs(dep + 1);
}

int main(){
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	scanf("%lld", &Y);
	f[2] = 1;
	for (int i = 3; i < A; i++) f[i] = f[i - 1] << 1;
	n = Find(Y);
	if (f[n] == Y){
		printf("%d %d\n", n, (n - 1) * n / 2);
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) printf("%d %d\n", i, j);
		return 0;
	}
	
	LL x = Y;
	while (x != 1){
		if (x & 1){
			ans[++tot] = -1;
			x -= 1;
		} else {
			int cnt = 0;
			while (!(x & 1)){
				x >>= 1;
				cnt++;
			}
			ans[++tot] = cnt + 2;
		}
	}
	siz = 1;
	dfs(1);
	printf("%d %d\n", siz, len);
	for (int i = 1; i <= len; i++) printf("%d %d\n", S[i], E[i]);
	
	return 0;
} 
