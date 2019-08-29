#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
ll n,A,B,C,D;
ll a[200005];
ll s1[200005][25],s2[200005][25],s3[200005][25],Nex[200005][25],Min[200005][25];
ll f[200005][25];
ll h,t,Ans,tot;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
	for (ll i = 1; i <= n; ++ i)
		scanf("%d",&a[i]);
	for (ll i = 1; i <= n; ++ i)
		tot+= a[i]*a[i]*a[i]*A+a[i]*a[i]*B+a[i]*C+D;
	for (ll i = 1; i <= n; ++ i){
		Min[i][0] = min(a[i],a[i+1]);
		s1[i][0] = Min[i][0];
		s2[i][0] = Min[i][0]*Min[i][0];
		s3[i][0] = Min[i][0]*Min[i][0]*Min[i][0];
		ll X1 = A*s3[i][0]+B*s2[i][0]+C*s1[i][0]+D;
		ll X2 = a[i]*a[i]*a[i]*A+a[i]*a[i]*B+a[i]*C+D;
		if (i!=n)
			X2 += a[i+1]*a[i+1]*a[i+1]*A+a[i+1]*a[i+1]*B+a[i+1]*C+D;
		f[i][0] = max(X1,X2);
		if (i!=n)
			Nex[i][0] = i+1;
	}
	h = 2;
	for (ll k = 1; k <= 20; ++ k){
		h *= 2;
		if (h > n)
			break;
		for (int i = 1;i+h <= n; ++ i)
			Nex[i][k] = Nex[Nex[i][k-1]][k-1];
		
	}
	h = 2;
	for (ll k = 1; k <= 20; ++ k){
		h *= 2;
		if (h > n){
			t = k-1;
			h /= 2;
			break;
		}
		for (ll i = 1; i+h-1 <= n; ++ i){
			if (Min[i][k-1] > Min[Nex[i][k-1]+1][k-1])
				Min[i][k] = Min[Nex[i][k-1]+1][k-1];
			else
				Min[i][k] = Min[i][k-1];
			s1[i][k] = Min[i][k];
			s2[i][k] = Min[i][k]*Min[i][k];
			s3[i][k] = Min[i][k]*Min[i][k]*Min[i][k];
			if (f[i][k-1]+f[Nex[i][k-1]+1][k-1] > A*s3[i][k]+B*s2[i][k]+C*s1[i][k]+D)
				f[i][k] = f[i][k-1]+f[Nex[i][k-1]+1][k-1];
			else
				f[i][k] = A*s3[i][k]+B*s2[i][k]+C*s1[i][k]+D;
		}
	}
	ll i = 1;
	while (i<n){
		while (i+h > n){
			h/=2;
			t--;
		}
		Ans += f[i][t];
		i += h;
	}
	if (i == n)
		Ans += a[n]*a[n]*a[n]*A+a[n]*a[n]*B+a[n]*C+D;
	printf("%lld",Ans);
	return 0;
}
/*
7 0 0 1 10
9 9 5 2 6 4 8
*/

