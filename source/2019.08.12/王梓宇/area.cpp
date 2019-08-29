#include<bits/stdc++.h>
using namespace std;
bool a[7001][7001];
bool vis[7001][7001];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int zbx,zby,tot;
int Maxx,Maxy;
inline bool judge(int x,int y){
	if(x>=0&&x<=Maxx&&y>=0&&y<=Maxy) return true;
	return false;
}
inline int fuck(int x,int y){
	if(x==0||y==0||(x==2&&y==1)||(x==3&&y==3)||(x==1&&y==2)){
		return 1;
	}return 0;
}
void dfs(int x,int y){
	tot++;vis[x][y]=1;
	for(int i=0;i<4;++i){
		int xx=dx[i]+x,yy=dy[i]+y;
		if(judge(xx,yy)&&a[xx][yy]==a[x][y]&&!vis[xx][yy]){
			dfs(xx,yy);
		}
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>zbx>>zby;
	int modx=zbx%4,mody=zby%4;
	if(modx==0||mody==0||(modx==2&&mody==1)||(modx==3&&mody==3)||(modx==1&&mody==2)){
		printf("infinity");
		return 0;
	}
	Maxx=zbx+1000,Maxy=zby+1000;
	for(int i=0;i<=zbx+1000;++i){
		for(int j=0;j<=zby+1000;++j){
			a[i][j]=fuck(i%4,j%4);
		}
	}
	dfs(zbx,zby);
	cout<<tot;
	return 0;
}


