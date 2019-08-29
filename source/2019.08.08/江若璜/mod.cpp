#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,p,n,a[15]={0,0,2,12,58,310,1886,13244,106002,954090,9540982};
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
ll getans(ll x){
	ll ans=a[10];
	for(ll i=11;i<=x;i++)
		if(i%2==1) ans=((ans*i)%p+i*(i-1))%p;
		else ans=((ans*i)%p+(i-1)*(i-2)+i)%p;
	return ans;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	for(ll i=1;i<=q;i++){
		read(n);read(p);
		if(n<=10){cout<<a[n]%p<<endl;continue;}
		else cout<<getans(n)%p<<endl;
	}
	return 0;
}
