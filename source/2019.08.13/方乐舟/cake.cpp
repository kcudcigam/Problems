#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long f[500][500];
void cut(long long x,long long y){
	f[1][1]=1;
	for (int i=1;i<=x;i++){
		for (int j=1;j<=y;j++){
		for (int k=1;k<i;k++){
			f[i][j]+=f[k][j]*f[i-k][j];
			f[i][j]=f[i][j]%1000000007;
		}
		for (int p=1;p<j;p++){
			f[i][j]+=f[i][p]*f[i][j-p];
			f[i][j]=f[i][j]%1000000007;
		}
	}
	}
	
}
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	cut(n,m);
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			cout<<f[i][j]<<endl;
//		}
//	}
	cout<<f[n][m]<<endl;
	return 0;
}


