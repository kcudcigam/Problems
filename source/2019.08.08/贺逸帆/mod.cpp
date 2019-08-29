#include<bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> void fr(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int MOD,n;

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	fr(q);
	while(q--){
		fr(n);fr(MOD);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
			if(i&1){
				ans+=(ll)i*(ll)(i-1);
				ans%=MOD;
			}else{
				ans+=((ll)i*(ll)(i-1)-i+2);
				ans%=MOD;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


