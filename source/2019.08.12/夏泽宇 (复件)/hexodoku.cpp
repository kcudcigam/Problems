#include<bits/stdc++.h>
using namespace std;
int m[40][10];
int Result[40],Centre[40];
int k,n,cnt=0;
int Time;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int ex(int pos,int dir,int x){
	while(m[pos][dir]){
		pos=m[pos][dir];
		if(x==Result[pos])return 0;
	}
	return 1;
}
int Circle(int pos,int x){
	int flg=0;
	for(int i=1;i<=6;i++){
		if(Centre[m[pos][i]]){
			for(int j=1;j<=6;j++){
				if(Result[m[m[pos][i]][j]]==x&&m[m[pos][i]][j]!=pos)return 0;
			}
		}
		if(Centre[pos])
			for(int j=1;j<=6;j++)
				if(Result[m[pos][j]]==x)return 0;
	}
	return 1;
}
int End=0;
void dfs(int x){
	if(End)return ;
	if(time(0)-Time>=2){
		puts("No way");
		End=1;
	}
	if(Result[x]){
		dfs(x+1);
		return;
	}
	if(x==32){
		cnt++;
		if(cnt==n){
			puts("Found");
			for(int i=1;i<=31;i++)printf("%d ",Result[i]);
			puts("");
			End=1;
		}
		return ;
	}
	for(int j=1;j<=k;j++){
		int flg=1;
		for(int i=1;i<=6;i++){
			flg=flg&ex(x,i,j);
		}
		flg=flg&Circle(x,j);
		if(flg){
			Result[x]=j;
			dfs(x+1);
		}
		Result[x]=0;
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	k=read(),n=read();
	Time=time(0);
	for(int i=1;i<=31;i++)Result[i]=read();
	m[1][1]=2,m[1][5]=4,m[1][6]=5;
	m[2][4]=1,m[2][5]=5,m[2][6]=6;
	m[30][1]=31,m[30][2]=27,m[30][3]=26;
	m[31][2]=28,m[31][3]=27,m[31][4]=30;
	for(int i=3;i<=29;i++){
		m[i][1]=i+1;
		m[i][2]=i-5;
		m[i][3]=i-6;
		m[i][4]=i-1;
		m[i][5]=i+5;
		m[i][6]=i+6;
	}
	for(int i=3;i<=29;i++){
		if(i==7||i==13||i==18||i==24||i==29)m[i][1]=0;
		if(i==3||i==6||i==7||i==13||i==24)m[i][2]=0;
		if(i==3||i==4||i==8||i==19||i==7)m[i][3]=0;
		if(i==3||i==8||i==14||i==19||i==25)m[i][4]=0;
		if(i==8||i==19||i==25||i==26||i==29)m[i][5]=0;
		if(i==25||i==28||i==29||i==24||i==13)m[i][6]=0;
	}
	m[5][3]=1,m[5][2]=2;
	m[6][3]=2;
	m[4][2]=1;
	m[26][6]=30;
	m[27][5]=30,m[27][6]=31;
	m[28][5]=31;
	Centre[5]=1,Centre[9]=1,Centre[12]=1;
	Centre[16]=1,Centre[20]=1,Centre[23]=1;
	Centre[27]=1;
	dfs(1);
	if(!End)puts("No way");
	return 0;
}

//	m[3][1]=4,m[3][5]=8,m[3][6]=9;
//	m[4][1]=5,m[4][2]=1,m[4][4]=3,m[4][5]=9,m[4][6]=10;

