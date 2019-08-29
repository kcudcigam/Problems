#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define ll unsigned long long
using namespace std;
int v[100];
ll totp, tote, tot; 
int main() {
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ll y;
	cin >> y;
	int t = log(y) / log(2);
	bool ppp = 1;
	for (int i = t + 1;i >= 0; i--) {
		if (y & (1 << i)) {
			v[i] = 1;
			if (totp == 0) totp = i + 2, tote = (i + 1) * (i + 2) / 2;
			else if (ppp) {
				tote+=2;
				totp++;
				ppp = 0;
			}
			else tote++;
		}
	}
	cout << totp << ' ' << tote << endl;
	tot = 0; 
	int k;
	for (int i = t + 1;i >= 0; i--) {
		if (v[i] && tot == 0) {
			for (int j = 1;j <= i + 1; j++) {
				for (int k = j + 1;k <= i + 1; k++) 
					printf("%d %d\n", j, k);
				printf ("%d %lld\n", j, totp);
			}
			k = i - 1;
			tot = i + 1;
			break;
		}
	}
	if (ppp) return 0;
	printf ("%lld %lld\n", totp - 1, totp);
	for (int i = k;i >= 0; i--)  {
		if (v[i]) {
			printf("%d %lld\n", i + 2, totp - 1);
		}
	}
	return 0;
}
					
					
					
					
					
					
					
					
					
					
					
					
			
