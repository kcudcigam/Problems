#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){f=-1;}ch=getchar();
	}
	while(ch<='9'&&ch>='0'){x*=10;x+=(ch-'0');ch=getchar();
	}return x*f;
}
int A[6];int n;
long long  dp[1005][1005];
int vis[1005][1005];
int a[200005];
inline long long f(int x){
	long long z=0;
	for(int i=1;i<=3;++i){
		z+=A[i];
		z*=x;
	}
	z+=A[4];
	return z;
}
long long dfs(int x,int y){
	if(x>y) return 0;
	if(vis[x][y]){
		return dp[x][y];
	}
	if(x==y){
		vis[x][y]=1;
		dp[x][y]=f(a[x]);return dp[x][y];
	}
	if((x+1)==y){
		vis[x][y]=1;
		dp[x][y]=f(min(a[x],a[y]));return dp[x][y];
	}
	for(int i=x;i<=y;++i){
		for(int j=i+1;j<=y;++j){
			dp[x][y]=max(dp[x][y],dfs(x,i)+dfs(i+1,j)+dfs(j+1,y));
		}
	}
	vis[x][y]=1;
	return dp[x][y];
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=read(),A[1]=read(),A[2]=read(),A[3]=read(),A[4]=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	cout<<dfs(1,n);
}

