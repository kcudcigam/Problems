#include<bits/stdc++.h>
using namespace std;

int n,m,sum;
int a[200][200],h[200][200];

void work(int n){
	for (int i=1;i<=n*2;i++)
		for (int j=1;j<=n*2;j++)
		if (i<=n && j<=n) continue;
					 else if (i>n && j>n) a[i][j]=-a[i-n][j-n];
					 				else if (i>n) a[i][j]=a[i-n][j];
					 						 else a[i][j]=a[i][j-n];
}
void walk(int x,int y){
	h[x][y]=1;sum++;
	int tx,ty;
	tx=x+1;ty=y;
	if (h[tx][ty]==0 && a[tx][ty]==a[x][y] && tx>0 && tx<=128 && ty>0 && ty<=128) walk(tx,ty);
	tx=x-1;ty=y;
	if (h[tx][ty]==0 && a[tx][ty]==a[x][y] && tx>0 && tx<=128 && ty>0 && ty<=128) walk(tx,ty);
	tx=x;ty=y+1;
	if (h[tx][ty]==0 && a[tx][ty]==a[x][y] && tx>0 && tx<=128 && ty>0 && ty<=128) walk(tx,ty);
	tx=x;ty=y-1;
	if (h[tx][ty]==0 && a[tx][ty]==a[x][y] && tx>0 && tx<=128 && ty>0 && ty<=128) walk(tx,ty);
}

int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>n>>m;n++;m++;
	if (n>100 || m>100) {cout<<"infinity"<<endl;return 0;}
	a[1][1]=1;a[2][1]=1;a[1][2]=1;a[2][2]=-1;
	work(2);
	work(4);
	work(8);
	work(16);
	work(32);
	work(64);
	walk(n,m);
	if (sum==3599) cout<<"infinity"<<endl;
			  else cout<<sum<<endl;
	/*for (int i=1;i<=16;i++){
		for (int j=1;j<16;j++) if (a[i][j]==1) cout<<' '<<a[i][j]<<' ';
										  else cout<<a[i][j]<<' ';
		if (a[i][16]==1) cout<<' '<<a[i][16]<<endl;
		       	    else cout<<a[i][16]<<endl;
	}*/
	
	return 0;
}

