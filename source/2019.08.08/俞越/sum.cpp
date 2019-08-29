#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a);
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
LL w[M],L[M],R[M];
int n;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	n=read(); 
	F(i,1,n) w[i]=read();
	L[1]=w[1];
	F(i,2,n){
		L[i]=max(L[i-1]+w[i],w[i]);
	}
	F(i,2,n) L[i]=max(L[i],L[i-1]);
	R[n]=w[n];
	DF(i,n-1,1){
		R[i]=max(R[i+1]+w[i],w[i]);
	}
	DF(i,n-1,1) R[i]=max(R[i],R[i+1]);
	LL ans=LONG_LONG_MIN;
	F(i,2,n){
		ans=max(L[i-1]+R[i],ans);
	}
	cout<<ans<<"\n";
	return 0;
}

