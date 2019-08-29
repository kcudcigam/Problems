#include<bits/stdc++.h>
using namespace std;
int f[110][1010];
bool b[110][1010];
int w[110];
int main(){
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=2;i<=n+1;i++)
	cin>>w[i];
	f[0][0]=0;
	f[1][0]=0;
	for (int i=2;i<=n+1;i++){
		for (int j=0;j<=m;j++){
			//if (b[i][j]==false)f[i][j]=f[i-1][j];
			if (j>=w[i])f[i][j]=max(f[i][j],max(f[i-1][j],f[i-2][j-w[i]]+1));
			else f[i][j]=max(f[i][j],f[i-1][j]);
		}
	}
	cout<<f[n][m]<<endl;
	return 0;
}

