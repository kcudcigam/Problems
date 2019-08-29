#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';return ret*w;
}
const int MAXN =1048+3;
int n,r=2,c=2,cnt,_cnt;
bool vis[MAXN][MAXN],A[MAXN][MAXN],B[MAXN][MAXN];
const int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
void calc(int x,int y){
	queue<pair<int,int> > q; bool ok=A[x][y]==1;
	q.push(make_pair(x,y)),vis[x][y]=cnt=1;
	while(!q.empty()){
		int _x=q.front().first,_y=q.front().second; q.pop();
		up(0,3,i){
			int nx=_x+dir[i][0],ny=_y+dir[i][1];
			if(A[nx][ny]!=ok||vis[nx][ny]) continue;
			if(nx==1||nx==r||ny==1||ny==c){
				cnt=INT_MAX; return;
			}
			vis[nx][ny]=true,cnt++;
			q.push(make_pair(nx,ny));
		}
	}
}
int __x,__y;
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	
	__x=qread()+1,__y=qread()+1;
	if(max(__x,__y)>=1024) puts("infinity"),exit(0);
	while((1<<n+1)<=max(__x,__y)) n++;
	A[1][1]=A[1][2]=A[2][1]=1,A[2][2]=0;
	up(1,n,p){
		up(1,r,i) up(1,c,j){
			B[i*2-1][j*2-1]=A[i][j];
			B[i*2  ][j*2-1]=A[i][j];
			B[i*2-1][j*2  ]=A[i][j];
			B[i*2  ][j*2  ]=!A[i][j];
		}
		memcpy(A,B,sizeof(A)),r<<=1,c<<=1;
	}
	calc(__x,__y);
	(cnt>=INT_MAX/2)?puts("infinity"):printf("%d\n",cnt);
	return 0;
}/*fxxk you*/
