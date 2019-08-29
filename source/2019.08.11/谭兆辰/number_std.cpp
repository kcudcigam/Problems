#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
#define ll long long
ll n;
bool vis[20];
ll a[10001000];
int tot=0;
#include <map>
map<int,int> q;
inline void work(int x,int y){
	for(int i=0;i<(1<<6);i++){
		int num=0;
		tot++;
		a[tot]=0;
		for(int j=0;j<6;j++){
			if((i>>j)&1){
				a[tot]=1ll*a[tot]*10+1ll*x;
			}
			else{
				a[tot]=1ll*a[tot]*10+1ll*y;
			}
		}
		if(!q[a[tot]]) q[a[tot]]=1;
		else tot--;
	}
}
int cnt;
bool fg=0;
int b[300300];
inline void dfs(ll x,int p){
	if(p==cnt+1){
		if(!x){
			fg=1;
//			for(int i=1;i<=cnt;i++) cout<<b[i]<<" ";
			return ;
		}
		return ;
	}
	for(int i=1;i<=tot&&a[i]<=x;i++){
		if(fg) return ;
		b[p]=a[i];
		dfs(x-a[i],p+1);
	}
	return ;
}
#include <algorithm>
int main(){
//	scanf("%d",&t);
	for(int i=0;i<=9;i++){
		for(int j=i;j<=9;j++){
			work(i,j);
		}
	}
	sort(a+1,a+1+tot);
	cout<<tot; 
//	for(int i=1;i<=tot;i++) cout<<a[i]<<" ";
//	while(t--){
//		scanf("%lld",&n);
//		cnt=0;
//		while(1){
//			cnt++;
//			dfs(n,1);
//			if(fg){
//				printf("%d\n",cnt);
//				break;
//			}
//		}
//		fg=0;
//	}
	return 0;
}
