#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	T f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int N;
	read(N);
	int rt;
	int dis[N+1][N+1];
	bool cnct[N+1][N+1];
	memset(dis,0,sizeof(dis));
	for (int i=1;i<=N;i++){
		cnct[i][i]=true;
	}
	memset(cnct,false,sizeof(cnct));
	for (int k=1;k<N;k++){
		int x;
		int y;
		read(x);
		read(y);
		dis[x][y]=dis[y][x]=1;
		cnct[x][y]=cnct[y][x]=true;
		for (int i=1;i<=N;i++){
			if ((i!=x)&&(i!=y)){
				if (cnct[i][x]&&(!cnct[i][y])){
					dis[i][y]=dis[i][x]+1;
					dis[y][i]=dis[x][i]+1;
					cnct[i][y]=cnct[y][i]=true;
					for (int j=1;j<=N;j++){
						if ((j!=x)&&(j!=y)&&(i!=j)&&cnct[i][j]){
							dis[j][y]=dis[y][j]=dis[j][x]+1;
							cnct[j][y]=cnct[y][j]=true;
						}
					}
					for (int j=1;j<=N;j++){
						if ((j!=x)&&(j!=y)&&(i!=j)&&cnct[y][j]&&(!cnct[j][i])){
							dis[j][i]=dis[i][j]=dis[y][j]+dis[i][y];
							cnct[j][i]=cnct[i][j]=true;
						}
					}
				}
				if (cnct[i][y]&&(!cnct[i][x])){
					dis[i][x]=dis[i][y]+1;
					dis[x][i]=dis[y][i]+1;
					cnct[i][x]=cnct[x][i]=true;
					for (int j=1;j<=N;j++){
						if ((j!=x)&&(j!=y)&&(i!=j)&&cnct[i][j]){
							dis[j][x]=dis[x][j]=dis[j][y]+1;
							cnct[j][x]=cnct[x][j]=true;
						}
					}
					for (int j=1;j<=N;j++){
						if ((j!=x)&&(j!=y)&&(i!=j)&&cnct[x][j]&&(!cnct[j][i])){
							dis[j][i]=dis[i][j]=dis[x][j]+dis[i][x];
							cnct[j][i]=cnct[i][j]=true;
						}
					}
				}
			}
		}
		int maxx=0;
		for (int i=1;i<=N;i++){
			if (cnct[i][x]){
				for (int j=1;j<=N;j++){
					if (cnct[j][y]){
						maxx=max(maxx,dis[i][j]);
					}
				}
			}
			
		}
		writeln(maxx);
	}
	return 0;
}

