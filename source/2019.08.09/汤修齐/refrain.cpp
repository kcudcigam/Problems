#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int Num;
int n, m1, m2;
int fa1[maxn], fa2[maxn], po1[maxn], po2[maxn], tot;
int num[maxn];

int main(){
	freopen("refrain.in", "r", stdin);
	freopen("refrain.out", "w", stdout);
	scanf("%d%d%d%d", &Num, &n, &m1, &m2);
	for (int i = 1; i <= m1; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		fa1[x] = fa1[y] = ++tot;
		po1[x] = y; po1[y] = x;
	}
	tot = 0;
	for (int i = 1; i <= m2; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		fa2[x] = fa2[y] = ++tot;
		po2[x] = y; po2[y] = x;
	}
	for (int i = 1; i <= n; i++) num[i] = i;
	int fac = 1, cnt = 0; bool f;
	for (int i = 2; i <= n; i++) fac *= i;
	for (int T = 1; T <= fac; T++){
		f = 0;
		for (int i = 1; i <= n; i++)
			if (fa1[num[i]] != fa1[num[po1[i]]]){
				f = 1; break;
			}
		for (int i = 1; i <= n && !f; i++)
			if (fa2[num[i]] != fa2[num[po2[i]]]){
				f = 1; break;
			}
		if (f) cnt++;
		for (int i = n; i > 1; i--)
			if (num[i] > num[i - 1]){
				int p = 0;
				for (int j = n; j >= i; j--)
					if (num[j] > num[i - 1] && (!p || num[p] > num[j])) p = j;
				swap(num[i - 1], num[p]);
				sort(num + i, num + n + 1);
				break;
			}
	}
	printf("%d\n", cnt);
	return 0;
}
