#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005,INF=999999;
ll n,m,Q,f[N][N],d[N][N],dis[N][N],maxn,ans;
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
bool check(ll x,ll st,ll en){
	memset(dis,INF,sizeof(dis));
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(d[i][j]<=x) dis[i][j]=d[i][j];
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	return dis[st][en]<INF;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	rd(n);rd(m);rd(Q);
	memset(f,INF,sizeof(f));
	memset(d,INF,sizeof(d));
	for(ll i=0,x,y,z;i<m;i++){
		rd(x);rd(y);rd(z);
		d[x][y]=d[y][x]=f[x][y]=f[y][x]=z;maxn=max(z,maxn);
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++) f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
	for(ll i=0,x,y;i<Q;i++){
		rd(x);rd(y);
		if(f[x][y]>=INF){putchar('-');putchar('1');puts("");continue;}
		ll l=0,r=maxn,mid=0;ans=maxn;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid,x,y)) ans=mid,r=mid-1;
			else l=mid+1;
		}
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		wr(ans);puts("");
	}
	return 0;
}

