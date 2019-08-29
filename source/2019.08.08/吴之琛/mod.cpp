#include<bits/stdc++.h>
#define ll long long
#define N 10000001
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
}
int q,n;
ll p;
ll f[N];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	while (q--){
		read(n);read(p);
		for (ll i=2;i<=n;i++)
			if (i&1) f[i]=(f[i-1]*i+i*i-i)%p;
			else f[i]=(f[i-1]*i+i*i-2*i+2LL)%p;
		printf("%lld\n",f[n]);
	}
	return 0;
}

