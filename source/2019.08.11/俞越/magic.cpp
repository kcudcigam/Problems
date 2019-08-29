#include<bits/stdc++.h>
#define LL long long 
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define SZ(x) (int)x.size()-1 
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10,mod=998244353;
LL n;
int len;
char ch[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
namespace FFF{
	char t[M],tt[M];
	int ans;
	void dfs(int x){
		if (x==n+1){
			F(i,1,len+1){
				F(j,1,i-1) tt[j]=t[j];
				F(j,i+n-len,n) tt[j-n+len]=t[j]; 
//				cout<<(t+1)<<" "<<(tt+1)<<"\n";
				if (!strcmp(tt+1,ch+1)){
					ans++;
					return ;
				} 
			}
//			cout<<(tt+1)<<" "<<(ch+1)<<"\n";
//			system("pause");
			return ;
		}
		F(i,0,25){
			t[x]='a'+i;
			dfs(x+1);
		}
	}
	void solve(){
		dfs(1);
		cout<<ans<<"\n";//
		cout<<(fast(26,n)-ans+mod)%mod<<"\n";
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n; scanf("%s",ch+1); len=strlen(ch+1);
//	FFF::solve();
	if (n==len) cout<<1<<"\n";
	else cout<<(fast(26,n)-((len+1)*26-len)*fast(26,n-len-1)%mod+mod)%mod<<"\n";
	return 0;
} 
