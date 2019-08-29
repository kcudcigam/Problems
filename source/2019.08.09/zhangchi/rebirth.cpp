#include<bits/stdc++.h>
#define int long long
#define pr pair<long long,long long>
using namespace std;
const int N=110000,inf=1e18;
vector<pr> a[N];
vector<int> b;
int d[N],h[N],ans[N],n,m;
priority_queue<pr,vector<pr>,greater<pr> > q;
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
void dij(){
	for(int i=0;i<=n;i++)
		d[i]=inf,h[i]=0;
	d[1]=0;
	q.push(pr(0,1));
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(h[u]) continue;
		h[u]=1;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].first,we=a[u][i].second;
			if(d[u]+we<d[v]){
				d[v]=d[u]+we;
				q.push(pr(d[v],v));
			}
		}
	}
}
signed main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	int Num=read();
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		a[x].push_back(pr(y,z));
		a[y].push_back(pr(x,z));
	}
	if(Num>7){
		dij();
		ans[1]=0;
		for(int i=2;i<=n;i++)
			ans[i]=inf;
		for(int u=n;u>1;u--){
			b.clear();
			int mx=0;
			for(int i=0;i<a[u].size();i++){
				int v=a[u][i].first,we=a[u][i].second;
				if(v>=u) continue;
				if(v==u-1) b.push_back(we);
				else ans[u]=min(ans[u],d[v]+we);
			}
			sort(b.begin(),b.end());
			if(b.size()>1) ans[u]=min(ans[u],d[u-1]+b[1]);
			ans[u-1]=ans[u]+b[0];
		}
		ans[1]=0;
	}
	else{
		for(int u=1;u<=n;u++)
			for(int i=0;i<a[u].size();i++){
				int v=a[u][i].first,we=a[u][i].second;
				if(u>=v) continue;
				a[u][i].second=inf;
				dij();
				ans[u]=max(ans[u],d[u]);
				ans[v]=max(ans[v],d[v]);
				a[u][i].second=we;
			}
	}
	for(int i=1;i<=n;i++)
		if(ans[i]>=1e15) cout<<"-1 ";
		else cout<<ans[i]<<" ";
	return 0;
}
