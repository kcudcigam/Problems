#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod=998244353;
ll N;
string S;
ll len;
ll p;
ll gg(int x){
	ll ad=1;
	for(int i=1;i<=x;i++)ad*=26;
	return ad%mod;
}
ll work(ll x){
	if(x<=7)return gg(x)%mod;
	return (work((ll)x/2)*work((ll)(N-x/2)))%mod;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	scanf("%lld",&N);
	cin>>S;
	len=S.length();
	p=N-len;
	if(p==0)printf("%lld",(work(N)-1)%mod); 
	else printf("%lld",(work(N)-((1+len)%mod*work(p))%mod+work(p-1))%mod);
	return 0;
}


