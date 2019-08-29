#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1;char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int vis[510][510],n,m,cnt,b[510];
ll f[510][510],g[10];
pair<int,int> p[510];
ll G(int x){
	ll ans=0,now=x;
	for(int i=1;i<=5;i++,now*=x)
		ans+=now*g[i];
	return ans;
}
ll solve(int l,int r){
	if(l>r) return 0;
	if(vis[l][r]) return f[l][r];
	vis[l][r]=1;
	vector<int> v;v.resize(r-l+1);
	for(int i=1;i<=n;i++)
		if(p[i].first>=l&&p[i].second<=r){
			v[p[i].first-l]++;
			if(p[i].second<r) v[p[i].second-l+1]--;
		}
	ll ans=0,now=0;
	for(int i=0;i<r-l+1;i++){
		now+=v[i];
		if(now)ans=max(ans,solve(l,l+i-1)+solve(l+i+1,r)+G(now));
	}
	return f[l][r]=ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=5;i++) read(g[i]);
	for(int i=1;i<=n;i++){
		read(p[i].first);read(p[i].second);
		b[++cnt]=p[i].first;
		b[++cnt]=p[i].second;
	}
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	for(int i=1;i<=n;i++)
		p[i].first=lower_bound(b+1,b+cnt+1,p[i].first)-b,
		p[i].second=lower_bound(b+1,b+cnt+1,p[i].second)-b;
	cout<<solve(1,cnt)<<'\n';
	return 0;
}
