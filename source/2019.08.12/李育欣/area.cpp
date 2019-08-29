#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int x,y,b[200][200],u[200][200],ans=1;
queue< pair<int,int> > q;
void bfs(int x,int y){
	q.push(make_pair(x,y));
	u[x][y]=1;
	while(q.size()){
		int xx=q.front().first,yy=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int X=xx+dx[i],Y=xx+dy[i];
			if(b[X][Y]!=b[xx][yy])continue;
			if(u[X][Y]==0){
				if(X==0||Y==0||X==128||Y==128){
					printf("infinity");
					return;
				}
				u[X][Y]=1;
				q.push(make_pair(X,Y));
			}
		}
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&x,&y);
	if(x==1||y==1){
		printf("infinity");
	}
	int x=2,y=6;
	b[0][0]=1;b[0][1]=1;b[1][0]=1;b[1][1]=-1;
	while(y--){	
		for(int i=x;i<x*2;i++){
			for(int j=0;j<x;j++){
				b[i][j]=b[i-x][j];
			}
		}
		for(int i=0;i<x;i++){
			for(int j=x;j<x*2;j++){
				b[i][j]=b[i][j-x];
			}
		}
		for(int i=x;i<x*2;i++){
			for(int j=x;j<x*2;j++){
				b[i][j]=-b[i-x][j-x];
			}
		}
		x*=2;
	}
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	bfs(x,y);
	return 0;
}


