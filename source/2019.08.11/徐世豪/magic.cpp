#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define Mod 998244353
using namespace std;
ll n;
char s[1000009];
inline ll ksm(ll k,ll t){
	ll Ans=1;
	while(t){
		if(t%2) {--t;Ans=(Ans*k)%Mod;}
		else {t/=2;k=(k*k)%Mod;}
	}
	return Ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	ll Ans=ksm(26,n);
	scanf("%s",s+1);
	ll k=strlen(s+1);
	if(n==k){
		printf("%lld",Ans-1);
		return 0;
	}
	Ans-=((k+1)*ksm(26,n-k))%Mod;
	int x=n-k-1;
	int t=ksm(26,x);
	for(ll i=1;i<=k;++i){
		Ans=(Ans+t)%Mod;
		if(x>0){
			x--;
			t=(t+ksm(26,x));
		}
	}
	printf("%lld",Ans);
	return 0;
}

