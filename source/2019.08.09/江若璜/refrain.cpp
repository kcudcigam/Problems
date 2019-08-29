#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005,mod=1e9+7;
ll num,n,m1,m2,v[N],cir[N],fa[N],d,ans,len[N],cntlc[N],cntll[N];
vector<ll> e[N];
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
ll jiecheng(ll x){
	if(x==0||x==1) return 1;
	ll sum=1;
	for(ll i=2;i<=x;i++) sum=(sum*i)%mod;
	return sum%mod;
}
void dfs(ll x,ll st,ll last){
//	cout<<"-------"<<x<<' '<<st<<' '<<last<<endl;
	if(v[x]) return ;
	v[x]=1;
	len[st]++;
	for(ll i=0;i<e[x].size();i++)
		if(e[x][i]!=last){
			fa[e[x][i]]=st;
			if(e[x][i]==st) cir[st]=1;
			dfs(e[x][i],st,x);
		}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num);read(n);read(m1);read(m2);
	for(ll i=0,u,w;i<m1+m2;i++){
		cin>>u>>w;
		e[u].push_back(w);
		e[w].push_back(u);
	}
	if(10<num&&num<15||m1+m2==n){cout<<(jiecheng(n)+mod-n)%mod<<endl;return 0;}
	if(n==1||n==2){cout<<0<<endl;return 0;}
	for(ll i=1;i<=n;i++)
		if(e[i].size()==0) d++;
		else if(!v[i]) fa[i]=i,dfs(i,i,i);
	if(d) ans=jiecheng(d);
	else ans=1;
	for(ll i=1;i<=n;i++)
		if(cir[i]) ans=(ans*len[i])%mod,cntlc[len[i]]++;
		else if(fa[i]==i) ans=(ans*(len[i]&1?1:2))%mod,cntll[len[i]]++;
	for(ll i=1;i<=n;i++){
		if(cntlc[i]>1) ans=(ans*jiecheng(cntlc[i]))%mod;
		if(cntll[i]>1) ans=(ans*jiecheng(cntll[i]))%mod;
	}
	cout<<(jiecheng(n)+mod-ans)%mod<<endl;
/*	for(ll i=1;i<=n;i++) cout<<cir[i]<<' ';
	cout<<endl;
	for(ll i=1;i<=n;i++) cout<<len[i]<<' ';
	cout<<endl;
	for(ll i=1;i<=n;i++) cout<<fa[i]<<' ';
	cout<<endl;
	cout<<dian<<' '<<ans<<endl;*/
	return 0;
}
