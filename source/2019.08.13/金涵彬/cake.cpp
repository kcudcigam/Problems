#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500][500];
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>m;
	if(n>m)swap(n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1){
				a[i][j]=1;
			}else{
				for(int k=1;k<i;k++){
					a[i][j]+=(a[i-k][j]*a[k][j])%1000000007;
					a[i][j]%=1000000007;
				}
				for(int k=1;k<j;k++){
					a[i][j]+=(a[i][j-k]*a[i][k])%1000000007;
					a[i][j]%=1000000007;
				}
			}
		}
	}
	cout<<a[n][m]<<endl;
	return 0;
}

