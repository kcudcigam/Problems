#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int Mod=1000000007;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,m;
LL dp[310][310];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=R();m=R();
	dp[1][1]=1;
	F(i,1,n)F(j,1,m){
		F(k,1,i-1)dp[i][j]=(dp[i][j]+dp[k][j]*dp[i-k][j])%Mod;
		F(k,1,j-1)dp[i][j]=(dp[i][j]+dp[i][k]*dp[i][j-k])%Mod;
	}
	cout<<dp[n][m]<<'\n';
	return 0;
}
