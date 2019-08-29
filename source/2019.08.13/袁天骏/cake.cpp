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
const int N=305;
int n,m,dp[N][N];
//
inline void add(int &x,int y){x+=y;if(x>=MOD)x-=MOD;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%MOD;}
int go(int x,int y){
	if(dp[x][y]>=0)return dp[x][y];
	if(x==y&&x==1)return dp[x][y]=1;
	int ans=0;
	for(int i=1;i<=x-1;i++)add(ans,mul(go(i,y),go(x-i,y)));
	for(int i=1;i<=y-1;i++)add(ans,mul(go(x,i),go(x,y-i)));
	return dp[x][y]=ans;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=getint();m=getint();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",go(n,m));
	return 0;
}
