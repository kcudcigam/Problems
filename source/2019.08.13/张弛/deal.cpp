#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1100,p=1e9+7;
int f[N][N],ff[N][N],g[N][N],a[N],b[N],c[N];
void add(int &x,int y){
	x+=y;
	if(x>=p) x-=p;
}
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
signed main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int n=read(),X=read();
	for(int i=n;i;i--)
		a[i]=read(),b[i]=read(),c[i]=read();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2*X;j++)
			for(int k=0;k<=b[i];k++)
				if(j-k*a[i]>=0){
					add(f[i][j],f[i-1][j-k*a[i]]);
					if(k) add(ff[i][j],f[i-1][j-k*a[i]]);
				}
				
	g[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2*X;j++)
			for(int k=0;k<=c[i];k++)
				if(j-k*a[i]>=0) add(g[i][j],g[i-1][j-k*a[i]]);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=X;j<X+a[i];j++)
			ans=(ans+ff[i][j]*g[n][j-X])%p;
	cout<<ans<<"\n";
	return 0;
}
