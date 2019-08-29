#include<bits/stdc++.h>
typedef long long ll;
const int MOD=998244353;
using namespace std;
char st[1000005];
ll quick_power(int x,ll a);
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ll N;
	scanf("%lld",&N);
	scanf("%s",&st);
	int M=strlen(st);
	ll XX=26+25*M;
	ll YY=quick_power(26,N-M-1);
	ll ans;
	if  (N>M)
		ans=XX*YY;
	else
		ans=1;
	ll Ans=quick_power(26,N)-ans;
	Ans%=MOD;
	while  (Ans<0)	Ans+=MOD;
	cout<<Ans<<endl;
	return 0;
}
ll quick_power(int x,ll a)
{
	if  (a<=0)	return 1;
	if  (a==1)	return x;
	ll  xx=quick_power(x,a/2);
	if  (a&1)
		return x*xx%MOD*xx%MOD;
	else
		return xx*xx%MOD;
}
