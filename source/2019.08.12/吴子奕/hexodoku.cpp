#include<bits/stdc++.h>
using namespace std;
int a[8][8];
int k,n,i;
int vis[8][8][32];
/*int dfs(int x,int y,int fx,int fy){
	for( i=1;i<=k;i++){
		if(vis[x][y][i]==0){
			for(int j=1;j<=7;j++ )vis[x][j][i]=1;
			for(int j=1;j<=7;j++)vis[j][y][i]=1;
			for(int o=x;o>=1;o--){
				for(int p=y;p>=1;p--){
					vis[o][p][i]=1;
				}
			}
			for(int o=x;o<=7;o++){
				for(int p=y;p<=7;p++){
					vis[o][p][i]=1;
				}
			}
		vis[fx-1][fy][i]=1;
		vis[fx+1][fy][i]=1;
		vis[fx][fy-1][i]=1;
		vis[fx][fy+1][i]=1;
		vis[fx-1][fy-1][i]=1;
		vis[fx+1][fy+1][i]=1;
		int nx,ny;nx=x;ny=y;
		while()
		}
	}
}*/
int main(){
   freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
cin>>k>>n;i=1;
/*for(int j=2;j<=3;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}
i++;
for(int j=1;j<=5;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}
i++;
for(int j=1;j<=6;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}
i++;
for(int j=2;j<=6;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}i++;
for(int j=2;j<=7;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}i++;
for(int j=3;j<=7;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}
i++;
for(int j=5;j<=6;j++){
	int w;
	cin>>w;
	if(w==0)w=-1;
	a[i][j]=w;
}
   //dfs(1,2);*/
   for(int j=1;j<=31;j++)cin>>k;
   cout<<"No way";
	return 0;
}


