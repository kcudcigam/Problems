#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
#define ll long long
ll n;
bool vis[20];
inline bool work(int x){
	int cnt=0;
	for(int i=0;i<=10;i++) vis[i]=0;
	while(x){
		if(!vis[x%10]){
			if(cnt==2) return false;
			else cnt++,vis[x%10]=1;
		}
		x/=10;
	}
	return true;
}
int cnt;
bool fg=0;
int a[300300],tot=0;
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
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(register int i=1;i<=999999;i++){
		if(work(i)) a[++tot]=i;
	}
	cout<<tot;
	while(t--){
		scanf("%lld",&n);
		cnt=0;
		while(1){
			cnt++;
			dfs(n,1);
			if(fg){
				printf("%d\n",cnt);
				break;
			}
		}
		fg=0;
	}
	return 0;
}
