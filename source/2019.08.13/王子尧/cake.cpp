#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define mo 1000000007
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int dp[310][310];

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);

	int n,m;read(n);read(m);
	dp[1][1]=1;
	rep(i,1,n){
		rep(j,1,m){
			if(dp[i][j])continue;
			rep(k,1,i-1){
				dp[i][j]+=(1ll*dp[k][j]*dp[i-k][j])%mo;	
				dp[i][j]%=mo;
			}
			rep(k,1,j-1){
				dp[i][j]+=(1ll*dp[i][k]*dp[i][j-k])%mo;
				dp[i][j]%=mo;
			}
			dp[j][i]=dp[i][j];
		}
	}
	write(dp[n][m]);
	return 0;
}
