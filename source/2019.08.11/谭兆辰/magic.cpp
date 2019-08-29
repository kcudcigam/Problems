#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long
ll n;
char s[1001000];
const int mod=998244353;
inline ll power(int a,int b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
ll ans;
int len=0;
int now[10010],b[10010];
//bool flag=0;
inline bool print(){
//	if(b[1]==2&&b[2]==1) flag=1;
	for(int i=1;i<=n-len+1;i++){
		bool fg=0;
		for(int j=1;j<=len;j++){
//			if(flag) cout<<b[j]<<" "<<now[i+j-1]<<"\n";
			if(b[i+j-1]!=now[j]){
				fg=1;
				break;
			}
		}
		if(!fg){
//			flag=0;
			return true;
		}
	}
//	flag=0;
	return false;
}
inline void dfs(int x){
	if(x==n+1){
		if(print()) ans--;
		if(ans<0) ans=(ans+mod)%mod;
		return ;
	}
	for(int i=1;i<=26;i++){
		b[x]=i;
		dfs(x+1);
	}
}

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout); 
	scanf("%lld",&n);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++) now[i]=s[i]-'a'+1;
	ans=1;
	for(int i=1;i<=n;i++) ans=1ll*ans*26%mod;
	dfs(1);
	cout<<ans;
	return 0;
}
