#include<bits/stdc++.h>
using namespace std;

const int mo=998244353;

long long qm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=(res*a)%mo;
		b>>=1;
		a=(a*a)%mo;
	}
	return res;
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n,sum,count;
	string s;
	cin>>n>>s;
	int a=s.size();
	sum=qm(26,a)-a-1;
	count=qm(26,n-a);
	int ans=(sum*count)%mo;
	if(n%a==0) ans+=a;
		cout<<ans;
//	sum=qm(26,n);
//	count=((s.size()+1)*qm(26,n-s.size()))%mo;
//	if(n-s.size()==s.size()) count-=s.size();
//	cout<<sum%mo-count%mo;
	return 0;
}
