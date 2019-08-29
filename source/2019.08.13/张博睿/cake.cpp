#include<bits/stdc++.h>
using namespace std;
long long n,m,duck[400][400];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	duck[1][1]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		for(int k=1;k<=i/2;k++) duck[i][j]=(duck[i][j]+duck[k][j]*duck[i-k][j])%1000000007;
		for(int k=1;k<=j/2;k++) duck[i][j]=(duck[i][j]+duck[i][k]*duck[i][j-k])%1000000007;
	}
	cout<<duck[n][m]<<endl;
	return 0;
}


