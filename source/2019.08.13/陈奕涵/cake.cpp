#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
const int maxn=310;
long long mem[maxn][maxn];
long long dfs(int n,int m){
	if(n>m)swap(n,m);
	//记忆化 
	if(mem[n][m])return mem[n][m];
	//横着切
	for(int i=1;i<n;++i)
		mem[n][m]=(mem[n][m]+dfs(i,m)*dfs(n-i,m))%mod;
	//竖着切
	for(int i=1;i<m;++i)
		mem[n][m]=(mem[n][m]+dfs(n,i)*dfs(n,m-i))%mod;
	//返回
	return mem[n][m];
} 
int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n>m)swap(n,m);
	mem[1][1]=1; 
	dfs(n,m);
	cout<<mem[n][m]<<endl;
	return 0;
} 
