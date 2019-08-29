#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	string s;
	cin>>n>>s;
	long long n1=n-s.size(),p=1;
	while(n1--)
	{
		p*=26;
		p%=MOD;
	}
	long long r=p;
	for(int i=1;i<=s.size();i++)
	{
		r*=26;
		r%=MOD;
	}
	p*=(s.size()+1);p%=MOD;
	int ans=r-p+s.size();
	while(ans<0) ans+=MOD;
	cout<<ans%MOD<<endl;
	return 0;
}

