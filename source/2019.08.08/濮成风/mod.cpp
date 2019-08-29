#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int T,n,mod;
void solve()
{
	ll ans=0,sum1=6,sum0=2,d1=6,d0=8;
	for(int i=2;i<=n;++i)
	{
		if(i&1)
		{
			ans=(ans*(ll)i+sum1)%mod;
			d1+=8;
			sum1+=d1;
		}
		else
		{
			ans=(ans*(ll)i+sum0)%mod;
			sum0+=d0;
			d0+=8;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>mod;
		solve();
	}
	return 0;
}

