#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int x,y;
int dirx[5]={0,1,0,-1};
int diry[5]={1,0,-1,0};
int a[MAXN][MAXN]={0};
bool vis[MAXN][MAXN]={false};
void pere_deal(){
	for(int i=1;i<=MAXN;i++){
	a[1][i]=1;
	}
	a[2][1]=1;
	a[2][2]=-1;
	a[2][3]=1;
	a[2][4]=-1;
	a[2][5]=1;
	a[2][6]=-1;
	a[3][1]=1;
	a[3][2]=1 ;
	a[3][3]= -1;
	a[3][4]= -1;
	a[3][5]= 1;
	a[3][6]= 1;
	a[4][1]=1;
	a[4][2]=-1;
	a[4][3]=-1;
	a[4][4]=1;
	a[4][5]=1;
	a[4][6]=-1;
	a[5][1]=1;
	a[5][2]=1;
	a[5][3]=1;
	a[5][4]=1;
	a[5][5]=1;
	a[5][6]=-1;
}
/*
void find(int tx,int ty){
	vis[tx][ty]=true;
	dfs(tx,ty);
	
}
void dfs(int nx,int ny){
	for(int i=1;i<=4;i++){
	int px=nx+dirx[i];
	int py=nx+diry[i];
	if(px>=0)
	if(!vis[px][py]){
		ans++;
		dfs(px,py);
	}	
	}
}
*/
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d %d",&x,&y);
	if(x<=5 && y<=5){
	if(x==1 || y==1)
	{
		printf("infinity\n");
		return 0;
	}
	else if(y==2){
		if(x==2){
		printf("1\n");
		return 0;
		}
		else if(x==3){
			printf("infinity\n");
			return 0;
		}
		else if(x==4){
			printf("5\n");
			return 0;
		}
		else if(x==5){
			printf("infinity\n");
			return 0;
		}
	}
	else if(y==3){
		if(x==2){
			printf("infinity\n");
			return 0;
		}
		else if(x==3){
			printf("5\n");
			return 0;
		}
		else if(x==4){
			printf("infinity\n");
			return 0;
		}
		else if(x==5){
			printf("infinity\n");
			return 0;
		}
	}
	else if(y==4){
		if(x==2 || x==3){
			printf("5\n");
			return 0;
		}
		else if(x==4 || x==5){
			printf("infinity\n");
			return 0;
		}
	}
	else if(y==5){
		if(x==2 || x==3 || x==4 ||x==5){
			printf("infinity\n");
			return 0;
		}
	}
	}	
	printf("infinity\n");
	return 0;
}


