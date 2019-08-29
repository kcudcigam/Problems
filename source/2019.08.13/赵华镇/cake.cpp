#include<iostream>
#include<cstdio>
using namespace std;
long long ans=1,mod=1000000007;
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	long long n,m,i;
	scanf("%lld%lld",&n,&m);
	if(n==1){
		for(i=1;i<=m-1;i++){
			ans=(ans*i)%mod;
		}
		printf("%lld",ans/2);
		return 0;
	}
	for(i=1;i<=m-1;i++){
		ans=(ans*i)%mod;
	}
	printf("%lld",ans);
	return 0;
}
