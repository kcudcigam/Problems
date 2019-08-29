#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p=998244353;
ll f(ll a,ll b){
	int g=1;
	if(b==0) return 1;
	if(b<0) return 0;
	a%=p;
	while(b!=1){
		if(b%2){
			g=((g%p)*(a%p))%p;
			b--;
		}
		else{
			b/=2;
			a=((a%p)*(a%p))%p;
		}
	}
	a=(a%p)*(g%p)%p;
	return a;
}
string s;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ll n,len,sum,ans,mi,da=0,fre;
	cin>>n>>s;
	len=s.size();
	sum=f(26,n);
	if(len==n){
		ans=sum+p-1;
		ans%=p;
		cout<<ans<<endl;
	}
	mi=f(26,n-len);
	mi=(mi%p)*(len+1)%p;
	for(int i=1;i<len;i++){
		fre=n-len-i;
		if(fre<0) break;
		da=da+f(26,fre)%p;
	}
	da=(da*2)%p;
	da=da+(f(26,n-len*2))%p;
	ans=sum+p+da-mi;
	ans%=p;
	cout<<ans<<endl;
	return 0;
}
