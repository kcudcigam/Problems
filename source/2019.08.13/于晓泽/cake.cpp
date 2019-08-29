#include<cstdio>
using namespace std;
const int N=300+15,mod=1000000007;
int n,m;long long f[N][N];
int main()
 {
 freopen("cake.in","r",stdin);
 freopen("cake.out","w",stdout);
 scanf("%d%d",&n,&m);	
 f[1][1]=1;	
 for(int i=1;i<=n;i++)	
  {
  	for(int j=1;j<=m;j++)
  	 {
  	 	for(int k=1;k<i;k++) {f[i][j]=(f[i][j]+f[k][j]*f[i-k][j]%mod)%mod; }
  	 	
  	 	for(int k=1;k<j;k++) {f[i][j]=(f[i][j]+f[i][k]*f[i][j-k]%mod)%mod; }
	 }
  }	

 printf("%lld\n",f[n][m]);

return 0; 	
 }
