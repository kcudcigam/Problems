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
vector<int>a[300010];
int d[2][300010],l[300010],n;
void addedge(int x,int y){
	a[x].push_back(y);
	a[y].push_back(x);
}
void _rotate(int fa,int x){
	swap(d[0][x],d[1][x]);
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=fa)_rotate(x,a[x][i]);
	}
}
void dfs1(int fa,int x,int t0,int t1){
	d[0][x]=t0;d[1][x]=t1;
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=fa)dfs1(x,a[x][i],t0+1,t1+1);
	}
}
void dfs2(int fa,int x,int opt,int t){
	d[opt][x]=t;
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=fa)dfs2(x,a[x][i],opt,t+1);
	}
}
void dfs3(int fa,int x,int t){
	l[x]=t;
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]!=fa)dfs3(x,a[x][i],t);
	}
}
void hebing(int x,int y){
	int ans;
	int tmp=max(d[0][x],d[1][x])+1+max(d[0][y],d[1][y]);
	if(l[x]>=tmp){
		dfs1(x,y,d[0][x]+1,d[1][x]+1);
		ans=l[x];
		addedge(x,y);
	}else if(l[y]>=tmp){
		dfs1(y,x,d[0][y]+1,d[1][y]+1);
		ans=l[y];
		addedge(x,y);
	}else{
		if(d[0][x]>=d[1][x]&&d[0][y]>=d[1][y]){
			_rotate(x,y);
			dfs2(x,y,0,d[0][x]+1);
			dfs2(y,x,1,d[1][y]+1);
		}else if(d[0][x]>=d[1][x]&&d[1][y]>=d[0][y]){
			dfs2(x,y,0,d[0][x]+1);
			dfs2(y,x,1,d[1][y]+1);
		}else if(d[1][x]>=d[0][x]&&d[0][y]>=d[1][y]){
			dfs2(x,y,1,d[1][x]+1);
			dfs2(y,x,0,d[0][y]+1);
		}else if(d[1][x]>=d[0][x]&&d[1][y]>=d[0][y]){
			_rotate(x,y);
			dfs2(x,y,1,d[1][x]+1);
			dfs2(y,x,0,d[0][y]+1);
		}
		ans=tmp;
		addedge(x,y);
	}
	dfs3(0,x,ans);
	writeln(ans);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);

	read(n);
	for(int i=1;i<n;i++){
		int x,y;
		read(x);read(y);
		hebing(x,y);
	}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3

8
1 2
2 3
3 4
4 5
3 6
6 7
7 8

8
1 2
3 4
5 6
7 8
2 3
4 5
6 7

*/


