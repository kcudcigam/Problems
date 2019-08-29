#include<iostream>
#include<cstdio>
#include<algorithm>
#define rint register int
#define ll long long
using namespace std;
const int maxn=405;
const int inf=1e8;

int ans=0,mod=1000000007;
int n,m;

void dfs(int x,int y){
	if(x==1&&y==1) return;
	for(rint i=1;i<=x/2;++i){
		++ans;
		dfs(i,y);
		dfs(x-i,y);
	}
	for(rint i=1;i<=y/2;++i){
		++ans;
		dfs(x,i);
		dfs(x,y-i);
	}
}

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	if(n==1){
		
	}
	
	dfs(n,m);
	if(ans>mod) ans-=mod;
	printf("%d\n",ans);
	return 0;
	
}

