#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
int n,m,q;ll ans;
map<int,ll> pr[1<<18],mp;
struct st{int v,p;};basic_string<st> v[1<<18];
int main(){
	freopen("max.in","r",stdin),freopen("max.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int x,y,p;scanf("%d%d%d",&x,&y,&p);v[x]+={y,p};
	}
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end(),[](st a,st b){return a.v<b.v;});
		ll p=1;
		for(int j=0,k;j<(int)v[i].size();j=k){
			for(k=j;k<(int)v[i].size() && v[i][k].v==v[i][j].v;k++);
			ll t=1;
			for(int tt=j;tt<k;tt++)(t*=1-v[i][tt].p)%=mod;
			pr[i][v[i][j].v]=p*(1-t)%mod;
			for(int t=j;t<k;t++)(p*=1-v[i][t].p)%=mod;
		}
		pr[i][0]=p;ll ls=0;
		for(auto&pa:pr[i])(ls+=pa.second)%=mod,(pa.second=ls-pa.second)%=mod;
	}
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++)
			for(auto&pa:pr[i])mp[pa.first]=1;
		for(int i=l;i<=r;i++)
			for(auto&pa:mp){
				auto it=pr[i].lower_bound(pa.first);
				if(it!=pr[i].end())(pa.second*=it->second)%=mod;
			}
		int ls=0;
		for(auto&pa:mp){
			(ans+=(pa.first-ls)*(1-pa.second))%=mod;
			ls=pa.first;
		}
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
