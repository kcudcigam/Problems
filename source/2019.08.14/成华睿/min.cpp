#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
int n;
ll a[N], mn[N], f[N];
ll A, B, C, D;
ll func(ll x){
	return A*x*x*x+B*x*x+C*x+D;
}
int main(){
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
	cin >> n >> A >> B >> C >> D;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mn[i] = 1e16;
		f[i] = -1e16;
	}
	f[1] = func(a[1]);
	mn[1] = a[1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++){
			mn[j] = min(mn[j], a[i]);
			f[i] = max(f[j-1]+func(mn[j]), f[i]);
		}
	cout << f[n] << endl;
	return 0;
}

