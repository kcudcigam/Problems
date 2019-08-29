#include<bits/stdc++.h>
using namespace std;
int a[2200][2200];
int dx[5]={0,1,0,-1,0},dy[5]={0,0,1,0,-1},cnt=0;
struct POS{
	int x,y;
};
bool vis[2200][2200],f=0;
void bfs(int x,int y){
	queue<POS> q;
	POS tmp,u;
	tmp.x=x;tmp.y=y;
	q.push(tmp);
	int i,col;
	col=a[x][y];
	while(!q.empty()){
		u=q.front();q.pop();
		for(i=1;i<=4;i++){
			x=u.x+dx[i];y=u.y+dy[i];
			if(vis[x][y]==1||x>2100||y>2100||col!=a[x][y]) continue;
			if(x==1||y==1){
				f=1;return;
			}
			cnt++;
			tmp.x=x;tmp.y=y;
			vis[x][y]=1;
			q.push(tmp);
		}
	}
	return;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int len,i,j,k,x,y;
	a[1][1]=1;a[2][1]=1;
	a[1][2]=1;a[2][2]=-1;
	for(i=1;i<=10;i++){
		len=1<<i;
		for(j=len+1;j<=len*2;j++)
		for(k=1;k<=len;k++) a[j][k]=a[j-len][k];
		for(j=1;j<=len;j++)
		for(k=len+1;k<=len*2;k++) a[j][k]=a[j][k-len];
		for(j=len+1;j<=len*2;j++)
		for(k=len+1;k<=len*2;k++) a[j][k]=-a[j-len][k-len];
	}
	scanf("%d%d",&x,&y);
	x++;y++;
	bfs(x,y);
	if(f) printf("infinity\n");
	else printf("%d\n",cnt);
	return 0;
}

