#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
const int N=255;
using namespace std;
int n,m,g[5],res;
struct Neko{
	int id,cnt;
}d[N];
ll ans,Max,flag,loc;
int l,r;
bool vis[N];
bool comp(Neko a,Neko b){
	return a.cnt>b.cnt;
}
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
ll G(ll x){
	return 1ll*g[1]*x+1ll*g[2]*x*x+1ll*g[3]*x*x*x+1ll*g[4]*x*x*x*x+1ll*g[5]*x*x*x*x*x;
}
namespace fpts{
	void Gao(){
		ll now=G(d[n].cnt);
		printf("%lld",max(now,n*G(1)));
	}
}
namespace _3_0pts{
	void Gao(){
		ll now=0,res=n,ans=0;
		sort(d+1,d+1+m,comp);
		rep(i,1,m){
			if(res-d[i].cnt<0) {ans+=G(d[i].cnt-res);break;}
			else ans+=G(d[i].cnt),res-=d[i].cnt;
		}
		printf("%lld",ans);
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=ip(),m=ip();rep(i,1,5) g[i]=ip();
	rep(i,1,m) d[i].id=i;
	rep(i,1,n){l=ip(),r=ip();if(l==1&&r==m) flag++;while(l<=r) d[l].cnt++,l++;}
	if(flag==n) fpts::Gao();
	else thpts::Gao();
	return 0;
}
