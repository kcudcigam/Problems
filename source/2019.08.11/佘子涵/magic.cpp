#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int mod=998244353;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long n,m,t,q,ans,tot;
char x[10000010];
long long pw(long long x){
	long long a=26,ans=1;
	while(x){
		if(x&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		x>>=1;
	}
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);scanf("%s",x);
	m=strlen(x);
	tot=(long long)pw(n);
	t=(long long)(m+1)*pw(n-m)%mod;
	q=(long long)m*pw(n-m-1)%mod;
	printf("%lld\n",(tot-t+q+mod)%mod);
	return 0;
}
