#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

inline ll read() {
	reg ll x=0, f=1; reg char c;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	do x=x*10+c-48; while (isdigit(c=getchar()));
	return x*f;
}

ll Y;

int main() {
	freopen("review.in", "r", stdin);
	freopen("review.out", "w", stdout);
	scanf("%lld", &Y);
	printf("%lld %lld\n", Y+2, Y<<1ll);
	for (reg ll i=2; i<=Y+1; ++i) printf("%lld %lld\n", 1ll, i);
	for (reg ll i=2; i<=Y+1; ++i) printf("%lld %lld\n", i, Y+2);
	return 0;
}

