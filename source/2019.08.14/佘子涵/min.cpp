#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long n,a,b,c,d,q[200010],f[1010][1010],mi[1010][1010];
long long so(long long x){
	return (long long)a*x*x*x+b*x*x+c*x+d;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(a);read(b);read(c);read(d);
	for(int i=1;i<=n;i++) read(q[i]);
	for(int i=1;i<=n;i++){
		mi[i][i]=q[i];
		for(int j=i+1;j<=n;j++){
			mi[i][j]=min(mi[i][j],q[j]);
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=so(q[i]);
	for(int i=1;i<=n;i++){
		for(int j=n-i+1;j>=1;j--){
			f[i][j]=so(mi[j][j+i-1]);
			for(int l=1;l<=i;l++){
				f[i][j]=max(f[i][j],f[l][j]+f[i-l][j+l]);
			}
		}
	}
	printf("%lld\n",f[n][1]);
	return 0;
}
