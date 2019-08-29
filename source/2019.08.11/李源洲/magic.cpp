#include <cstdio>
#include <iostream>
#define MOD 998244353
using namespace std;

typedef long long l;

l qpow(int b, l exp) {
	if(exp <= 0) return 1;
	if(exp == 1) return b;
	l h = qpow(b, exp>>1);
	return (h*h*((exp&1)?b:1)) % MOD; 
}

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	l n; scanf("%lld", &n); 
	l s=0; char c;
	while((c=getchar()))
		if('a' <= c && c <= 'z') {
			s++;
			break;
		}
	while((c=getchar())) {
		if(!('a' <= c && c <= 'z')) break;
		s++;
	}
	l ans = qpow(26, n);
	for(int ov=0; ov<=s; ov++) {
		ans -= (s+1-ov)*qpow(25,min(s,n-s)-ov)*qpow(26,n-2*s);
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD << endl;
}
