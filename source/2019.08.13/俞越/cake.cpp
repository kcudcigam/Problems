#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=333,mod=1000000007;
LL dp[M][M];
LL dfs(int x,int y){
	if (dp[x][y]) return dp[x][y];
	LL tmp=0;
	F(i,1,x-1){//?
		tmp+=dfs(i,y)*dfs(x-i,y);
		tmp%=mod;
	}
	F(i,1,y-1){
		tmp+=dfs(x,i)*dfs(x,y-i);
		tmp%=mod;
	}
//	if (x==2 && y==2) cout<<tmp<<" GG\n";
	return dp[x][y]=tmp;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m; n=read(); m=read();
	dp[1][1]=1;
	cout<<dfs(n,m)<<"\n";
//	cout<<dfs(2,2)<<"\n";
	return 0;
}
