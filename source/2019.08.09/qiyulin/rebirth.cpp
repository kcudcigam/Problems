#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> pa;

const int M=100+(int)(1e6);
const int N=100+(int)(2e5);
const LL INF=(LL)(1e18);

int sta[N],v[M],nxt[M],tot,d[M];
LL w[M];
LL f[N];
int vis[N];
priority_queue <pa,vector<pa>,greater<pa> > q;
int n,m,x,y,z,te;
int a[N],p,fr[N];
LL g[N],nw;
LL ans;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void Dj(){
	for (int i=2;i<=n;++i) f[i]=INF;
	f[1]=0ll;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(f[1],1));
	while (!q.empty()){
		x=q.top().second;
		q.pop();
		if (vis[x]==1) continue;
		vis[x]=1;
		for (int i=sta[x];i>0;i=nxt[i])
			if (d[i]==0){
				y=v[i];
				if (f[y]>(f[x]+w[i])){
					f[y]=f[x]+w[i];
					q.push(make_pair(f[y],y));
					fr[y]=i;
				}
			}
	}	
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	te=rd();
	n=rd();m=rd();
	memset(sta,0,sizeof(sta));
	memset(d,0,sizeof(d));
	tot=1;
	for (int i=1;i<=m;++i){
		x=rd();y=rd();z=rd();
		if (x!=y){
			v[++tot]=y;w[tot]=(LL)(z);nxt[tot]=sta[x];sta[x]=tot;
			v[++tot]=x;w[tot]=(LL)(z);nxt[tot]=sta[y];sta[y]=tot;
		}
	}
	if (te<=7){
		cout<<0;
		for (int i=2;i<=n;++i){
			ans=-1ll;
			for (int j=sta[i];j>0;j=nxt[j]){
				d[j]=d[j^1]=1;
				Dj();
				ans=(ans>f[i])?ans:f[i];
				d[j]=d[j^1]=0;
			}
			ans=(ans==INF)?-1ll:ans;
			cout<<' '<<ans;
		}
		cout<<"\n";
	}else{
	
	for (int i=2;i<=n;++i) f[i]=g[i]=INF;
	f[1]=0ll;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(f[1],1));
	z=0;
	while (!q.empty()){
		x=q.top().second;
		q.pop();
		if (vis[x]==1) continue;
		vis[x]=1;a[++z]=x;
		for (int i=sta[x];i>0;i=nxt[i]){
			y=v[i];
			if (f[y]>(f[x]+w[i])){
				f[y]=f[x]+w[i];
				q.push(make_pair(f[y],y));
				fr[y]=i;
			}
		}
	}
	
	memset(vis,0,sizeof(vis));
	p=1;
	while ((p<=n)||(!q.empty())){
		if ((!q.empty())&&(vis[q.top().second]==1)){
			q.pop();continue;
		}
		if ((p>n)||((!q.empty())&&(q.top().first<f[a[p]]))){
			x=q.top().second;
			vis[x]=1;
			nw=g[x];
			for (int i=sta[x];i>0;i=nxt[i]){
				y=v[i];
				if ((fr[y]!=i)&&(g[y]>nw+w[i])){
					g[y]=nw+w[i];
					q.push(make_pair(g[y],y));
				}
			}
		}else{
			x=a[p++];
			nw=f[x];
			for (int i=sta[x];i>0;i=nxt[i]){
				y=v[i];
				if ((fr[y]!=i)&&(g[y]>nw+w[i])&&(fr[x]!=(i^1))){
					g[y]=nw+w[i];
					q.push(make_pair(g[y],y));
				}
			}
		}
	}
	
	cout<<0;
	for (int i=2;i<=n;++i){
		if (g[i]==INF) cout<<" -1";else cout<<' '<<g[i];
	}
	cout<<'\n';
	
	}
	return 0;
}
