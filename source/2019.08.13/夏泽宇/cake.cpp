#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
typedef long long ll;
ll f[310][310];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
ll dfs(int x,int y){
	if(f[x][y])return f[x][y];
	for(int i=1;i<=x&&x-i>0;i++)
		f[x][y]=(f[x][y]+dfs(i,y)*dfs(x-i,y))%mod;
	for(int i=1;i<=y&&y-i>0;i++)
		f[x][y]=(f[x][y]+dfs(x,i)*dfs(x,y-i))%mod;
	return f[x][y];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n=read(),m=read();
	if(n>m)swap(n,m);//m是较大值 
	ll jc=1;
	f[1][1]=1;
	dfs(n,m);
	printf("%lld\n",f[n][m]);
	return 0;
}


