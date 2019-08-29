#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
bool h[520][520];
inline int FZ(int x,int y,int zx,int zy,int yx,int yy){
	int tmp=yx-zx+1;
	if(tmp==4&&x==zx+1&&y==zy+1)return 0;
	if(tmp==1)return 1;
	int t1=(x>=zx+tmp/2);int t2=(y>=zy+tmp/2);
	int pos=t1*2+t2+1;
	if(pos==1)return FZ(x,y,zx,zy,zx+tmp/2-1,zy+tmp/2-1);
	if(pos==2)return FZ(x,y,zx,zy+tmp/2,zx+tmp/2-1,yy);
	if(pos==3)return FZ(x,y,zx+tmp/2,zy,yx,zy+tmp/2-1);
	if(pos==4)return -FZ(x,y,zx+tmp/2,zy+tmp/2,yx,yy);
}
int ans=0;
inline void bfs(int x,int y){
	ans++;h[x][y]=1;
	rep(i,0,3){
		int tx=x+dir[i][0];int ty=y+dir[i][1];
		if(tx<1||ty<1||h[tx][ty])continue;
		int t=1;
		while(t<max(tx,ty))t*=2;
		int s=FZ(tx,ty,1,1,t,t);
		if(s!=-1)continue;
		bfs(tx,ty);
	}
	return;
}

int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);

	int x,y;read(x);read(y);
	x++;y++;
	if(x==2&&y==2){write(1);return 0;}
	int t=1;
	while(t<max(x,y))t*=2;
	int s=FZ(x,y,1,1,t,t);
	if(s==1){puts("infinity");}
	else{
		if(s==0){write(1);return 0;}
		if(x<=101&&y<=101){bfs(x,y);write(ans);}
		else{write(t/2*5-1);}
	}
	return 0;
}
