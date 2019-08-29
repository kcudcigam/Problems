#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
const int Ma=100000020;
long long f[40],mul,a[150][150],d[150][150],x,y,ff[150][150],tot;
int dfs(int x,int y,int pd,int f){
	d[x][y]=1;ff[x][y]=f;
	if(x>1&&!d[x-1][y]&&a[x][y]==a[x-1][y]) d[x][y]+=dfs(x-1,y,pd,f);
	if(y>1&&!d[x][y-1]&&a[x][y]==a[x][y-1]) d[x][y]+=dfs(x,y-1,pd,f);
	if(x<128&&!d[x+1][y]&&a[x][y]==a[x+1][y]) d[x][y]+=dfs(x+1,y,pd,f);
	if(y<128&&!d[x][y+1]&&a[x][y]==a[x][y+1]) d[x][y]+=dfs(x,y+1,pd,f);
	if(pd) d[x][y]=Ma;
	return d[x][y];
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	f[1]=1;f[2]=5;mul=9;
	for(int i=3;i<=35;i++){
		f[i]=f[i-1]*2+mul;
		for(int j=1;j<=i-3;j++) f[i]+=f[j]*2;
		mul*=3;
	}
	a[1][1]=1;
	for(int i=2;i<=128;i<<=1){
		for(int j=(i>>1)+1;j<=i;j++){
			for(int k=1;k<j;k++){
				a[j][k]=a[j-(i>>1)][k];
			}
			for(int k=1;k<=(i>>1);k++){
				a[k][j]=a[k][j-(i>>1)];
			}
			for(int k=(i>>1)+1;k<=i;k++){
				a[j][k]=!a[j-(i>>1)][k-(i>>1)];
			}
		}
	}
	dfs(1,1,1,1);
	tot=1;
	for(int i=1;i<=128;i++){
		for(int j=1;j<=128;j++){
			if(!d[i][j]) dfs(i,j,0,++tot);
		}
	}
	read(x);read(y);
	x++;y++;
	if(d[x][y]==Ma) printf("infinity\n");
	else printf("%d\n",d[x][y]);
	return 0;
}

