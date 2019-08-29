#include<bits/stdc++.h>
#define pii pair<int,int>
#define iiii pair<int,pii >
#define ll long long 
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint(){
	char c=getchar();int x=0,p=1;
	while(c<=32)c=getchar();
	if(c==45)c=getchar(),p=-p;
	while(c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//ruogu
const int N=2e5+10;
bool vis[N];
int cc,n,m1,m2;
int to[N][2];
int fac[N],inv[N];
int line[N],cyc[N],l[2][N];
//
inline int add(int x,int y){x+=y;return (x>=MOD)?x-MOD:x;}
inline int mul(int x,int y){ll ans=1ll*x*y;return ans%MOD;}
inline int sub(int x,int y){x-=y;return (x<0)?x+MOD:x;}
inline int modpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
inline int modinv(int x){

	return modpow(x,MOD-2);
}
void init(){
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=mul(fac[i-1],i);
	inv[N-1]=modinv(fac[N-1]);for(int i=N-2;i>=0;i--)inv[i]=mul(inv[i+1],i+1);
}
void dfs(int x,int col,int cnt){
	if(vis[x]){
		cyc[cnt]++;
		cout<<cnt<<endl;
		return;
	}
	++cnt;
	vis[x]=true;
	if(to[x][col]==-1){
		if(cnt&1)l[cc][cnt]++;
		else line[cnt]++;
		return;
	}
	dfs(to[x][col],col^1,cnt);
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	init();
	int num=getint();
	n=getint();m1=getint();m2=getint();
	memset(to,-1,sizeof(to));
	rep(i,m1){
		int x=getint()-1,y=getint()-1;
		to[x][0]=y;
		to[y][0]=x;
	}
	rep(i,m2){
		int x=getint()-1,y=getint()-1;
		to[x][1]=y;
		to[y][1]=x;
	}
	int res=1;
	rep(i,n)if(!vis[i]&&to[i][0]!=-1&&to[i][1]==-1){
		cc=0;
		dfs(i,0,0);
	}
	rep(i,n)if(!vis[i]&&to[i][1]!=-1&&to[i][0]==-1){
		cc=1;
		dfs(i,1,0);
	}
	for(int i=2;i<=n;i+=2){
		res=mul(res,mul(fac[cyc[i]],modpow(i,cyc[i])));
	}
	for(int i=2;i<=n;i++){
		res=mul(res,mul(fac[line[i]],modpow(2,line[i])));
	}
	for(int i=2;i<=n;i++){
		res=mul(res,fac[l[0][i]]);
		res=mul(res,fac[l[1][i]]);
	}
	res=sub(0,res);
	res=add(res,fac[n]);
	cout<<res<<endl;
	return 0;
}
