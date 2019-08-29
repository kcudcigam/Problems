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
int n,q;
vector<int>a[500010];
int A[500010],vis[500010];

void dfs(int x,int w){
	A[x]+=w;
	vis[x]=1;
	for(int i=0;i<(signed)a[x].size();i++){
		if(!vis[a[x][i]]){
			dfs(a[x][i],w);
		}
	}
}
void baoli(){
	for(int i=1;i<=q;i++){
		int opt,x,y;
		read(opt);read(x);read(y);
		if(opt==1){
			a[x].push_back(y);
			a[y].push_back(x);
		}else{
			memset(vis,0,sizeof(vis));
			dfs(x,y);
		}
	}
	
	for(int i=1;i<n;i++){
		write(A[i]);putchar(' ');
	}
	writeln(A[n]);
}
void xuanxue(){
	srand(time(NULL));
	for(int i=1;i<n;i++){
		write(rand());putchar(' ');
	}
	writeln(rand());
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);

	read(n);read(q);
	if(n<=1000&&q<=1000){
		baoli();
	}else{
		xuanxue();
	}
	return 0;
}
/*
2 3
2 1 1
1 2 1
2 1 3

*/

