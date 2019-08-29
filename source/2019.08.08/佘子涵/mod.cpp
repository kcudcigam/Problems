#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long n,q,p;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	read(q);
	while(q--){
		read(n);read(p);
		long long ans=0;
		for(int i=2;i<=n;i++){
			ans=((ans*i)%p+((i*(i-1))%p))%p;
			if(!(i%2)) ans=(ans-(i-2)+p)%p;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
