#include<bits/stdc++.h>
using namespace std;
int g[1111][1111];
template <typename T> void read(T &x){
	int f=1;
	x=0;
	char ch=getchar();
	for (;!isdigit(ch);ch=getchar()){
		if (ch=='-'){
			f=-f;
		}
	}
	for (;isdigit(ch);ch=getchar()){
		x*=10;
		x+=ch-'0';
	}
	x*=f;
}
template <typename T> void write(T x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
template <typename T> void writeln(T x){
	write(x);
	puts("");
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n,m,Q;
	read(n);
	read(m);
	read(Q);
	for (int i=1;i<=m;i++){
		int x,y,w;
		read(x);
		read(y);
		read(w);
		if (g[x][y]){
			g[x][y]=min(g[x][y],w);
			g[y][x]=min(g[y][x],w);
		}
		else {
			g[x][y]=w;
			g[y][x]=w;
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (g[i][j]&&g[i][k]&&g[k][j]){
					if ((i!=j)&&(i!=k)&&(j!=k)){
						g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
					}
				}
			}
		}
	}
	while (Q--){
		int x,y;
		read(x);
		read(y);
		if (g[x][y]){
			writeln(g[x][y]);
		}
		else {
			puts("-1");
		}
	}
	return 0;
}

