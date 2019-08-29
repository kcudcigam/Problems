#include<bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,x,a[N],b[N],c[N];
LL f[1<<16],g[1<<16],ans;
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	read(n);read(x);f[0]=g[0]=1;
	for (int i=1;i<=n;++i) read(a[i]),read(b[i]),read(c[i]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=b[i];++j)
			for (int k=a[i];k<x+a[i];++k)
				f[k]=(f[k]+f[k-a[i]])%mod;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=c[i];++j)
			for (int k=a[i];k<x+a[i];++k)
				g[k]=(g[k]+g[k-a[i]])%mod;
	for (int i=x;i<=x+a[n];++i) ans=(ans+f[i]*g[i-x])%mod;
	cout<<ans<<'\n';
	return 0;
}
