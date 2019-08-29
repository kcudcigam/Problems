#include<bits/stdc++.h>
using namespace std;

int a[11], b[11];

int main(){
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		long long n, p;
		cin >> n >> p;
		long long ans = 0;
		for (int i = 1; i <= n; ++i) a[i] = b[i] = i;
		while (next_permutation(a + 1, a + n + 1)) 
			for (int i = 1; i <= n; ++i) {
				if (a[i] != b[i]) ans = (ans + 1) % p;
				b[i] = a[i];
			}
		
		cout << ans % p << endl;
	}

	return 0;
}
/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938
*/



