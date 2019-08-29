#include<bits/stdc++.h>
using namespace std;

int num,n,MOD=1e9+7;

int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d %d",&num,&n);
	long long ans=1;
	for (int i=2;i<=n;++i)
		ans=ans*i%MOD;
	ans--;
	printf("%lld\n",ans);
	return 0;
}

