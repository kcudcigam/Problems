#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 200005;
ll read(void) {
	ll x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

ll n, ti[N], x[N], y[N];
double tx, ty;
int T;
inline ll man(ll x, ll y, ll xx, ll yy) {
	ll ans = 0;
	if (x > xx) ans += x - xx;
	else ans += xx - x;
	if (y > yy) ans += y - yy;
	else ans += yy - y;
	return ans;
}

int main() {
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout); 
	cin >> T;
	while (T--) {
		n = read();
		bool flag = 0;
		for (int i = 1;i <= n; i++) {
			ti[i] = read();
			scanf ("%lf %lf", &tx, &ty);
			if ((int)tx != tx || (int)ty != ty) flag = false;
			x[i] = (int)tx, y[i] = (int)ty;
		}
		for (int i = 1;i <= n; i++) {
			ll dis = man(x[i-1], y[i-1], x[i], y[i]);
			if (dis > ti[i] - ti[i-1] || ((ti[i] - ti[i-1] - dis) & 1)) {
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		cout << "YES\n";
	}
	return 0;
}
		
		
