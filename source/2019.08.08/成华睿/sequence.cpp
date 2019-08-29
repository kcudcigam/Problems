#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500005;
template <typename T> void read(T &x){
	int f = 1;
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x*10+c-'0';
	x *= f;
	return;
}
ll s, e, k, q, res;
int n, m, l, r;
ll f[N], ans[N];
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= m; i++){
		read(l);
		read(r);
		read(s);
		read(e);
		ans[l] += s;
		ans[r+1] -= e;
		e -= s;
		k = e/(r-l);
		f[l+1] += k;
		f[r+1] -= k;
	}
	for (int i = 1; i <= n; i++){
		q += f[i];
		ans[i] = ans[i-1]+ans[i]+q;
		res ^= ans[i];
	}
	cout << res << endl;
	return 0;
}
