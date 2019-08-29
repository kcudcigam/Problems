#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=410,p=1e9+7;
int f[N][N];
void add(int &x,int y){
	x=(x+y)%p;
}
signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int n,m;
	cin>>n>>m;
	f[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(i+j>2){
				for(int k=1;k<i;k++)
					add(f[i][j],f[k][j]*f[i-k][j]);
				for(int k=1;k<j;k++)
					add(f[i][j],f[i][k]*f[i][j-k]);
			}
	cout<<f[n][m]<<"\n";
	return 0;
}
