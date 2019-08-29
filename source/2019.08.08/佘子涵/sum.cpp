#include<fstream>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
long long n,a[N],s[N],fs[N],mi=1e15,ma=-1e15,maa,mii,z[N],f[N],ans;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	ma=mi=z[1]=s[1]=a[1];
	maa=mii=1;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(ma<s[i]){
			ma=s[i];maa=i;
		}
		if(maa!=mii) z[i]=max(z[i-1],ma-mi);
		else z[i]=z[i-1];
		if(mi>s[i]){
			mi=s[i];ma=mi;maa=mii=i;
		}
	}
	maa=mii=n;
	ma=mi=f[n]=fs[n]=a[n];
	for(int i=n-1;i>=1;i--){
		fs[i]=fs[i+1]+a[i];
		if(ma<fs[i]) ma=fs[i],maa=i;
		if(maa!=mii) f[i]=max(f[i+1],ma-mi);
		else f[i]=f[i+1];
		if(mi>fs[i]) mi=fs[i],ma=mi,maa=mii=i;
	}
	ans=z[1]+f[2];
	for(int i=2;i<n;i++){
		ans=max(z[i]+f[i+1],ans);
	}
	printf("%lld\n",ans);
	return 0;
}
