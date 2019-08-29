#include<bits/stdc++.h>
#define up(l,r,i) for(register int i=l;i<=r;i++)
#define dn(r,l,i) for(register int i=r;i>=l;i--)
using namespace std;
typedef long long LL;
int qread(){
	int w=1,c,ret;
	while((c=getchar())> '9'||c< '0')
	w=(c=='-'?-1:1); ret=c-'0';
	while((c=getchar())>='0'&&c<='9')
	ret=ret*10+c-'0';return ret*w;
}
const int MAXN =31+3;
int data[MAXN],k,n;
int mmp[3][MAXN]={{0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6},
				  {0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5},
				  {0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7}};
int ttt[MAXN][3]={{0},{1},{1},{2},{1,2},{1},{1,3},{3},{2},{2},{1,2,4},{1,3,4},{3},{3},{2,5},{2,4,5},{4},{3,4,6},{3,6},{5},{5},{4,5,7},{4,6,7},{6},{6},{5},{5,7},{7},{6,7},{6},{7},{7}};
bool A[8][MAXN],B[8][MAXN],C[8][MAXN],D[8][MAXN];
int _,cnt;
void dfs(int x){
	if(++_>=2e7&&(n-cnt>=1e5||cnt<=1e4)) puts("No way"),exit(0);
//	up(1,31,i) printf("%d ",data[i]); puts("");
	if(x==32){
		if(++cnt==n){
			puts("Found");
			up(1,31,i) printf("%d ",data[i]);
			exit(0);
		}
		return;
	}
	if(data[x]) dfs(x+1); else{
		up(1,k,i){
			if(!A[mmp[0][x]][i]&&!B[mmp[1][x]][i]&&!D[mmp[2][x]][i]){
				if((!ttt[x][0]||!C[ttt[x][0]][i])&&(!ttt[x][1]||!C[ttt[x][1]][i])&&(!ttt[x][2]||!C[ttt[x][2]][i])){
					A[mmp[0][x]][i]=B[mmp[1][x]][i]=D[mmp[2][x]][i]=true;
					if(ttt[x][0]) C[ttt[x][0]][i]=true;
					if(ttt[x][1]) C[ttt[x][1]][i]=true;
					if(ttt[x][2]) C[ttt[x][2]][i]=true;
					data[x]=i,dfs(x+1);
					A[mmp[0][x]][i]=B[mmp[1][x]][i]=D[mmp[2][x]][i]=false;
					if(ttt[x][0]) C[ttt[x][0]][i]=false;
					if(ttt[x][1]) C[ttt[x][1]][i]=false;
					if(ttt[x][2]) C[ttt[x][2]][i]=false;
					data[x]=0;
				}
			}
		}
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	
	k=qread(),n=qread();
	if(k<=6) puts("No way"),exit(0);
	up(1,31,i){
		data[i]=qread(); int t=data[i];
		if(!t) continue;
		if(A[mmp[0][i]][t]||B[mmp[1][i]][t]||D[mmp[2][i]][t]) puts("No way"),exit(0);
		if(!((ttt[i][0]==0||!C[ttt[i][0]][t])&&(ttt[i][1]==0||!C[ttt[i][1]][t])&&(ttt[i][2]==0||!C[ttt[i][2]][t])))
		puts("No way"),exit(0);
		A[mmp[0][i]][t]=B[mmp[1][i]][t]=D[mmp[2][i]][t]=true;
		if(ttt[i][0]) C[ttt[i][0]][t]=true;
		if(ttt[i][1]) C[ttt[i][1]][t]=true;
		if(ttt[i][2]) C[ttt[i][2]][t]=true;
	}
	dfs(1),puts("No way");
	return 0;
} 
/*
8 2000000000
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
