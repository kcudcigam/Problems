#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N=105;
ll n,a=1,k=2,sw[N];
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
/*ll pw(ll x,ll y){
	if(y==0) return 1;
	ll sum=1,k=x;
	while(y){
		if(y&1) sum*=k;
		k*=k;y>>=1;
	}
	return sum;
}*/
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	read(n);
	while(a<n) a*=2,k++;
	if(a==n){
		cout<<k<<' '<<k*(k-1)/2<<endl;
		for(ll i=1;i<k;i++)
			for(ll j=i+1;j<=k;j++) cout<<i<<' '<<j<<endl;
		return 0;
	}
	ll cnt=0,cntuse=0;
	while(n){
		if(n&1) sw[cnt]=1,cntuse++;
		n>>=1;cnt++;
	}
	cout<<k<<' '<<(k-1)*(k-2)/2+cntuse<<endl;
	for(ll i=1;i<k-1;i++)
		for(ll j=i+1;j<k;j++) cout<<i<<' '<<j<<endl;
	for(ll i=0;i<N;i++)
		if(sw[i]) cout<<i+2<<' '<<k<<endl;
	return 0;
}
