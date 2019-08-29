#include<bits/stdc++.h>
using namespace std;

bool f[10];

bool check(int n) {
	for (int i = 0; i <= 9; ++i) f[i] = false;
	while (n != 0) {f[n % 10] = true; n /= 10;}
	
	int cnt = 0;
	for (int i = 0; i <= 9; ++i) if (f[i]) cnt++;
	
	if (cnt <= 2) return true;
	else return false;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T; cin >> T;
	while(T--) {
		long long n; cin >> n;
		if (check(n)) {cout << "1" << endl; continue;}
		
		bool f = false;
		for (int i = 1; i <= n; ++i) 
			if (check(i) && check(n - i)) {
				cout <<"2" << endl;
				f = true;break;
			}
			
		if (f) continue;
		else cout << "3" << endl;
	}

	return 0;
}



