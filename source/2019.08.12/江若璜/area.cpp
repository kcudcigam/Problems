#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2005;
ll a[N][N],ans,v[N][N],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},cnt=2;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=fl;
}
void wr(ll x){
	 if(x<0) putchar('-'),x=-x;
	 if(x<10) putchar(x+'0');
	 if(x>9) wr(x/10),putchar(x%10+'0');
}
void dfs(ll x,ll y){
	if(v[x][y]||ans==-1) return ;
//	cout<<x<<' '<<y<<endl;
	v[x][y]=1;ans++;
	if(x==0||y==0){ans=-1;return ;}
	for(ll k=0;k<4;k++)
		if(a[x+dx[k]][y+dy[k]]==a[x][y]&&x+dx[k]<cnt&&y+dy[k]<cnt) dfs(x+dx[k],y+dy[k]);
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	ll x,y;
	rd(x);rd(y);
	if(x>=2000||y>=2000){cout<<"infinity"<<endl;return 0;}
	a[0][0]=a[0][1]=a[1][0]=1;a[1][1]=-1;
	while(cnt-1<max(x,y)){
		for(ll i=0;i<cnt;i++)
			for(ll j=cnt;j<cnt+cnt;j++) a[i][j]=a[i][j-cnt];
		for(ll i=cnt;i<cnt+cnt;i++)
			for(ll j=0;j<cnt;j++) a[i][j]=a[i-cnt][j];
		for(ll i=cnt;i<cnt+cnt;i++)
			for(ll j=cnt;j<cnt+cnt;j++) a[i][j]=-a[i-cnt][j-cnt];
		cnt*=2;
	}
//	for(ll i=0;i<cnt;i++,cout<<endl)
//		for(ll j=0;j<cnt;j++) cout<<(a[i][j]==1?1:0)<<' ';
	if(x==0||y==0||a[x][y]==1&&(x==cnt-1||y==cnt-1)){cout<<"infinity"<<endl;return 0;}
	dfs(x,y);
	if(ans==-1) cout<<"infinity"<<endl;
	else wr(ans),puts("");
	return 0;
}
