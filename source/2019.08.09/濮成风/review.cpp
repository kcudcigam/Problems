#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,size;
vector<int>ans[666];
int count(ll x)
{
	int sum=0;
	while(x)
		x/=2,++sum;
	return sum;
}
ll qpow(ll x,ll y)
{
	ll ans=1,base=x;
	while(y)
	{
		if(y&1)
			ans=ans*base;
		base=base*base;
		y>>=1;
	}
	return ans;
}
int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int m=count(n);
	if(qpow(2,m-1)==n)
	{
		++m;
		for(int i=1;i<=m;++i)
			for(int j=i+1;j<=m;++j)
			{
				ans[i].push_back(j);
				++size;
			}
	}
	else
	{
		m+=2;
		for(int i=2;i<=m;++i)
			for(int j=i+1;j<=m;++j)
			{
				ans[i].push_back(j);
				++size;
			}
		for(ll i=0;i<64;++i)
		{
			if(n&((ll)(1)<<i))
			{
				ans[1].push_back(m-i-1);
				++size;
			}
		}
	}
	cout<<m<<" "<<size<<endl;
	for(int i=1;i<=m;++i)
		for(int j=0;j<ans[i].size();++j)
			cout<<i<<" "<<ans[i][j]<<endl;
	return 0;
}

