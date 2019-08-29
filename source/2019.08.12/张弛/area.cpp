#include<bits/stdc++.h>
using namespace std;
const int N=1100;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int a[N][N],mx,my,ans=0,t=2;
void dfs(int x,int y,int k){
	a[x][y]=-k; ans++;
	mx=min(x,mx),my=min(y,my);
	for(int i=0;i<4;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>0 && ty>0 && tx<=t && ty<=t && a[tx][ty]==k)
			dfs(tx,ty,k);
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	a[1][1]=a[1][2]=a[2][1]=1; a[2][2]=-1;
	while(t<256){
		for(int x=1;x<=t;x++)
			for(int y=1;y<=t;y++){
				int qx=(x-1)*t,qy=(y-1)*t;
				for(int i=1;i<=t;i++)
					for(int j=1;j<=t;j++)
						a[qx+i][qy+j]=a[x][y]*a[i][j];
			}
		t=t*t;
	}
	for(int x=1;x<=4;x++)
		for(int y=1;y<=4;y++){
			int qx=(x-1)*t,qy=(y-1)*t;
			for(int i=1;i<=t;i++)
				for(int j=1;j<=t;j++)
					a[qx+i][qy+j]=a[x][y]*a[i][j];
		}
	t*=4;
	int x,y;
	cin>>x>>y;
	x++,y++;
	mx=x,my=y;
	if(x>100 || y>100){
		cout<<"infinity\n";
		return 0;
	}
	dfs(x,y,a[x][y]);
	if(mx==1 || my==1) cout<<"infinity\n";
	else cout<<ans<<"\n";
	return 0;
}
