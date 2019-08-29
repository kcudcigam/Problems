#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define INF 100000000000001
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n;
ll ans;
ll a[N],s[N],f[N],s2[N],f2[N];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++){
		s2[i]=s[i]=s[i-1]+a[i];
		if (s[i]<0){
			s[i]=0;
			s2[i]=a[i];
		}
	}
	for (int i=n;i>=1;i--){
		f2[i]=f[i]=f[i+1]+a[i];
		if (f[i]<0){
			f[i]=0;
			f2[i]=a[i];
		}
	}
	for (int i=2;i<=n;i++) s2[i]=max(s2[i-1],s2[i]);
	for (int i=n-1;i>=1;i--) f2[i]=max(f2[i+1],f2[i]);
	ans=-INF;
	for (int i=1;i<=n-1;i++) ans=max(ans,s2[i]+f2[i+1]);
	printf("%lld\n",ans);
	return 0;
}

