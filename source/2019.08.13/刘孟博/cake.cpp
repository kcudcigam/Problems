#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=311,MOD=1000000007;
int n,m,f[MAXN][MAXN];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
inline int dfs(int n,int m){
	if(~f[n][m])return f[n][m];
	if(n==1&&m==1)return f[n][m]=1;
	int res=0;
	for(int i=1;i<n;i++) res=(ll)(res+(ll)dfs(i,m)*dfs(n-i,m))%MOD;
	for(int i=1;i<m;i++) res=(ll)(res+(ll)dfs(n,i)*dfs(n,m-i))%MOD;
	return f[n][m]=f[m][n]=res;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)f[i][j]=-1;
	printf("%d\n",dfs(n,m));
	return 0;
}
