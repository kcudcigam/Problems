#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int n,m;
ll a[305][305];
ll c(int x,int y){
	if(a[x][y])return a[x][y];
	ll ans=0;
	for(int i=1;i<x;i++){
		c(i,y);
		c(x-i,y);
		ans+=a[i][y]+a[x-i][y];
		if((x-i)==i)ans-=a[i][y];
	}
	for(int i=1;i<y;i++){
		c(x,i);
		c(x,y-i);
		ans+=a[x][i]+a[x][y-i];
		if((y-i)==i)ans-=a[x][i];
	}
	return a[x][y]=ans%mod;
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d%d",&n,&m);
	a[1][2]=1;a[2][1]=1;
	c(n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	printf("%lld",a[n][m]);
	return 0;
}


