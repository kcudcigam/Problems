#include<bits/stdc++.h>
#define rui register unsigned int
#define ll long long
using namespace std;
const int N = 10000005;
ll f[N];
int n, q;
ll p;
int main(){
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
	cin >> q;
	for (int j = 1; j <= q; j++){
		cin >> n >> p;
		f[1] = 0;
		for (int i = 2; i <= n; i++){
			f[i] = (f[i-1]*i+i*(i-1))%p;
			if (i%2 == 0) f[i] = (f[i]+p-i+2)%p;
		}
		cout << f[n] << endl;
	}	
	return 0;
}


