#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll y;

void part1(ll n) {
	cout << n << " " << n - 1 + n / 2 << endl;
	for (ll i = 1; i < n; ++i) cout << i << " " << i + 1 << endl;
	for (ll i = 1; i <= n / 2; ++i) cout << i * 2 - 1 << " " << i * 2 + 1 << endl;
}

void part2() {
	if (y == 1) {
		cout << "2 1" << endl;
		cout << "1 2" << endl;
	}
	if (y == 2) {
		cout << "3 3" << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "1 3" << endl;
	}
	if (y == 3) {
		cout << "4 5" << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "3 4" << endl;
		cout << "1 3" << endl;
		cout << "2 4" << endl;
	}
	if (y == 5) {
		cout << "5 7" << endl;
		cout << "1 2" << endl;
		cout << "2 3" << endl;
		cout << "3 4" << endl;
		cout << "4 5" << endl;
		cout << "1 3" << endl;
		cout << "2 4" << endl;
		cout << "3 5" << endl;
	}
} 

void part3() {
	cout << y + 1 << " " << 2 * y - 1 << endl;
	for (ll i = 1; i <= y; ++i) cout << i << " " << i + 1 << endl;
	for (ll i = 1; i < y; ++i) cout << i << " " << y + 1 << endl;
}

int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> y;
	ll t = y; ll cnt = 1;
	while (t % 2 == 0) {t /= 2; cnt++;}
	if (t == 1) part1(cnt * 2 - 1);
	else if (y <= 5) part2();
	else part3();
	
	return 0;
}
