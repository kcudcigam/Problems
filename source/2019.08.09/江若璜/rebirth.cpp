#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005,INF=4e9+9;
ll num,n,m,f[N][N],ans[N],can[N];
struct edge{ll x,y,len;}e[N*3];
template<typename T> void read(T &x){
	ll f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void init(ll a){
	memset(f,INF,sizeof(f));
	for(ll i=1;i<a;i++)
		f[e[i].x][e[i].y]=f[e[i].y][e[i].x]=min(e[i].len,f[e[i].y][e[i].x]);
	for(ll i=a+1;i<=m;i++)
		f[e[i].x][e[i].y]=f[e[i].y][e[i].x]=min(e[i].len,f[e[i].y][e[i].x]);
	for(ll i=0;i<=n;i++) f[i][i]=0;
}
void floyd(){
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(num);read(n);read(m);
	for(ll i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].len;
	for(ll i=1;i<=m;i++){
		init(i);
		floyd();
		for(ll i=1;i<=n;i++)
			if(can[i]==1) continue;
			else if(f[i][1]==INF) ans[i]=-1,can[i]=1;
			else ans[i]=max(ans[i],f[i][1]);
	}
	for(ll i=1;i<=n;i++) cout<<(ans[i]>=INF?-1:ans[i])<<' ';
	cout<<endl;
	return 0;
}
