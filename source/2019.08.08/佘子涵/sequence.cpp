#include<cstdio>
#include<iostream>
using namespace std;
const int N=500011;
long long n,m,l,r,s,e,a[N],b[N],ans;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++){
		read(l);read(r);read(s);read(e);
		if(s==e){
			a[l]+=s;a[r+1]-=s;
			continue;
		} 
		a[l]+=s;a[r+1]-=s;
		long long t=(e-s)/(r-l);
		b[l+1]+=t;b[r+1]-=t+e-s;b[r+2]+=e-s;
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	for(int i=1;i<=n;i++){
		a[i]+=b[i];
		ans^=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
