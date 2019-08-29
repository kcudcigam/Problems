#include<bits/stdc++.h>
using namespace std;
int n;
int q;
long long mod;
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout); 
	scanf("%d",&q);
	while(q--)
	{
	scanf("%d%lld",&n,&mod);
	long long ans=0ll;
	for(int i=2;i<=n;i++)
	{
		ans=(((1ll*ans*i%mod)+(1ll*(i-1)*i%mod)-((i&1)?0:(i-2)))%mod+mod)%mod;
	}
	printf("%lld\n",ans);
	}
}
