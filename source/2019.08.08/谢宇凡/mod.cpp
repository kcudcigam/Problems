#include<bits/stdc++.h>
using namespace std;

long long q,n,p;

int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	scanf("%lld",&q);
	while (q--){
		scanf ("%lld%lld",&n,&p);
		long long ans=0;
		for (long long i=2;i<=n;++i)
			if (i&1)	ans=(ans*i+i*(i-1))%p;
				else ans=(ans*i+i*(i-1)-i+2)%p;
		printf("%lld\n",ans);
	} 
	return 0;
}


