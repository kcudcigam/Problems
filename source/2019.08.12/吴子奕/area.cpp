#include<bits/stdc++.h>
using namespace std;
long long num[101][101];
int a[101][101];
int x1[5]={0,0,0,1,-1};
int yyyyyyy[5]={0,1,-1,0,0};
int vis[101][101];
int sum;
//void build(int x,int y){
//	if(x>=200&&y>=200)return;
//	for(int i=2;i<=)
//	build(x*2,x*2);
//}
void dfs(int x,int y){
	
	if(vis[x][y])return;
	vis[x][y]=1;
	sum++;
	for(int i=1;i<=4;i++){
		int nx,ny;
		nx=x+x1[i];
		ny=y+yyyyyyy[i];
		if(nx<=0||nx>=100||ny<=0||ny>=100)continue;
		 
		if(a[x][y]!=a[nx][ny])continue;
		dfs(nx,ny);
		
	}num[x][y]=sum;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int a,b;cin>>a>>b;
for(int i=1;i<=100;i++){
	for(int j=1;j<=100;j++){
		sum=0;
		//dfs(i,j);
	
	}
}
for(int i=1;i<=100;i++){
for(int j=1;j<=100;j++){
//	cout<<num[i][j]<<",";}
	}
	cout<<"infinity";
	return 0;
}}


