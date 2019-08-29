#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1000;
const int P = 1000000007;
int yin[N], yang[N], n, m1, m2;
long long lie[N], pai[N];
int main() {
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num;
	cin >> num;
	cin >> n >> m1 >> m2;
	lie[0] = 1;
	for (int i = 1;i <= n; i++) lie[i] = lie[i-1] * i;
	for (int i = 1;i <= m1; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		yang[x] = y, yang[y] = x;
	}
	for (int j = 1;j <= m2; j++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		yin[x] = y, yin[y] = x;
	}
	long long ans = 0;
	if (num <= 6) {
		for (int i = 1;i <= n; i++) pai[i] = i;
		while (next_permutation(pai + 1, pai + n + 1)) {
			int tmp[100];
			for (int i = 1;i <= n; i++) {
				tmp[pai[i]] = i;
			}
		
			for (int i = 1;i <= n; i++) {
				if (yin[tmp[i]] != tmp[yin[i]] || yang[tmp[i]] != tmp[yang[i]]) {
					ans ++;
					break;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	return 0;
}
/*
1
4 2 2
1 2
4 3
2 3
1 4

*/	
	
