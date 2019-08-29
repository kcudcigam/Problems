#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
int n=1,m=2;
bool MAP[10010][10010];
int dx[4]={-1,0,+1,0};
int dy[4]={0,+1,0,-1};
struct node{
	int x,y;
}a[1000010];
void deal(int dep){
	for(int i=1;i<=dep;++i){
		for(int j=1;j<=dep;++j){
			MAP[i+dep][j]=MAP[i][j+dep]=MAP[i][j];
			MAP[i+dep][j+dep]=1^MAP[i][j];
		}
	}
}
void count(){
	if(MAP[x][y]==1){
		if(MAP[x-1][y]==0&&MAP[x][y+1]&&MAP[x][y-1]&&MAP[x+1][y]){
			cout<<1<<endl;
			return;
		}
		else{
			cout<<"infinity"<<endl;
			return;
		}
	}
	else{
		a[1].x=x,a[1].y=y;
		int ll=1,rr=1;
		while(ll<=rr){
			for(int i=0;i<4;++i){
				int nx=a[ll].x+dx[i],ny=a[ll].y+dy[i];
				if(nx>=1&&nx<=m&&ny>=1&&ny<=m&&MAP[nx][ny]==false){
					MAP[nx][ny]==true;
					rr++;
					a[rr].x=nx,a[rr].y=ny;
				}
			}
		}
		cout<<rr<<endl;
	}
	
	return;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cin>>x>>y;
	
	x++,y++;
	MAP[1][1]=MAP[1][2]=MAP[2][1]=true,MAP[2][2]=false;
	
	while(m<x||m<y){
		deal(m);
		m*=2;
		n++;
	}
	
	count();
	return 0;
}

