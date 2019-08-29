#include<iostream>
#define F(i,a,b) for (register int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a);
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
#pragma GCC optimize("Ofast")
using namespace std;
inline int read(){
	register char ch=getchar(); register int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
/*
	int a[4];
	F(i,0,3) a[i]=i+1;	
//	F(i,2,10) f[i]=f[i-1]*i+(i-1)*(i-1)+1,cout<<f[i]<<"    GG\n";
	int ans=0,cnt=0;
	do{
		cnt++;
		F(i,0,3) {
			w[cnt][i]=a[i];
			if (cnt>1 && w[cnt-1][i]^a[i]) ans++;
		}
		F(i,0,3) cout<<a[i]<<" ";
		cout<<'\n';
		if (a[0]!=w[cnt-1][0]) cout<<ans<<"\n";
	}while (next_permutation(a,a+4));
	cout<<ans<<"\n";
*/
	register int q=read();
	while (q--){
		register int n=read(),p=read();
//		if (n<=2){
//			if (n==1) cout<<0<<"\n";
//			else cout<<2%p<<"\n";
//			continue;
//		}
		register int tmp=0;
		F(i,1,n) {
			tmp=(1ll*tmp*i+1ll*i*(i-1)-(i&1 ? 0 : i-2))%p;	
			if (tmp<0) tmp+=p;
		}
		cout<<tmp<<"\n";
	}
	return 0;
}


