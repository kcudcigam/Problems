#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define ll long long
const int N=300005;
ll T,n,ans;
ll mp[10];
bool vis[N];
ll ip(){
	ll x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
bool check(ll x){
	ll ans=0;
	while(x) mp[x%10]++,x/=10;
	rep(i,0,9) if(mp[i]) ans++;
	return ans<=2?1:0;
}
//void Gao(ll x,ll ans,ll sum){
//	if(vis[x]) return;
//	if(sum==x) {printf("%lld\n",ans);return;}
//	if(sum>x){ans=sum=0;return;}
//	rep(i,1,x){
//		if(!check(i)) continue;
//		vis[i]=1;
//		Gao(x,ans+1,sum+i);vis[i]=0;
//	}
//}
namespace _5pts{
	void Nekosaiko(int x){
		if(check(x)) printf("1\n");
		else printf("0\n");
	}
}
namespace _20pts{
	void NEkosaiko(int x){
		rep(i,1,x){
			if(check(i)&&check(x-i)) ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("number.txt","r",stdin);
	freopen("number.txt","w",stdout);
    T=ip();
    while(T--){n=ip();_5pts::Nekosaiko(n);}
	return 0;
}


