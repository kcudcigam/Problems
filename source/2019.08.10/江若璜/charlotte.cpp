#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100005;
ll T,n,t[N],x[N],y[N],i;
template <typename T> void read(T &a){
	ll f=1;a=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	a*=f;
}
ll ab(ll a){return a<0?-a:a;}
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(i=1;i<=n;i++){read(t[i]);read(x[i]);read(y[i]);}
		for(i=1;i<=n;i++){
			ll far=ab(x[i]-x[i-1])+ab(y[i]-y[i-1]);
			if(far>t[i]-t[i-1]){putchar('N');putchar('o');puts("");break;}
			if((t[i]-t[i-1]-far)&1){putchar('N');putchar('o');puts("");break;}
		}
		if(i==n+1){putchar('Y');putchar('e');putchar('s');puts("");}
	}
	return 0;
}
