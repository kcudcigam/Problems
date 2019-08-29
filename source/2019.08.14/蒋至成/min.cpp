#include<bits/stdc++.h>
using namespace std;
int n;
long long A,B,C,D;
int	minn[1001][1001],a[1001];
long long f[1001][1001],js[1001][1001],ans;
long long cal(long long x){
	long long aa=A*x*x*x+B*x*x+C*x+D;
	return aa;	
}
long long dp(int x,int y){
	if(f[x][y])return f[x][y];
	long long ans=js[x][y];
	for(int i=x;i<y;++i){
		ans=max(ans,dp(x,i)+dp(i+1,y));
	}
	return f[x][y]=ans;
}
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n);read(A);read(B);read(C);read(D);
	for(int i=1;i<=n;++i){
		read(a[i]);
		f[i][i]=cal(a[i]);
		js[i][i]=f[i][i];
		minn[i][i]=a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			minn[i][j]=min(minn[i][j-1],a[j]);
			js[i][j]=cal(minn[i][j]);
		}
	}
	printf("%lld",dp(1,n));
	return 0;
}


