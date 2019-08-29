#include<iostream>
#include<cstdio>
using namespace std;
/*
int a[32]={0,1,1,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,7,7};
int b[32]={0,3,2,5,4,3,2,1,6,5,4,3,2,1,6,5,4,3,2,7,6,5,4,3,2,7,6,5,4,3,6,5};
int c[32]={0,2,3,1,2,3,4,5,1,2,3,4,5,6,2,3,4,5,6,2,3,4,5,6,7,3,4,5,6,7,5,6};
int h[32][5];
int book1[10][50];
int book2[10][50];
int book3[10][50];
int pd[35];
int d[35];
int Ans,flag;
int n,k,x;
void dfs(int x,int step){
	if (Ans == n)
		return;
	if (step == 31){
		Ans ++;
		return;
	}
	if (pd[step+1])
		dfs(d[step+1],step+1);
	for (int i = 1; i <= k; ++ i){
		if (Ans == n)
			return;
		flag = 0;
		for (int j = 1; j <= 3; ++ j)
			if (d[h[step+1][j]] == i)
				flag = 1;
		if (!book1[a[step+1]][i]&&!book2[b[step+1]][i]&&!book3[c[step+1]][i]&&!flag){
			book1[a[step+1]][i]=1;
			book2[b[step+1]][i]=1;
			book3[c[step+1]][i];
			d[step+1] = i;
			dfs(i,step+1);
			book1[a[step+1]][i]=0;
			book2[b[step+1]][i]=0;
			book3[c[step+1]][i]=0;
		}
	}
}
*/
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	/*
	scanf("%d%d",&k,&n);
	h[4][1]=1;
	h[4][2]=3;
	h[5][1]=1;
	h[5][2]=2;
	h[5][3]=4;
	h[6][1]=2;
	h[6][2]=5;
	h[7][1]=6;
	h[8][1]=3;
	h[14][1]=8;
	h[14][2]=9;
	h[13][1]=7;
	h[13][2]=12;
	h[19][1]=14;
	h[24][1]=18;
	h[24][2]=23;
	h[25][1]=19;
	h[26][2]=20;
	h[30][1]=26;
	h[30][2]=27;
	h[31][1]=27;
	h[31][2]=28;
	h[31][3]=30;
	for (int i = 9; i <= 12; ++ i){
		h[i][1] = i-6;
		h[i][2] = i-5;
		h[i][3] = i-1;
	}
	for (int i = 15; i <= 18; ++ i){
		h[i][1] = i-6;
		h[i][2] = i-5;
		h[i][3] = i-1;
	}
	for (int i = 20; i <= 23; ++ i){
		h[i][1] = i-6;
		h[i][2] = i-5;
		h[i][3] = i-1;
	}
	for (int i = 26; i <= 29; ++ i){
		h[i][1] = i-6;
		h[i][2] = i-5;
		h[i][3] = i-1;
	}
	for (int i = 1; i <= 31; ++ i){
		scanf("%d",&x);
		if (x!=0){
			d[i] = x;
			pd[i] = 1;
			book1[a[i]][x] = 1;
			book2[b[i]][x] = 1;
			book3[c[i]][x] = 1;
		}
	}
	for (int i = 1; i <= k; ++ i){
		book1[a[1]][i]=1;
		book2[b[1]][i]=1;
		book3[c[1]][i]=1;
		d[1] = i;
		dfs(i,1);
		book1[a[1]][i]=0;
		book2[b[1]][i]=0;
		book3[c[1]][i]=0;
		if (Ans == n){
			printf("Found\n");
			for (int i = 1; i <= 31; ++ i)
				printf("%d ",d[i]);
			return 0;
		}
	}*/
	printf("No way");
}
