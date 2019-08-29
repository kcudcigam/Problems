#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 105;
int a[MAXN];
int n, k, l, p, m, ans;
int main(){
	freopen("glass.in", "r", stdin);
	freopen("glass.out", "w", stdout);
	cin >> n >> k;
	for (int i = n; i; i /= 2){
		a[++m] = i%2;
		if (p == 0 && a[m]) p = m;
	}
	l = m+1;
	for (int i = m, s = 0; i > p; i--){
		if (a[i])
			s++; else
			l = i;
		if (s == k){
			p = l;
			a[l] = 1;
			break;
		} 		
	}
	for (int i = p, x = 1 << (p-1); i <= m+1; i++, x <<= 1) ans += a[i]*x;
	cout << ans-n << endl;
	return 0;
}

