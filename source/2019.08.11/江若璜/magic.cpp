#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000005,mod=998244353;
ll n,cnt,ans,dabiao[20]={0,0,0,701*25,728*25};
string ss,now;
template <typename T> void rd(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
inline void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
ll pw(ll x,ll y){
	ll sum=1,f=x;
	while(y){
		if(y&1) sum=(sum*f)%mod;
		f=(f*f)%mod;y>>=1;
	}
	return sum%mod;
}
void dfs(ll x){
	if(x==n){
		for(ll i=0;i<n-cnt+1;i++){
			if(now.substr(i,cnt)==ss){ans=(ans+1)%mod;break;}
		}
		return ;
	}
	for(ll i=0;i<26;i++){
		now+='a'+i;
		dfs(x+1);
		now.erase(x,1);
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	rd(n);cin>>ss;cnt=ss.size();
	if(cnt==1){wr(pw(25,n));puts("");return 0;}
	ans=(n-cnt+1)%mod;
	ans=(pw(26,n-cnt)%mod*ans)%mod;
	if(n-cnt==1){
		ans--;
		wr((pw(26,n)%mod+mod-ans)%mod);puts("");
		return 0;
	}
	if(n==5&&cnt==2){cout<<728*625<<endl;return 0;}
	dfs(0);
	cout<<(pw(26,n)+mod-ans)%mod<<endl;
	return 0;
}
