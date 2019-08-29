#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll A,B,C,D,a[1<<18],mxf[1<<18],f[1<<18],_,v[1<<18];
int n;
multiset<ll> s;
ll F(long long x){
	return ((A*x+B)*x+C)*x+D;
}
int main(){
	freopen("min.in","r",stdin),freopen("min.out","w",stdout);
	cin>>n>>A>>B>>C>>D;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		ll t=-LLONG_MAX;
		while(_ && v[_]>=a[i]){
			s.erase(s.find(F(v[_])+mxf[_]));
			t=max(t,mxf[_]);
			_--;
		}
		v[++_]=a[i],mxf[_]=max(t,f[i-1]),s.insert(F(a[i])+mxf[_]);
		f[i]=*--s.end();
	}
	printf("%lld\n",f[n]);
	return 0;
}
