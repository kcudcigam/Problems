#include<bits/stdc++.h>
using namespace std;
int n,k;
int z[15][15];
bool flag,vis[35];
int dx[]={2,-2,1,1,-1,-1},dy[]={0,0,1,-1,1,-1};
struct node{
	int x,y;
}w[35];
int zy(int a){
	return z[w[a].x][w[a].y];
}
bool Z(int a,int b,int c,int d,int e){
	if((zy(a)==zy(b)&&zy(a)!=0)||(zy(a)==zy(c)&&zy(a)!=0))
		return 0;
	if((zy(a)==zy(d)&&zy(a)!=0)||(zy(a)==zy(e)&&zy(a)!=0))
		return 0;
	if((zy(b)==zy(c)&&zy(b)!=0)||(zy(b)==zy(d)&&zy(b)!=0))
		return 0;
	if((zy(b)==zy(e)&&zy(b)!=0)||(zy(c)==zy(d)&&zy(c)!=0))
		return 0;
	if((zy(c)==zy(e)&&zy(c)!=0)||(zy(d)==zy(e)&&zy(d)!=0))
		return 0;
	return 1;
}
bool Y(int a,int b,int c,int d,int e,int f){
	if((zy(a)==zy(b)&&zy(a)!=0)||(zy(a)==zy(c)&&zy(a)!=0))
		return 0;
	if((zy(a)==zy(d)&&zy(a)!=0)||(zy(a)==zy(e)&&zy(a)!=0))
		return 0;
	if((zy(b)==zy(c)&&zy(b)!=0)||(zy(b)==zy(d)&&zy(b)!=0))
		return 0;
	if((zy(b)==zy(e)&&zy(b)!=0)||(zy(c)==zy(d)&&zy(c)!=0))
		return 0;
	if((zy(c)==zy(e)&&zy(c)!=0)||(zy(d)==zy(e)&&zy(d)!=0))
		return 0;
	if((zy(f)==zy(a)&&zy(f)!=0)||(zy(f)==zy(b)&&zy(f)!=0))
		return 0;
	if((zy(f)==zy(c)&&zy(f)!=0)||(zy(f)==zy(d)&&zy(f)!=0))
		return 0;
	if((zy(f)==zy(e)&&zy(f)!=0))
		return 0;
	return 1;
}
void init(){
	w[1].x=w[2].x=1;
	w[3].x=w[4].x=w[5].x=w[6].x=w[7].x=2;
	w[8].x=w[9].x=w[10].x=w[11].x=w[12].x=w[13].x=3;
	w[14].x=w[15].x=w[16].x=w[17].x=w[18].x=4;
	w[19].x=w[20].x=w[21].x=w[22].x=w[23].x=w[24].x=5;
	w[25].x=w[26].x=w[27].x=w[28].x=w[29].x=6;
	w[30].x=w[31].x=7;
	w[8].y=w[19].y=1;
	w[3].y=w[14].y=w[25].y=2;
	w[9].y=w[20].y=3;
	w[4].y=w[15].y=w[26].y=4;
	w[1].y=w[10].y=w[21].y=w[30].y=5;
	w[5].y=w[16].y=w[27].y=6;
	w[2].y=w[11].y=w[22].y=w[31].y=7;
	w[6].y=w[17].y=w[28].y=8;
	w[12].y=w[23].y=9;
	w[7].y=w[18].y=w[29].y=10;
	w[13].y=w[24].y=11;
}
bool judge(){
	int i,j;
	for(i=1;i<=7;i++){
		for(j=1;j<=10;j++)
			if(z[i][j])
				if(!vis[z[i][j]])
					vis[z[i][j]]=1;
				else
					return 0;
		memset(vis,0,sizeof(vis));
	}
	if((zy(3)==zy(8)&&zy(3)!=0)||(zy(24)==zy(29)&&zy(24)!=0))
		return 0;
	if((zy(7)==zy(13)&&zy(7)!=0)||(zy(19)==zy(25)&&zy(19)!=0))
		return 0;
	if(!Z(1,4,9,14,19)||!Z(6,11,16,21,26))
		return 0;
	if(!Z(13,18,23,28,31)||!Z(8,14,20,26,30))
		return 0;
	if(!Z(4,10,16,22,28)||!Z(2,6,12,18,24))
		return 0;
	if(!Y(3,9,15,21,27,31)||!Y(1,5,11,17,23,29))
		return 0;
	if(!Y(2,5,10,15,20,25)||!Y(7,12,17,22,27,30))
		return 0;
	if(zy(5))
		for(i=0;i<6;i++)
			if(z[w[5].x+dx[i]][w[5].y+dy[i]]==zy(5))
				return 0;
	if(zy(9))
		for(i=0;i<6;i++)
			if(z[w[9].x+dx[i]][w[9].y+dy[i]]==zy(9))
				return 0;
	if(zy(12))
		for(i=0;i<6;i++)
			if(z[w[12].x+dx[i]][w[12].y+dy[i]]==zy(12))
				return 0;
	if(zy(16))
		for(i=0;i<6;i++)
			if(z[w[16].x+dx[i]][w[16].y+dy[i]]==zy(16))
				return 0;
	if(zy(20))
		for(i=0;i<6;i++)
			if(z[w[20].x+dx[i]][w[20].y+dy[i]]==zy(20))
				return 0;
	if(zy(23))
		for(i=0;i<6;i++)
			if(z[w[23].x+dx[i]][w[23].y+dy[i]]==zy(23))
				return 0;
	if(zy(27))
		for(i=0;i<6;i++)
			if(z[w[27].x+dx[i]][w[27].y+dy[i]]==zy(27))
				return 0;
	return 1;
}
void dfs(int cur){
	int i;
	if(cur==32)
		if(judge())
			if(--n==0){
				flag=1;
				return;
			}
	if(cur%4==0)
		if(!judge())
			return;
	if(z[w[cur].x][w[cur].y]){
		dfs(cur+1);
		return;
	}
	for(i=1;i<=k;i++){
		z[w[cur].x][w[cur].y]=i;
		dfs(cur+1);
		if(flag)
			return;
		z[w[cur].x][w[cur].y]=0;
	}
}
void write(){
	int i;
	printf("Found\n");
	for(i=1;i<32;i++)
		printf("%d ",z[w[i].x][w[i].y]);
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	int i;
	scanf("%d%d",&k,&n);
	init();
	for(i=1;i<=31;i++)
		scanf("%d",&z[w[i].x][w[i].y]);
	dfs(1);
	if(!flag)
		printf("No way");
	else
		write();
	return 0;
}


