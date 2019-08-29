#include<bits/stdc++.h>
#define Mod 10000007
#define k1 19491001
#define k2 998244353
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
const int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
const int N=256;
int a[N+1][N+1];
bool vis[N+1][N+1];
int ans;
bool inf;
int maxn;
bool v[Mod];
void dfs(int x,int y,int c){
	if (x==1||y==1){
		inf=true;
		return;
	}
	ans++;
	vis[x][y]=true;
	for (int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if (tx>=1&&ty>=1&&a[tx][ty]==c&&!vis[tx][ty]) dfs(tx,ty,c);
	}
	return;
}
bool check(int x,int y,int p){
	if (p==1) return true;
	int mid=(p>>1);
	if (x>=mid&&y>=mid) return !check(x-mid,y-mid,p>>1);
	else{
		if (x>=mid) x-=mid;
		if (y>=mid) y-=mid;
		return check(x,y,p>>1);
	}
}
int r(int x,int y){
	ll tmp1=x,tmp2=y;
	ll res=((tmp1*k1)+(tmp2*k2))%Mod;
	int t=res;
	return t;
}
void dfs2(int x,int y,bool c){
	if (!x||!y){
		inf=true;
		return;
	}
	ans++;
	v[r(x,y)]=true;
	for (int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if (tx>=0&&ty>=0&&!v[r(tx,ty)]&&check(tx,ty,maxn)==c) dfs2(tx,ty,c);
	}
	return;
}
int x,y;
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	read(x);read(y);
	if (x<=128&&y<=128){
		a[1][1]=a[1][2]=a[2][1]=1;
		for (int i=1;i<=7;i++){
			for (int j=1;j<=(1<<i);j++)
				for (int k=(1<<i)+1;k<=(1<<(i+1));k++)
					a[j][k]=a[j][k-(1<<i)];
			for (int j=(1<<i)+1;j<=(1<<(i+1));j++)
				for (int k=1;k<=(1<<i);k++)
					a[j][k]=a[j-(1<<i)][k];
			for (int j=(1<<i)+1;j<=(1<<(i+1));j++)
				for (int k=(1<<i)+1;k<=(1<<(i+1));k++)
					a[j][k]=a[j-(1<<i)][k-(1<<i)]^1;
		}
		++x;++y;
		memset(vis,false,sizeof(vis));
		inf=false;
		dfs(x,y,a[x][y]);
		if (inf) puts("infinity");else printf("%d\n",ans);
		return 0;
	}
	maxn=1;
	inf=false;
	while (maxn<max(x,y)) maxn<<=1;
	maxn<<=2;
	dfs2(x,y,check(x,y,maxn));
	if (inf) puts("infinity");else printf("%d\n",ans);
	return 0;
}

