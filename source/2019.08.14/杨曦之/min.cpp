#include<bits/stdc++.h>
using namespace std;
long long q[200000+10];
long long n,a,b,c,d,ans=0;
long long f(long long x){
	long long y;
	y=c*x+d;
	return y;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int i;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
	for(i=1;i<=n;i++){
		scanf("%lld",&q[i]);
	}
	for(i=1;i<=n;i++){
		if(q[i]<0) ans+=f(q[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

