#include<bits/stdc++.h>
using namespace std;
const int mo=1000000007;
long long f[310][310];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1){
				f[i][j]=1;
				continue;
			}
			for(int k=1;k<j;k++)f[i][j]=(f[i][j]+(f[i][k]*f[i][j-k])%mo)%mo;
			for(int k=1;k<i;k++)f[i][j]=(f[i][j]+(f[k][j]*f[i-k][j])%mo)%mo;
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}
