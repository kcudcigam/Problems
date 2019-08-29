#include<bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int n,a[N],mn;
LL A,B,C,D,f[N];
LL Calc(LL x){return ((A*x+B)*x+C)*x+D;}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(A);read(B);read(C);read(D);
	for (int i=1;i<=n;++i) read(a[i]);
	if (n>1000){
		LL ans=0;
		for (int i=1;i<=n;++i) ans+=Calc(a[i]);
		cout<<ans<<'\n';
		return 0;
	}
	for (int i=1;i<=n;++i){
		mn=a[i];
		for (int j=i;j;--j){
			mn=min(mn,a[j]);
			f[i]=max(f[i],f[j-1]+Calc((LL)mn));
		}
	}
	cout<<f[n]<<'\n';
	return 0;
}
