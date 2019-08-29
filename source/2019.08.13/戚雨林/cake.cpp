#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL p=1000000007ll;

int n,m;
LL f[305][305],ans;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

LL dfs(int n,int m){
	if (f[n][m]>0ll) return f[n][m];
	for (int i=1;i<n;++i)
		f[n][m]=(f[n][m]+dfs(i,m)*dfs(n-i,m))%p;
	for (int i=1;i<m;++i)
		f[n][m]=(f[n][m]+dfs(n,i)*dfs(n,m-i))%p;
	return f[n][m];
}

int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	memset(f,0,sizeof(f));
	f[1][1]=1ll;
	ans=dfs(n,m);
	cout<<ans<<'\n';
	return 0;
}
