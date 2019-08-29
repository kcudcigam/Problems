#include<bits/stdc++.h>
#define mo 998244353
#define ll long long
using namespace std;
ll n,l;
string s;
ll po(ll x,ll y){if (y<0)return 0;ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>s;
	l=s.length();
	if (n<l) cerr<<"gg"<<endl;
	cout<<(po(26,n)+mo-po(26,n-l)+(mo-l)*(25*po(26,n-l-1)%mo))%mo;
	return 0;
}
