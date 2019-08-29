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
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
vector<int>a[300010];
int w[300010],gz[300010],n,m,q;
int x[300010],y[300010];
struct Info{
	int opt,x,y;
}t[300010];
void baoli(){
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	while(q--){
		int opt;
		read(opt);
		if(opt==0){
			int x;
			read(x);
			writeln(w[x]);
		}else{
			int x,y;
			read(x);read(y);
			w[x]+=y;
			for(int i=0;i<a[x].size();i++)w[a[x][i]]+=y;
		}
	}
} 
void xuanxue(){
	for(int i=1;i<=m;i++){
		read(x[i]);read(y[i]);
	}
	for(int i=1;i<=q;i++){
		read(t[i].opt);read(t[i].x);
		if(t[i].opt==1)read(t[i].y);
		else gz[t[i].x]=1;
	}
	for(int i=1;i<=m;i++){
		if(gz[x[i]])a[y[i]].push_back(x[i]);
		if(gz[y[i]])a[x[i]].push_back(y[i]);
	}
	
	for(int i=1;i<=q;i++){
		if(t[i].opt==0){
			writeln(w[t[i].x]);
		}else{
			w[t[i].x]+=t[i].y;
			for(int j=0;j<a[t[i].x].size();j++)w[a[t[i].x][j]]+=t[i].y;
		}
	}
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);

	read(n);read(m);read(q);
	
	if(n<=3000&&m<=3000&&q<=3000){
		baoli();
	}else{
		xuanxue();
	}
	return 0;
}

/*
5 4 4
1 2
1 3
1 4
1 5
1 1 1
0 2
1 1 3
0 4

*/
