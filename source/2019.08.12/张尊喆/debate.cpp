#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N = 400500;
ll b[N], c[N], d[N];
ll tb, tc, td;

int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x =(x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}
ll n, ans;
ll cnt1, cnt2;
ll now;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n = read();
	char s[5];
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s); 
		if (s[0] == '1') {
			if (s[1] == '1') {
				cnt1++, cnt2++;
				ans += read(), now++;
			}
			else b[++tb] = read();
		}
		else {
			if (s[1] == '1') c[++tc] = read();
			else d[++td] = read();
		}
	}
	sort(b + 1, b + tb + 1, cmp);
	sort(c + 1, c + tc + 1, cmp);
	int tmp = min(tb, tc);
	for (int k = 1;k <= tmp; k++) {
		cnt1++, cnt2++;
		ans += b[k] + c[k];
		now += 2;
	}
	int mor =  cnt1 * 2 - now;
	if (tc > tb) {
		for (int k = tb + 1;k <= tc; k++) 
		d[++td] = c[k];
	}
	else {
		for (int k = tc + 1;k <= tb; k++) 
		d[++td] = b[k];
	}
	sort(d + 1, d + td + 1, cmp);
	for (int i = 1;i <= td && i <= mor; i++)
		ans += d[i];
	cout << ans << endl;
	return 0;
}
	
