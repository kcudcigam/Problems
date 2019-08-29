#include<bits/stdc++.h>
#define N 1010
using namespace std;
int n,m,a[N],ans;
void dfs(int dep,int sum,int tmp){
	if(dep>n){
		ans=max(ans,tmp);
		return;
	}
	if(sum+a[dep]<=m){
		dfs(dep+2,sum+a[dep],tmp+1);
	}
	dfs(dep+1,sum,tmp);
}
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}

