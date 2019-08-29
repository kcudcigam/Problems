#include <bits/stdc++.h>
#define ll long long
#define rui register unsigned int
using namespace std;
int T, n, tx, ty, tt, t, x, y, dis;
bool p;
int main(){
	freopen("charlotte.in", "r", stdin);
	freopen("charlotte.out", "w", stdout);
	cin >> T;
	for (; T; T--){
		cin >> n;
		tx = ty = tt = 0;
		p = true;
		for (int i = 1; i <= n; i++){
			cin >> t >> x >> y;
			dis = abs(x-tx)+abs(y-ty);
			if (dis > t-tt || (t-tt-dis)%2 == 1) p = false;
			tx = x;
			ty = y;
			tt = t;
		}
		if (p)
			cout << "YES" << endl; else
			cout << "NO" << endl;
	}
	return 0;
}


