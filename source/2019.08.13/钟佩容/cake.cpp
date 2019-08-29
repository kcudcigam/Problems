#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f[300][300];
int dfs(int x,int y){
	if (x==1&&y==1) return 1;
	else if (f[x][y]!=0) return f[x][y]%1000000007;
	else{
	   int tot=0;
	   for (int i=1;i<=x-1;i++)
	      tot=tot+(dfs(i,y)*dfs(x-i,y))%1000000007;
	   for (int i=1;i<=y-1;i++)
	      tot=tot+(dfs(x,i)*dfs(x,y-i))%1000000007;
	   f[x][y]=tot;f[y][x]=tot;
	   return tot;
	}
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n-1;i++)
	   ans=ans+dfs(i,m)*dfs(n-i,m)%1000000007;
	for (int i=1;i<=m-1;i++)
	   ans=ans+dfs(n,i)*dfs(n,m-i)%1000000007;
	cout<<ans<<endl;
	   

	return 0;
}

