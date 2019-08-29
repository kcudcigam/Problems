#include<bits/stdc++.h>
#define rui register unsigned int
#define ll long long
using namespace std;
const int N = 10005;
ll ls[N], lr[N], l[N], r[N], a[N];
int n;
ll x, y, ans;
int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		l[i] = l[i-1]+a[i];
		if (l[i] <= 0) l[i] = 0;
	}
	for (int i = n; i >= 0; i--){
		r[i] = r[i+1]+a[i];
		if (r[i] <= 0) r[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		ls[i] = max(ls[i-1], a[i]);
		l[i] = max(l[i], l[i-1]);
	}
	for (int i = n; i >= 1; i--){
		lr[i] = max(lr[i+1], a[i]);
		r[i] = max(r[i], r[i+1]);
	}
	for (int i = 1; i < n; i++){
		x = l[i];
		y = r[i+1];
		if (l[i] == 0) x = ls[i];
		if (r[i+1] == 0) y = lr[i+1];
		ans = max(ans, x+y);
	}
	cout << ans << endl;
	return 0;
}																
