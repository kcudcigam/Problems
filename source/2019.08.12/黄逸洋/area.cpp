#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int a[600][600],b[600][600],vis[600][600];
int X,Y,ans=0,flg=0;
void dfs(int x,int y,int mk){
	if(flg)return;
	if(x==1||y==1){
		flg=1;
		return;
	}
	ans++;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(tx>=1&&ty>=1&&a[tx][ty]==mk&&!vis[tx][ty]){
			dfs(tx,ty,mk);
		}
	}
}
void baoli(){
	a[1][1]=a[1][2]=a[2][1]=1;a[2][2]=-1;
	int la=2,lb=4;
	for(int k=1;k<=8;k++){
		for(int i=1,ii=1;i<=la;i++,ii+=2){
			for(int j=1,jj=1;j<=la;j++,jj+=2){
				b[ii][jj]=a[i][j]*1;
				b[ii+1][jj]=a[i][j]*1;
				b[ii][jj+1]=a[i][j]*1;
				b[ii+1][jj+1]=a[i][j]*-1;
			}
		}
		for(int i=1;i<=lb;i++){
			for(int j=1;j<=lb;j++){
				a[i][j]=b[i][j];
			}
		}
		la=lb;
		lb*=2;
	}
	
	dfs(X+1,Y+1,a[X+1][Y+1]);
	if(flg)cout<<"infinity"<<endl;
	else writeln(ans);
}
void pianfen(){
	cout<<"infinity"<<endl;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	
	read(X);read(Y);
	if(X<=100&&Y<=100){
		baoli();
	}else{
		pianfen();
	}
	return 0;
}


