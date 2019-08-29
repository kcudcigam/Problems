#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>void fr(T &x){
	x=0;char c=getchar();
	int f=1;
	for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	x=x*f;
}
const int MOD=1e9+7;
ll f[310][310];
int n,m;
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	fr(n),fr(m);
	
	f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int k=1;k<i;k++)f[i][j]=(f[i][j]+f[k][j]*f[i-k][j])%MOD;
			for(int k=1;k<j;k++)f[i][j]=(f[i][j]+f[i][k]*f[i][j-k])%MOD;
		}
	
	cout<<f[n][m]<<endl;
	return 0;
}


