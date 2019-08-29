#include<bits/stdc++.h>
using namespace std;
int n,m; 
int f[301][301];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long dfs(int x,int y){
	if(x==1&&y==1)return 1;
	if(f[x][y])return f[x][y];
	long long ans=0;
	for(int i=1;i<x;++i){
	ans+=(dfs(i,y)*dfs(x-i,y));
	ans%=1000000007;	
	}
	for(int i=1;i<y;++i){
	ans+=(dfs(x,i)*dfs(x,y-i));
	ans%=1000000007;
	}
	return f[x][y]=f[y][x]=ans;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout); 
	read(n);read(m);
	if(n==1&&m==1)cout<<0; 
	else cout<<dfs(n,m)%1000000007;
	return 0;
}

