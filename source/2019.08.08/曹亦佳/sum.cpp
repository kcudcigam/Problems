#include<bits/stdc++.h>
using namespace std;

template <typename tn> void read(tn &a) {
	tn x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	a = x * f;
}

const long long INF = 1e15;
const int MAXN = 100010;
int n, a[MAXN];

int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	
	int ms, me, s = 1, i = 1; long long mx = -INF, sum = 0;
	while (i <= n) {
		sum += a[i];
		if (sum > mx) {mx = sum;ms = s;me = i;}
		if (sum < 0) {sum = 0;s = i + 1;}
		i++;
	}
	
	long long ans = mx;
	int ll = ms, rr = me;
	s = i = 1;mx = -INF;sum = 0;
	while (i < ll) {
		sum += a[i];
		if (sum > mx) {mx = sum; ms = s; me = i;}
		if (sum < 0) {sum = 0; s = i + 1;}
		i++;
	}
	
	s = i = rr + 1; sum = 0;
	while (i <= n) {
		sum += a[i];
		if (sum > mx) {mx = sum; ms = s; me = i;}
		if (sum < 0) {sum = 0; s = i + 1;}
		i++;
	}
	
//	cerr << ans << " " << mx << " " << ll << " " << rr << endl;
	
	if ((mx < 0) && (rr - ll > 0)) cout << ans << endl;
	else cout << ans + mx << endl;

	return 0;
}



