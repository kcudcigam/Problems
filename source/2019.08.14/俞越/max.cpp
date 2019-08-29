#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10,mod=1e9+7,inf=2e9;
int n,m,q,X[M],Y[M],P[M];
int L[M],R[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int eg[M];
LL ans;
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=read(); m=read(); q=read();
	F(i,1,m){
		X[i]=read(); Y[i]=read(); P[i]=read();
	}
	F(i,1,q) {
		L[i]=read(); R[i]=read();
	}
	F(i,0,(1<<m)-1){
		LL PP=1;
		F(j,1,n) eg[j]=inf;
		F(j,0,m-1){
			if (i>>j&1){
				PP=PP*P[j+1]%mod;
				eg[X[j+1]]=min(eg[X[j+1]],Y[j+1]);
			}
			else PP=PP*(1-P[j+1]+mod)%mod;
		}
		if (!PP) continue;
		LL tmp=0;
		F(j,1,q){
			int val=0;
			F(k,L[j],R[j]){
				if (eg[k]!=inf) val=max(val,eg[k]);
			}
			tmp+=val;
//			cout<<val<<"\n";
		}
		tmp%=mod;
		ans=(ans+PP*tmp)%mod;
//		cout<<tmp<<" "<<PP<<" "<<i<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}




