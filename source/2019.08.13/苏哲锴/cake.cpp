#include<bits/stdc++.h>
using namespace std;
const int Mo=1000000007;
int n,m;
int d[501][501];
int main(){
freopen("cake.in","r",stdin);
freopen("cake.out","w",stdout);
cin>>n>>m;
 d[1][1]=1;
 for(int i=2;i<=m;i++){
	for(int k=1;k<i;k++){
		d[1][i]+=d[1][k]*d[1][i-k];
		d[i][1]=d[1][i];
	}
}
for(int i=2;i<=n;i++){
	for(int j=2;j<=m;j++){
		for(int k=1;k<j;k++){
			//d[i][j]%=Mo;
			d[i][j]+=d[i][k]%Mo*d[i][j-k]%Mo;
			
		}
		for(int z=1;z<i;z++){
			//d[i][j]%=Mo;
			d[i][j]+=d[z][j]%Mo*d[i-z][j]%Mo; 
			
		}
	}
}
//cout<<d[2][2]<<endl;
//cout<<d[1][3]<<" "<<d[3][1]<<endl;
//cout<<work(1,3)<<" "<<work(1,4)<<endl;
//work(n,m);
//for(int i=1;i<=n;i++){
//for(int j=1;j<=m;j++){
//		for(int k=1;k<=max(i,j)){
//			d[i][j]+=
//		}
//	}
//}
while(d[n][m]<0 ) d[n][m]+=Mo;
cout<<d[n][m]<<endl;

	return 0;
}


