#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL p=7ll+(LL)(1e9);

int a[20][20],b[20][20],c[20],vis[20],n,m,k,te,u,v,ans,d[20],e[20],f[20],g[20];
LL x,y;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int chk(){
	int x,y;
	for (int i=1;i<=m;++i){
		x=d[i];y=e[i];
		if (a[c[x]][c[y]]!=1) return 1;
	}
	for (int i=1;i<=k;++i){
		x=f[i];y=g[i];
		if (b[c[x]][c[y]]!=1) return 1;
	}
	return 0;
}

void dfs(int x){
	if (x>n){
		ans+=chk();
		return;
	}
	for (int i=1;i<=n;++i)
		if (vis[i]==0){
			vis[i]=1;c[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}

int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>te;
	if ((te<=6)){
		cin>>n>>m>>k;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=1;i<=m;++i){
			cin>>u>>v;
			d[i]=u;e[i]=v;
			a[u][v]=a[v][u]=1;
		}
		for (int i=1;i<=k;++i){
			cin>>u>>v;
			f[i]=u;g[i]=v;
			b[u][v]=b[v][u]=1;
		}
		memset(vis,0,sizeof(vis));
		ans=0;
		dfs(1);
		cout<<ans<<'\n';
	}else{
		cin>>n>>m>>k;
		x=1ll;
		for (int i=2;i<=n;++i) x=(x*(LL)(i))%p;
		y=1ll;
		for (int i=2;i<=m;++i) y=(y*(LL)(i))%p;
		for (int i=2;i<=k;++i) y=(y*(LL)(i))%p;
		for (int i=2;i<=(n-m-m-k-k);++i) y=(y*(LL)(i))%p;
		for (int i=1;i<=(m+k);++i){
			y+=y;
			y=(y<p)?y:(y-p);
		}
		x=(x>=y)?(x-y):(x-y+p);
		cout<<x<<'\n';
	}
	return 0;
}
