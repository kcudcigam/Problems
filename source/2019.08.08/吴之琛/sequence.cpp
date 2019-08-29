#include<bits/stdc++.h>
#define N 500010
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n,m;
ll dat,tot;
ll ans,s[N],f[N],p[N],res[N];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	while (m--){
		int L,R;
		ll a,b,tmp,k;
		read(L);read(R);read(a);read(b);
		s[L]+=a;
		s[R+1]-=a;
		if (R>L){
			tmp=R-L;
			k=(b-a)/tmp;
		}
		else k=0;
		f[L+1]+=k;
		f[R+1]-=k;
		p[R+1]+=b-a;
	}
	for (int i=1;i<=n;i++) s[i]+=s[i-1];
	for (int i=1;i<=n;i++){
		dat+=f[i];
		tot+=dat-p[i];
		res[i]=tot;
	}
	for (int i=1;i<=n;i++){
		res[i]+=s[i];
		ans=ans xor res[i];
	}
	printf("%lld\n",ans);
	return 0;
}

