#include <bits/stdc++.h>
using namespace std;

#define reg register
#define ll long long

const ll mod = 998244353;

ll power(ll a, ll b) {
	ll res=1;
	for (; b; b>>=1) {
		if (b&1) (res*=a)%=mod;
		(a*=a)%=mod;
	}
	return res;
}

ll n, ans; string str;

int main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	cin>>n; cin>>str;
	ll len=str.size();
	if (len==n) {
		cout<<(power(26, n)-1+mod)%mod<<endl;
		return 0;
	}
	ans=((power(26, n)-(len+1)%mod*power(26, n-len)%mod+mod)%mod+len%mod*power(26, n-len-1)%mod)%mod;
	cout<<ans<<endl; 
	return 0;
}

