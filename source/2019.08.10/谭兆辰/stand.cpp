#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
#define N 300
int n,m,g[6];
struct node{
	int l,r;
}s[N];
#define ll long long
#include <algorithm>
inline ll calc(int x){
	return 1ll*g[1]*x+1ll*g[2]*x*x+1ll*g[3]*x*x*x+1ll*g[4]*x*x*x*x+1ll*g[5]*x*x*x*x*x;
}
struct code{
	int l,r,c;
}f[N];
inline bool cmp(node x,node y){
	return x.l<y.l||(x.l==y.l&&x.r<y.r);
}
int b[N],cnt,lst[N],tmp[N];
inline int print(){
	int nowl=0,sum=0,nowr=1e9;
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			sum++;
			if(s[i].r<nowl||s[i].l>nowr) return 0;
			else nowl=max(nowl,s[i].l),nowr=min(nowr,s[i].r);
		}
	}
	return sum;
}
int maxx=0;
bool vis[N];
inline void dfs(int x){
	if(x==n+1){
		int k=print();
		if(maxx<k){
			int num=0;
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					tmp[++num]=i;
				}
			}
			maxx=k;
		}
		return ;
	}
	for(int i=1;i<=2;i++){
		if(!vis[x]) b[x]=i;
		else b[x]=0;
		dfs(x+1); 
	}
}
bool mp[10001];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=5;i++) read(g[i]);
	for(int i=1;i<=n;i++) read(s[i].l),read(s[i].r);
	sort(s+1,s+1+n,cmp);
	if(n<=20){
		ll ans=0;
		int now=0;
		for(int i=1;i<=n;i++){
			bool fg=0;
			maxx=0;
			for(int j=1;j<=n;j++) b[j]=0;
			dfs(1);
			for(int j=1;j<=maxx;j++) vis[tmp[j]]=1;
			now+=maxx;
			ans+=calc(maxx);
			if(now==n){
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m<=50){
		ll ans=0;
		int maxx=0,now,num=0;
		while(num<n){
			maxx=0;
			for(int i=1;i<=m;i++){
				if(!mp[i]){
					int cnt=0;
					for(int j=1;j<=n;j++){
						if(!vis[j]&&s[j].l<=i&&s[j].r>=i){
							cnt++;
						}
					}
					if(maxx<cnt) maxx=cnt,now=i;
				} 
			} 
			ans+=calc(maxx);
			mp[now]=1;
			for(int i=1;i<=n;i++){
				if(s[i].l<=now&&s[i].r>=now){
					vis[i]=1;
					num++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0; 
}
