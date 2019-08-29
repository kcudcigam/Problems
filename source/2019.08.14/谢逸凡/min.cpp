#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=3e5+5;
ll A,B,C,D,n,a[N],ans,flag;
ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
} 
ll f(ll x){return ((A*x+B)*x+C)*x+D;}
namespace _20pts{
	ll sum=INF,cnt=0,zcy[N],nmsl[N],ans=0;
	void Gao(){
		rep(i,1,n){
		if(f(a[i])>0) ans+=f(a[i]);
		else zcy[++cnt]=a[i],nmsl[cnt]=i;
	    }
	    rep(i,1,cnt){
	    	if(nmsl[i]==nmsl[i-1]+1) sum=min(sum,zcy[i]);
	    	else ans+=sum,sum=INF;
		}
	    printf("%lld\n",ans);
    }
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	n=ip(),A=ip(),B=ip(),C=ip(),D=ip();
	rep(i,1,n) a[i]=ip();
	if(A==0&&B==0&&C<0){
		_20pts::Gao();
		return 0;
	}
	rep(i,1,n){ans+=f(a[i]);}
	printf("%lld\n",ans);
	return 0;
}

