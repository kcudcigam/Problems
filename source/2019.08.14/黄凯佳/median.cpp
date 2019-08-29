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

const int N = 500000 + 5;

ll n, m, a[N], b[N];

ll solve(ll l1, ll r1, ll l2, ll r2) {
//	printf("a[] = \n");
//	for (reg int i=l1; i<=r1; ++i) printf("%lld ", a[i]), printf((i-l1+1)%5==0?"\n":"\0");
//	puts("");
//	printf("b[] = \n");
//	for (reg int i=l2; i<=r2; ++i) printf("%lld ", b[i]), printf((i-l2+1)%5==0?"\n":"\0");
//	puts("");
	ll res=0, l, r; int flag=0, k=((r1-l1+1+r2-l2+1)>>1)+1;
//	printf("need %d\n", k);
	l=l1, r=r1;
	while (l<=r && !flag) {
		ll mid=(l+r)>>1, x=lower_bound(b+l2, b+r2+1, a[mid])-(b+l2), y=upper_bound(b+l2, b+r2+1, a[mid])-(b+l2);
//		printf("in b[%lld ~ %lld] smaller than %lld(%lld) = %lld(%lld)\n", l2, r2, a[mid], mid-l1+1, x, y);
		if ((mid-l1+1)+x<=k && (mid-l1+1)+y>=k) flag=1, res=a[mid];
		else if ((mid-l1+1)+x<k) l=mid+1;
		else r=mid-1;
	}
	l=l2, r=r2;
	while (l<=r && !flag) {
		ll mid=(l+r)>>1, x=lower_bound(a+l1, a+r1+1, b[mid])-(a+l1), y=upper_bound(a+l1, a+r1+1, b[mid])-(a+l1);
//		printf("in a[%lld ~ %lld] smaller than %lld(%lld) = %lld(%lld)\n", l1, r1, b[mid], mid-l2+1, x, y);
		if ((mid-l2+1)+x<=k && (mid-l2+1)+y>=k) flag=1, res=b[mid];
		else if ((mid-l2+1)+x<k) l=mid+1;
		else r=mid-1;
	}
	return res;
}

int main() {
	freopen("median.in", "r", stdin);
	freopen("median.out", "w", stdout);
	n=read(); m=read();
	for (reg int i=1; i<=n; ++i) a[i]=read();
	for (reg int i=1; i<=n; ++i) b[i]=read();
	for (reg int op; m; --m) {
		op=read();
		if (op==1) {
			ll x=read(), y=read(), z=read();
			if (x==0) a[y]=z; else b[y]=z;
		}
		else {
			ll l1=read(), r1=read(), l2=read(), r2=read();
			printf("%lld\n", solve(l1, r1, l2, r2));
		}
	}
	return 0;
}

