#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=1005;
const int M=10005;
int n,X,a[N],b[N],c[N],dp[N][M<<1],f[N][M<<1],res;
//
inline void add(int &x,int y){x+=y;if(x>=MOD)x-=MOD;}
inline void sub(int &x,int y){x-=y;if(x<0)x+=MOD;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%MOD;}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=getint();X=getint();
	rep(i,n)a[i]=getint(),b[i]=getint(),c[i]=getint();
	dp[n][0]=f[n][0]=1;
	int ub=a[n-1]-1;
	for(int i=n-1;i>=0;i--){
		rep(j,ub+1){
			f[i][j]=f[i+1][j];
			if(j-a[i]>=0)add(f[i][j],f[i][j-a[i]]);
		}
		for(int j=ub;j>=a[i]*(c[i]+1);j--){
			sub(f[i][j],f[i][j-a[i]*(c[i]+1)]);
		}
		rep(j,a[i]+X){
			dp[i][j]=dp[i+1][j];
			if(j-a[i]>=0)add(dp[i][j],dp[i][j-a[i]]);
		}
		for(int j=a[i]+X-1;j>=a[i]*(b[i]+1);j--){
			sub(dp[i][j],dp[i][j-a[i]*(b[i]+1)]);
		}
		for(int j=a[i]+X;j<=ub+X;j++)dp[i][j]=dp[i+1][j];
		//rep(j,ub+X+1)printf("%d %d %d %d\n",i,j,f[i][j],dp[i][j]);
	}
	//cout<<f[0][X]<<endl;
	rep(i,M)if(i-X>=0)add(res,mul(dp[0][i],f[0][i-X]));
	cout<<res<<endl;
	return 0;
}
