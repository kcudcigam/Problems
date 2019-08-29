#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL p=1000000007ll;
const int N=1010;
const int M=10+(int)(2e4);

int n,m,k;
int a[N],b[N],c[N];
LL ans;
LL f[N][M],g[N][M];

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void Work(int *a,int *b,LL f[N][M]){
	f[0][0]=1ll;
	int t;
	LL x;
	for (int i=1;i<=n;++i){
		t=a[i]*(b[i]+1);
		for (int j=0;j<a[i];++j) f[i][j]=f[i-1][j];
		for (int j=a[i];(j<t)&&(j<=m);++j){
			x=f[i-1][j]+f[i][j-a[i]];
			x=(x<p)?x:(x-p);
			f[i][j]=x;
		}
		for (int j=t;j<=m;++j){
			x=f[i-1][j]+f[i][j-a[i]];
			x=(x<p)?x:(x-p);
			x=(x>=f[i-1][j-t])?(x-f[i-1][j-t]):(x-f[i-1][j-t]+p);
			f[i][j]=x;
		}
	}
}

int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=rd();k=rd();
	for (int i=n;i>0;--i){
		a[i]=rd();b[i]=rd();c[i]=rd();
	}
	m=k+a[1];
	
	Work(a,b,f);
	Work(a,c,g);
	ans=0ll;
	a[n+1]=0;
	for (int i=1;i<=n;++i){
		for (int j=k+a[i+1];j<k+a[i];++j)
			ans=(ans+f[i][j]*g[n][j-k])%p;
	}
	cout<<ans<<'\n';
	return 0;
}
