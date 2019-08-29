#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int head[N],Next[N],ver[N],edge[N];
int tot=0;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int d[N];
void dfs(int x,int fa_d,int fa){
	d[x]=fa_d+1;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(y==fa)continue;
		dfs(y,d[x],x);
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n=read();
	for(int i=1;i<=n-1;i++){
		int x=read(),y=read();
		add(x,y,1);
		add(y,x,1);
		for(int k=1;k<=n;k++)d[k]=0;
		dfs(x,-1,0);
		int Max=-1,record=0;
		for(int j=1;j<=n;j++){
			if(d[j]>Max)Max=d[j],record=j;
		}
		for(int k=1;k<=n;k++)d[k]=0;
		dfs(record,-1,0);
		Max=-1,record=0;
		for(int j=1;j<=n;j++){
			if(d[j]>Max)Max=d[j],record=j;
		}
		printf("%d\n",Max);
	}
	return 0;
}



