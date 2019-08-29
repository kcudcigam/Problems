#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int a[2010][2010];
int now,x,y,cnt,cnt1;
int st[4][4];
struct sb{
	int x,y;
};
bool inv[2010][2010];
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
inline void bfs(int x,int y){
	queue<sb>q;
	memset(inv,false,sizeof inv);
	cnt=0;
	q.push((sb){x,y});
	cnt++;
	inv[x][y]=true;
	while(!q.empty()){
		sb now1=q.front();
		int nx=now1.x,ny=now1.y;
		q.pop();
		for(register int i=0;i<4;i++){
			int tx=nx+dx[i],ty=ny+dy[i];
			if(tx>now||tx<=0||ty>now||ty<0||inv[tx][ty]||a[tx][ty]!=a[nx][ny]){
				continue;
			}
			cnt++;
			inv[tx][ty]=true;
			q.push((sb){tx,ty});
		}
	}
}
inline bool judge(long long x){
	long long ans=1;
	while(ans<x){
		ans<<=1;
	}
	if(ans==x) return true;
	else return false;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d%d",&x,&y);
	long long now2=x+y;
	if(judge(now2)){
		printf("infinity\n");
		return 0;
	}
	x++;y++;
	if(x<=1000&&y<=1000){
		now=2;
		a[1][1]=1;
		a[1][2]=1;
		a[2][1]=1;
		a[2][2]=-1;
		st[1][1]=1;st[1][2]=1;
		st[2][1]=1;st[2][2]=-1;
		while(now<x||now<y){
			for(register int i=1;i<=now;i++){
				for(register int j=1;j<=now;j++){
					for(register int k=1;k<=2;k++){
						for(register int l=1;l<=2;l++){
							a[(i-1)*2+k][(j-1)*2+l]=a[i][j]*st[k][l];
						}
					}
				}
			}
			now*=2;
		}
		bfs(x,y);
		cnt1=cnt;
		for(register int i=1;i<=now;i++){
			for(register int j=1;j<=now;j++){
				for(register int k=1;k<=2;k++){
					for(register int l=1;l<=2;l++){
						a[(i-1)*2+k][(j-1)*2+l]=a[i][j]*st[k][l];
					}
				}
			}
		}
		now*=2;
		bfs(x,y);
		if(cnt!=cnt1){
			printf("infinity\n");
		}
		else {
			printf("%d\n",cnt);
		}	
	}
	else {
		printf("infinity");
	}
}
