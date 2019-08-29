#include<bits/stdc++.h>
#include<cstring>
#define p 998244353
#define ll long long
using namespace std;
char a[1000002];
ll n,h,len,tot,cnt,l,Ans,s;
ll b[50],c[50];
ll Pow(ll x,ll y){
	ll base = 1;
	while (y){
		if (y%2){
			base = (base*x) %p;
		}
		x = (x*x) % p;
		y/=2;
	}
	return base;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	cin>>a;
	h = strlen(a);
	if (n == h){
		printf("0");
		return 0;
	}
	len = n-h;
	tot = 1;
	cnt = 0;
	b[0] = 26;//b方案 c26的次方 
	c[0] = 1;
	cnt = 0;
	for (int i = 1; i < 13; ++ i){
		tot *= 26;
		if (n >= tot && n < tot*26)
			cnt = i;
		c[i] = tot;
	}
	for (int i = 1; i <= cnt; ++ i)
		b[i] = Pow(b[i-1],26);
	tot = 1;
	l = len;
	for (int i = cnt; i >= 0; -- i)
		if (len >= c[i]){
			s = len/c[i];
			len = len%c[i];
			s = Pow(b[i],s);
			tot = (tot*s)%p;
		}
	if (n%2)
		Ans = ((tot*2))%p;
	else
		Ans = ((tot*2)-1)%p;
	if (n>2){
		tot = Pow(tot,n-l-1);
		Ans = (Ans+tot)%p;
		Ans = (Ans-l+1+p) %p;
		Ans = (Ans-n+l+1+p) %p;
	}
	tot = 1;
	for (int i = cnt; i >= 0; -- i)
		if (n >= c[i]){
			s = n/c[i];
			n = n %c[i];
			s = Pow(b[i],s);
			tot = (tot*s)%p;
		}
	Ans = (tot - Ans + p) %p;
	printf("%lld",Ans);
	return 0;
}


