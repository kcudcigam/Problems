#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
LL n,a[N],f1[N],f2[N],M1[N],M2[N],ans=-1e18;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);M1[0]=M2[n+1]=-1e18;
	for (int i=1;i<=n;++i) read(a[i]),f1[i]=f2[i]=a[i];
	for (int i=1;i<=n;++i) f1[i]=max(f1[i],f1[i-1]+a[i]),M1[i]=max(M1[i-1],f1[i]);
	for (int i=n;i>=1;--i) f2[i]=max(f2[i],f2[i+1]+a[i]),M2[i]=max(M2[i+1],f2[i]);
	for (int i=1;i<n;++i) ans=max(ans,M1[i]+M2[i+1]);
	cout<<ans<<'\n';
	return 0;
}
