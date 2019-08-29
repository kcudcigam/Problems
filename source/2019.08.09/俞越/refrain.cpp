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
const int mod=1e9+7;
namespace FFFUCK{
	const int M=100;
	int n,m1,m2;
	struct node{
		int x,y;
	}a1[M],a2[M];
	bool g1[M][M],g2[M][M];
	int p[M];
	void solve(){
		n=read(); m1=read(); m2=read();
		F(i,1,m1){
			a1[i]=(node){read(),read()};
			g1[a1[i].x][a1[i].y]=g1[a1[i].y][a1[i].x]=1;
		}
		F(i,1,m2){
			a2[i]=(node){read(),read()};
			g2[a2[i].x][a2[i].y]=g2[a2[i].y][a2[i].x]=1;
		}
		F(i,1,n) p[i]=i;
		int ans=0;
		do{
			bool flag=0;
			F(i,1,m1){
				if (!g1[p[a1[i].x]][p[a1[i].y]]) {
					flag=1;
					ans++;
					break;
				}
			}
			if (flag) continue;
			F(i,1,m2){
				if (!g2[p[a2[i].x]][p[a2[i].y]]) {
					flag=1;
					ans++;
					break;
				}
			}
			/*
			if (!flag){
				F(i,1,n) cout<<p[i]<<" ";
				cout<<"\n";
			}
			*/
		}while (next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";
	}
	LL fast(LL x,LL p){
		LL ret=1;
		for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
		return ret;
	}
	bool v[M];
	LL f[M];
	void solvee(){
//		cout<<mod<<"\n";
		n=read(); m1=read(); m2=read();
		F(i,1,m1){
			a1[i]=(node){read(),read()};
			g1[a1[i].x][a1[i].y]=g1[a1[i].y][a1[i].x]=1;
//			v[a1[i].x]=1; v[a1[i].y]=1;
		}
		F(i,1,m2){
			a2[i]=(node){read(),read()};
			g2[a2[i].x][a2[i].y]=g2[a2[i].y][a2[i].x]=1;
		}
		f[0]=1;
		F(i,1,n) f[i]=f[i-1]*i%mod;
		LL ans=(f[n]-fast(2,m1+m2)*f[n-m1*2-m2*2]%mod*f[m1]%mod*f[m2]%mod+mod)%mod;
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int Num=read();
	if (Num<=6){
		FFFUCK::solve();
		return 0;
	}
	else {
		if (Num<=10){
			FFFUCK::solvee();
			return 0;
		}	
		else {
			int n=read();
			LL tmp=1;
			F(i,1,n) tmp=tmp*i%mod;
			tmp=(tmp-1+mod)%mod;
			cout<<tmp<<"\n";
		}
	}

	return 0;
}



