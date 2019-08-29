#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL p=7ll+(LL)(1e9);
const int N=100+(int)(2e5);

struct Node{
	int x;
	LL y,z;
}a[N];
int n,m,q;
char vis[N];
LL c[N];
int l[N],r[N];
LL ans,nw;
int t;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void dfs(int x,LL w){
	if (x>m){
		LL re=0ll;
		for (int i=1;i<=q;++i) re+=c[i];
		re%=p;
		ans=(ans+re*w)%p;
		return;
	}
	if (vis[a[x].x]==1) dfs(x+1,w);else{
		LL d[q+2];
		for (int i=1;i<=q;++i) d[i]=c[i];
		vis[a[x].x]=1;
		for (int i=1;i<=q;++i)
			if ((l[i]<=a[x].x)&&(a[x].x<=r[i]))
				c[i]=a[x].y;
		dfs(x+1,(w*a[x].z)%p);
		vis[a[x].x]=0;
		for (int i=1;i<=q;++i) c[i]=d[i];
		
		dfs(x+1,(w*(p+1ll-a[x].z))%p);
	}
}

bool cmp(Node a,Node b){
	return (a.y<b.y);
}

bool cpx(Node a,Node b){
	return (a.x==b.x)?(a.z<b.z):(a.x<b.x);
}

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=rd();m=rd();q=rd();
	for (int i=1;i<=m;++i){
		a[i].x=rd();a[i].y=(LL)(rd());a[i].z=(LL)(rd());
	}
	if ((m<=20)&&(1)){
		for (int i=1;i<=q;++i) cin>>l[i]>>r[i];
		memset(vis,0,sizeof(vis));
		for (int i=1;i<=q;++i) c[i]=0ll;
		sort(a+1,a+m+1,cmp);
		ans=0ll;
		dfs(1,1ll);
		cout<<ans<<'\n';
	}else
	if (n==q){
		ans=0ll;
		sort(a+1,a+m+1,cpx);
		t=1;
		for (int i=1;i<=n;++i){
			nw=1ll;
			while ((t<=m)&&(a[t].x==i)){
				ans=(ans+((nw*a[t].z)%p)*a[t].y)%p;
				nw=(nw*(p+1ll-a[t].z))%p;
				++t;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
