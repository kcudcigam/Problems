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
const int M=2e4+10,mod=1000000007;
LL g[2][M],f[2][M];
int a[M],b[M],c[M],n,X;
void ck(LL &x){
	if (x>mod) x-=mod;
	if (x<0) x+=mod;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read(); X=read(); int mx=X;
	F(i,1,n){
		a[i]=read(); b[i]=read(); c[i]=read();
		mx=max(mx,a[i]+X);
	}
	int now=0;
	g[0][0]=1;
	F(i,1,n){
		now^=1; //ms(g[now],0);
		int del=(c[i]+1)*a[i];
		F(j,0,a[i]-1){
			LL tmp=0; int ct=-1;
			for (int k=j;k<=mx;k+=a[i]){
				ct++;
				tmp+=g[now^1][k];
				if (ct>c[i]) tmp-=g[now^1][k-del];
				ck(tmp);
				g[now][k]=tmp;
//				ck(g[now][k]); 
//				if (ct==c[i]) break;
			}
		}
	}
	now=0;
	f[0][0]=1;
	DF(i,n,1){
		now^=1; //ms(f[now],0);
		int del=(b[i]+1)*a[i];
		F(j,0,a[i]-1){
			LL tmp=0; int ct=-1;
			for (int k=j;k<=mx;k+=a[i]){
				ct++;
				tmp+=f[now^1][k];
				if (ct>b[i]) tmp-=f[now^1][k-del];
			 	ck(tmp);
				if (k<X+a[i]) f[now][k]=tmp;
				else f[now][k]=f[now^1][k];
//				ck(f[now][k]);
//				if (ct==b[i]) break;
			}
		}
//		F(i,0,mx)
//		cout<<f[now][i]<<" ";
//		cout<<"\n";
	}
	LL ans=0;
	F(i,X,mx){
//		cout<<i<<" "<<g[now][i-X]<<" "<<f[now][i]<<"\n";
		ans=(ans+g[now][i-X]*f[now][i])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
