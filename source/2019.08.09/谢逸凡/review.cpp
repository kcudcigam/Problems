#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define REP(i,x) for(int i=head[x];i;i=nxt[i])
#define Rep(i,l,k) for(int i=l;i>=k;i--)
typedef long long ll;
using namespace	std;
const int N=2e5+5;
const int INF=16384;
ll y;
//const int INF=10;
int n;

ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
namespace fivepts{
	int n=INF;
	void Gao(){
		printf("%d %d\n",n,n-1);
	    rep(i,1,n-1) printf("%d %d\n",i,i+1);
	}
}
namespace tenpts{
	int n=INF;
	void Gao(){
		printf("%d %d\n",n,n);
		printf("%d %d\n",1,n);
		rep(i,1,n-1) printf("%d %d\n",i,i+1);
	}
}
namespace fiftypts{
	int n=INF;
	void Gao(){
		printf("%lld %lld\n",n,n+y-1);
		rep(i,1,n-1) printf("%lld %lld\n",i,i+1);
		rep(i,n-y+1,n-1) printf("%lld %lld\n",i,n);
	}
}
namespace qishiwupts{
	ll n=1;
	ll bower(ll x,ll f){
		int ans=0;
		while(x*=2) {if(x==f) break;ans++;}
		return ans;
	}
	void Gao(){
		n=bower(n,y);
		printf("%lld %lld\n",n,y);
		rep(i,1,n) rep(j,i+1,n) printf("%d %d\n",i,j);
	}
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	y=ip();
	if(y==1){fivepts::Gao();return 0;}
	if(y==2){tenpts::Gao();return 0;}
	if(y<INF){fiftypts::Gao();return 0;}
	if(y%2==0&&y>=INF){qishiwupts::Gao();}
	return 0;
}

