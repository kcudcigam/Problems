#include<cstdio>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int bl[10][35],n,k,x,tot,nu,nw[35];
bool us[35][35],yep;
void dfs(int x){
	if(yep) return;
	if(x==32){
		nu++;
		if(nu==k){
			printf("Found\n");
			for(int i=1;i<=31;i++) printf("%d ",nw[i]);
			printf("\n");
			yep=1;
			return;
		}
		return;
	}
	if(nw[x]){
		dfs(x+1);
		return;
	}
	for(int i=1;i<=n;i++){
		bool fl=1;
		for(int j=1;j<=6;j++){
			if(!bl[j][x]) break;
			if(us[bl[j][x]][i]) fl=0;
		}
		if(fl){
			for(int j=1;j<=6;j++){
				if(!bl[j][x]) break;
				us[bl[j][x]][i]=1;
			}
			nw[x]=i;
			dfs(x+1);
			if(yep) return;
			for(int j=1;j<=6;j++){
				if(!bl[j][x]) break;
				us[bl[j][x]][i]=0;
			}
			nw[x]=0;
		}
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	tot=1;
	for(int i=1;i<=2;i++) bl[1][i]=tot;tot++;
	for(int i=3;i<=7;i++) bl[1][i]=tot;tot++;
	for(int i=8;i<=13;i++) bl[1][i]=tot;tot++;
	for(int i=14;i<=18;i++) bl[1][i]=tot;tot++;
	for(int i=19;i<=24;i++) bl[1][i]=tot;tot++;
	for(int i=25;i<=29;i++) bl[1][i]=tot;tot++;
	for(int i=30;i<=31;i++) bl[1][i]=tot;tot++;
	bl[2][19]=bl[2][25]=tot;tot++;
	bl[2][8]=bl[2][14]=bl[2][20]=bl[2][26]=bl[2][30]=tot;tot++;
	bl[2][3]=bl[2][9]=bl[2][15]=bl[2][21]=bl[2][27]=bl[2][31]=tot;tot++;
	bl[2][4]=bl[2][10]=bl[2][16]=bl[2][22]=bl[2][28]=tot;tot++;
	bl[2][1]=bl[2][5]=bl[2][11]=bl[2][17]=bl[2][23]=bl[2][29]=tot;tot++;
	bl[2][2]=bl[2][6]=bl[2][12]=bl[2][18]=bl[2][24]=tot;tot++;
	bl[2][7]=bl[2][13]=tot;tot++;
	
	bl[3][3]=bl[3][8]=tot;tot++;
	bl[3][1]=bl[3][4]=bl[3][9]=bl[3][14]=bl[3][19]=tot;tot++;
	bl[3][2]=bl[3][5]=bl[3][10]=bl[3][15]=bl[3][20]=bl[3][25]=tot;tot++;
	bl[3][6]=bl[3][11]=bl[3][16]=bl[3][21]=bl[3][26]=tot;tot++;
	bl[3][7]=bl[3][12]=bl[3][17]=bl[3][22]=bl[3][27]=bl[3][30]=tot;tot++;
	bl[3][13]=bl[3][18]=bl[3][23]=bl[3][28]=bl[3][31]=tot;tot++;
	bl[3][24]=bl[3][29]=tot;tot++;
	
	bl[4][1]=bl[4][2]=bl[4][4]=bl[4][5]=bl[4][6]=bl[4][10]=bl[4][11]=tot;tot++;
	bl[4][3]=bl[5][4]=bl[4][8]=bl[4][9]=bl[5][10]=bl[4][14]=bl[4][15]=tot;tot++;
	bl[5][6]=bl[4][7]=bl[5][11]=bl[4][12]=bl[4][13]=bl[4][17]=bl[4][18]=tot;tot++;
	bl[6][10]=bl[6][11]=bl[5][15]=bl[4][16]=bl[5][17]=bl[4][21]=bl[4][22]=tot;tot++;
	bl[5][14]=bl[6][15]=bl[4][19]=bl[4][20]=bl[5][21]=bl[4][25]=bl[4][26]=tot;tot++;
	bl[6][17]=bl[5][18]=bl[5][22]=bl[4][23]=bl[4][24]=bl[4][28]=bl[4][29]=tot;tot++;
	bl[6][21]=bl[6][22]=bl[5][26]=bl[4][27]=bl[5][28]=bl[4][30]=bl[4][31]=tot;tot++;
	
	read(n);read(k);
	if(n<=6){
		printf("No way\n");
		return 0;
	}
	bool fl=1;
	for(int i=1;i<=31;i++){
		read(x);
		if(!fl) break;
		if(x){
			nw[i]=x;
			for(int j=1;j<=6;j++){
				if(!bl[j][i]) break;
				if(us[bl[j][i]][x]){
					fl=0;continue;
				}
				us[bl[j][i]][x]=1;
			}
		}
	}
	if(!fl){
		printf("No way\n");
		return 0;
	}
	dfs(1);
	if(!yep){
		printf("No way\n");
		return 0;
	}
	return 0;
}

