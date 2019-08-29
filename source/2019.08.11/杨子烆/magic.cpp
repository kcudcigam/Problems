#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
long long ksm(long long a,long long b){
	if(b==0)return 1;
	if(b%2==0) {
		long long jg=ksm(a,b/2);
		long long ans=(jg*jg)%mod;
		return ans;
}
	else{
		long long jg=ksm(a,b/2);
		long long ans=(jg*jg)%mod;
		return (ans*a)%mod;
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	long long n,ans1,ans=0,len=0;
	read(n);
	char c;
	c=getchar();
	for (;'a'<=c&&'z'>=c; c = getchar()) len++;
	ans1=ksm(26,n);
	long long a=len+1,b=n-len,jg;
	int flag=0;
	if(b==0){
		cout<<(ans1+mod-1)%mod;return 0;
	}
	long long s=ksm(26,b-1);
	for(int i=1;i<=a;i++){
		jg=(s*(26-flag))%mod;
		ans=(ans+jg)%mod;
		flag=1;
	}
	ans=(ans1+mod-ans)%mod;
	cout<<ans;
	return 0;
}


