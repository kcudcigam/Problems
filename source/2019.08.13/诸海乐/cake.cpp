#include<bits/stdc++.h>
using namespace std;
long long a[310][310];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
 	a[1][1]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=1;k<i;k++){
				a[i][j]=(a[i][j]+a[k][j]*a[i-k][j]%1000000007)%1000000007;
			}
			for (int k=1;k<j;k++){
				a[i][j]=(a[i][j]+a[i][k]*a[i][j-k]%1000000007)%1000000007;
			}
		}
			
	}
	/*
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<a[n][m]<<endl;
	return 0;
}


