#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
template <typename T> void read(T &x){
	T f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
long long q_power(long long x,long long y){
	if (y==1){
		return x;
	}
	if (y==0){
		return 1;
	}
	long long k=q_power(x,y/2);
	if (y&1){
		return ((k*k*x)%MOD);
	}
	else {
		return ((k*k)%MOD);
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	read(n);
	long long tot=q_power(26,n);
	char s[1111111];
	scanf("%s",s);
	
	int ll=strlen(s);
	
	long long ans=tot-(2*q_power(26,n-ll)-1);
	while (ans<0){
		ans+=MOD;
	}
	for (int i=1;i<ll;i++){
		ans-=q_power(26,n-ll)-q_power(26,n-ll-i);
		while (ans<0){
			ans+=MOD;
		}
	}
	writeln(ans);
	return 0;
}

