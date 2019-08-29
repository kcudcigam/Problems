#include<bits/stdc++.h>
#define MAXLOG 31
#define ll long long

using namespace std;

int n , k;
int cnt , a[MAXLOG + 1];
int p;
ll ans;

template <typename T> inline void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

int main(){

	freopen("glass.in" , "r" , stdin);
	freopen("glass.out" , "w" , stdout);

	read(n); read(k);
	
	while(n) {
		a[++p] = n % 2;
		cnt += a[p];
		n >>= 1;
	}
	
	if (cnt <= k) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 1; i <= p; i++) {
		if (a[i] == 1) {
			ans += (1 << (i - 1));
			cnt--;
			for (int j = i + 1; j; j++) {
				if (a[j] == 0) {
					a[j] = 1;
					cnt++;
					break;
				}
				else {
					a[j] = 0;
					cnt--;
				}
			}
		}
		if (cnt <= k) break;
	}
	
	cout << ans << endl;

	return 0;
}

