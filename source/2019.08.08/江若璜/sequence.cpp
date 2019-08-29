#include<bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long ll;
ll n,m,x[N],ans;
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(ll i=0,l,r,s,e;i<m;i++){
		read(l);read(r);read(s);read(e);
		for(ll j=l;j<=r;j++) x[j]+=(j-l)*(e-s)/(r-l)+s;
	}
	for(ll i=1;i<=n;i++) ans^=x[i];
	cout<<ans<<endl;
	return 0;
}
