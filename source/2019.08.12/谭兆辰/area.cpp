#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int a[5050][5050];
int now=2,cnt1=-1,cnt2=-1;
int b[5050][5050];
inline void calc(){
	int ki=1,kj=1;
	cnt2=-1;
	for(int i=1;i<=now;i++){
		cnt2++,cnt1=-1;
		for(int j=1;j<=now;j++){
			ki=cnt2*now+1,cnt1++;
			for(int k=1;k<=now;k++){
				kj=cnt1*now+1;
				for(int p=1;p<=now;p++){
//					cout<<ki<<" "<<kj<<" "<<a[i][j]<<" "<<a[k][p]<<"\n"; 
					b[ki][kj]=a[i][j]*a[k][p],kj++;
				}
				ki++;
			}
		}
	}
	now=now*now;
	for(int i=1;i<=now;i++){
		for(int j=1;j<=now;j++){
			a[i][j]=b[i][j];
//			cout<<b[i][j];
		}
//		cout<<"\n";
	}
}
struct node{
	int x,y;
}q[100100];
bool vis[1001][1001];
int ans=1;
int ls[4]={-1,1,0,0},rs[4]={0,0,-1,1};
inline void bfs(){
	q[1].x=n,q[1].y=m;
	vis[n][m]=1;
	int k=a[n][m];
	int ft=0,sd=1;
	while(ft<sd){
		node p=q[++ft];
		for(int i=0;i<4;i++){
			if(!vis[ls[i]+p.x][rs[i]+p.y]&&a[ls[i]+p.x][rs[i]+p.y]==k&&ls[i]+p.x<=now&&ls[i]+p.x>0&&rs[i]+p.y<=now&&rs[i]+p.y>0){
				q[++sd].x=ls[i]+p.x,q[sd].y=rs[i]+p.y,ans++,vis[ls[i]+p.x][rs[i]+p.y]=1;
			}
		}
	}
	return ;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&n,&m);
	n++,m++;
	a[1][1]=a[2][1]=a[1][2]=1,a[2][2]=-1;
	calc(),calc(),calc();
	bfs();
//	for(int i=1;i<=4;i++){
//		for(int j=1;j<=6;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	if(ans>10000) cout<<"infinity";
	else cout<<ans;
	return 0;
}
