#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int k,n;
bool vis[32][32];
int now[32];
int f[4][32][10],tot[4][32];
int in[32][4];
bool fg[32],flag=0;
struct node{
	int nxt,to;
}s[20200];
int head[10010],tot1=0;
inline void edge(int x,int y){
	s[++tot1].to=y,s[tot1].nxt=head[x],head[x]=tot1;
	return ;
}
int a[8];
int cnt=0;
inline void dfs(int x){
//	cout<<x<<" ";
	if(x==32){
		cnt++;
		if(cnt==n){	
			cout<<"Found\n";
			for(int i=1;i<=31;i++){
				cout<<now[i]<<" ";
			}
			flag=1;
		} 
		return ;
	}
	if(flag) return ;
	if(fg[x]){
		dfs(x+1);
		return ;
	}
	for(int i=1;i<=k;i++) vis[x][i]=0;
	int l,r;
	int ha=in[x][0];
	for(int i=1;i<=tot[0][ha];i++) vis[x][now[f[0][ha][i]]]=1;
	ha=in[x][1];
	for(int i=1;i<=tot[1][ha];i++) vis[x][now[f[1][ha][i]]]=1;
	ha=in[x][2];
	for(int i=1;i<=tot[2][ha];i++) vis[x][now[f[2][ha][i]]]=1;
	for(int i=head[x];i;i=s[i].nxt){
		int y=s[i].to;
		vis[x][now[y]]=1;
	}
	for(int i=1;i<=k;i++){
		if(flag) return ;
		if(!vis[x][i]){
			now[x]=i;
			dfs(x+1);
			now[x]=0;
		}
	}
	return ;
}
inline void work(int st,int ed,int cha,int op,int num){
	for(int i=st;i<=ed;i+=cha) f[op][num][++tot[op][num]]=i,in[i][op]=num;
	return ;
}
inline void init(){
	for(int i=1;i<=7;i++){
		for(int j=1;j<=7;j++){
			if(i!=j){
				edge(a[i],a[j]);
			}
		}
	}
	return ;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&k,&n);
	for(int i=1;i<=31;i++){
		scanf("%d",&now[i]);
		if(now[i]) fg[i]=1;
	}
	work(1,2,1,0,1);
	work(3,7,1,0,2);
	work(8,13,1,0,3);
	work(14,18,1,0,4);
	work(19,24,1,0,5);
	work(25,29,1,0,6);
	work(30,31,1,0,7);
	work(3,8,5,1,1);
	work(1,1,1,1,2);
	work(4,19,5,1,2);
	work(2,2,1,1,3);
	work(5,25,5,1,3); 
	work(6,26,5,1,4);
	work(7,27,5,1,5); 
	work(30,30,1,1,5); 
	work(13,28,5,1,6);
	work(31,31,1,1,6);
	work(24,29,5,1,7);
	work(7,13,6,2,1);
	work(2,2,1,2,2);
	work(6,24,6,2,2);
	work(1,1,1,2,3);
	work(5,29,6,2,3);
	work(4,28,6,2,4);
	work(3,27,6,2,5);
	work(31,31,1,2,5);
	work(8,26,6,2,6);
	work(30,30,1,2,6);
	work(19,25,6,2,7);
	a[1]=1,a[2]=2,a[3]=4,a[4]=5,a[5]=6,a[6]=10,a[7]=11;
	init(); 
	a[1]=3,a[2]=4,a[3]=8,a[4]=9,a[5]=10,a[6]=14,a[7]=15;
	init(); 
	a[1]=6,a[2]=7,a[3]=11,a[4]=12,a[5]=13,a[6]=17,a[7]=18;
	init(); 
	a[1]=10,a[2]=11,a[3]=15,a[4]=16,a[5]=17,a[6]=21,a[7]=22;
	init(); 
	a[1]=14,a[2]=15,a[3]=19,a[4]=20,a[5]=21,a[6]=25,a[7]=26;
	init(); 
	a[1]=17,a[2]=18,a[3]=22,a[4]=23,a[5]=24,a[6]=28,a[7]=29;
	init(); 
	a[1]=21,a[2]=22,a[3]=26,a[4]=27,a[5]=28,a[6]=30,a[7]=31;
	init(); 
	dfs(1);
	if(!flag) cout<<"No way";
	return 0;
}
