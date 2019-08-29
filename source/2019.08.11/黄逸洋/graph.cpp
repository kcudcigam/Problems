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
		putchar('-');
		write(-x);
		return;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
struct Node{
	int id,w; 
};
vector<Node>a[300010];
bool flg;
int vis[300010];
void dfs(int lim,int x,int y){
	vis[x]=1;
	if(flg)return;
	if(x==y){
		flg=1;
		return;
	}
	for(int i=0;i<a[x].size();i++){
		if(!vis[a[x][i].id]&&a[x][i].w<=lim){
			dfs(lim,a[x][i].id,y);
		}
	}
}
bool check(int lim,int x,int y){
	memset(vis,0,sizeof(vis));
	flg=0;
	dfs(lim,x,y);
	return flg;
}
int query(int x,int y){
	int l=0,r=0x3f3f3f3f;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid,x,y)){
			r=mid;
		}else{
			l=mid;
		}
	}
	return r==0x3f3f3f3f?-1:r;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);

	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=m;i++){
		int x,y,w;
		read(x);read(y);read(w);
		a[x].push_back((Node){y,w});
		a[y].push_back((Node){x,w});
	}
	
	while(q--){
		int x,y;
		read(x);read(y);
		writeln(query(x,y));
	}
	return 0;
}



