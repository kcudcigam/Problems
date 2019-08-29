#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define R register
int q;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
#define ll long long
ll f[10010000];
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout); 
	read(q); 
	while(q--){
		int n,p;
		read(n),read(p);
		f[1]=0;
		for(R int i=2;i<=n;i++){
			if(i%2==0){
				f[i]=((f[i-1]*i%p+1ll*(i-1)*i%p)%p-1ll*(i-2)%p)%p;
				if(f[i]<0) f[i]=(f[i]+p)%p;
			}
			else{
				f[i]=(f[i-1]*i%p+1ll*(i-1)*i%p)%p;
			}
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
