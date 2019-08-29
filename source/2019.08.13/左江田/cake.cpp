#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long f[333][333];
int n,m;
long long doit(int nx,int mx){
	if(nx==1&&mx==1){
		f[nx][mx]=1;
		return 1;
	}
	for(int i=1;i<=nx-1;++i){
		if(f[i][mx]==0){
			doit(i,mx);
		}
		if(f[nx-i][mx]==0){
			doit(nx-i,mx);
		}
		f[nx][mx]+=(f[i][mx]*f[nx-i][mx]);
		f[nx][mx]%=1000000007;
	}
	for(int i=1;i<=mx-1;++i){
		if(f[nx][i]==0){
			doit(nx,i);
		}
		if(f[nx][mx-i]==0){
			doit(nx,mx-i);
		}
		f[nx][mx]+=(f[nx][i]*f[nx][mx-i]);
		f[nx][mx]%=1000000007;
	}
	return f[nx][mx];
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	scanf("%d %d",&n,&m);
	doit(n,m);
	printf("%lld",f[n][m]);
} 
