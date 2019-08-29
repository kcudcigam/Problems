#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar())if(ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
ll solve(int n,ll p){
	if (n<=4){
		if (n==1) return 0%p;
		else if (n==2) return 2%p;
		else if (n==3) return 12%p;
		else if (n==4) return 58%p;
	}
	ll tmp=58;
	ll ans=0;
	for (ll i=5;i<=n;i++){
		if (i%2==1) ans=(tmp*i%p+i*(i-1)%p)%p;
		else ans=(tmp*i%p+i%p+(i-1)*(i-2)%p)%p;
		tmp=ans%p;
//		printf("%lld\n",ans);
//		assert(ans>=0);
	}
	return ans%p;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int T;
	for (read(T);T;T--){
		int n;ll p;
		read(n),read(p);
		printf("%lld\n",solve(n,p));
	}
	return 0;
}

/*
10
1 530093761
2 892208769
3 659909301
4 348347651
5 703875913
6 870865473
7 61687961
8 334373509
9 826163921
10 735259938
*/
