#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
int sum,a[100];
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
ll poww(int y){
	ll x=2,tx=1;
	while (y){
		if (y&1) tx*=x;
		x*=x;
		y>>=1;
	}
	return tx;
}
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	read(n);read(k);
	int t=-1;
	while (n){
		a[++t]=n&1;
		n>>=1;
		if (a[t]) ++sum;
	}
	if (sum<=k){
		printf("%d\n",0);
		return 0;
	}
	int d=sum-k+1;
	for (int i=0;i<=t;i++){
		if (a[i]){
			d--;
			ans+=poww(i);
			if (!d){
				ans=poww(i+1)-ans;
				printf("%lld\n",ans);
				return 0;
			}
		}
	}
	return 0;
}

