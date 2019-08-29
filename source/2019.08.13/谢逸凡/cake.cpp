#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define N 305
typedef long long ll;
using namespace std;
ll n,m,ans,cng=1;
ll p=1000000007;
ll f[N][N];
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
int dfs(int x,int y){
	if(x==y) {f[x][y]++;return f[x][y];}
 	if(f[x][y]) return f[x][y];
	for(int i=1;i<=x-1&&x-i>=0;i++)
	   f[x][y]=(f[x][y]+(dfs(i,y)*dfs(x-i,y))%p)%p;
	for(int i=1;i<=y-1&&y-i>=0;i++)
	   f[x][y]=(f[x][y]+(dfs(x,i)*dfs(x,y-i))%p)%p;
	return f[x][y];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	n=ip(),m=ip();
	if(n==1&&m==1){puts("1");return 0;}
	f[1][1]=1;
	rep(i,2,n){
		cng=cng*(i-1)%p;
		f[i][1]=f[1][i]=cng;
	}
	if(n==1||m==1){
		printf("%lld",f[n][m]);
		return 0;
	}
	dfs(n,m);
	printf("%lld",f[n][m]);
	return 0;
}


