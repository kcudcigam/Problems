#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
int n,m,f[310][310];
int dfs(int n,int m){
	if(n==1 && m==1)return 1;
	if(f[n][m])return f[n][m];
	for(int i=1;i<n;i++)
		(f[n][m]+=dfs(i,m)*dfs(n-i,m))%=mod;
	for(int i=1;i<m;i++)
		(f[n][m]+=dfs(n,i)*dfs(n,m-i))%=mod;
	return f[n][m];
}
int main(){
	freopen("cake.in","r",stdin),freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%lld\n",dfs(n,m));
	return 0;
}
