#include<bits/stdc++.h>
using namespace std;
const long long  mod=998244353;
long long n,ans;
char c[1000010];
long long ks(int x,long long y){
	if(y==0){
		return 1;
	}
	if(y==1){
		return x;
	}
	long long v=ks(x,y/2);
	if(y%2==0){
		return v%mod*v%mod;
	}
	else{
		return v%mod*v%mod*26%mod;
	}
}
long long Max(long long x,long long y){
	if(x>=y) return x;
	return y;
}
long long Min(long long x,long long y){
	if(x<=y) return x;
	return y;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",c);
	long long len=strlen(c);
	if(len==n){
		ans=(ks(26,n)-1)%mod;
		printf("%lld",ans);
		return 0;
	}
	long long sum=ks(26,n)%mod;
	for(long long i=0;i<=len;++i){
		
		ans+=ks(26,Max(0,n-len-i))%mod*ks(25,Min(n-len,i))%mod;
		ans%=mod; 
	}
	long long qvq=(sum+mod-ans)%mod;
	printf("%lld",qvq);
	return 0;
}


