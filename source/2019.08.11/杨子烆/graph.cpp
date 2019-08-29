#include<bits/stdc++.h>
using namespace std;
struct b{
	int x;int y;int valu;
};	
int vi[300001];
int bc[300001];
int get(int x){
	if(x==bc[x])return x;
	return bc[x]=get(bc[x]);
}

int has[300001];
b bia[300001] ;
long long ans[300001];
vector<int> bj[300001];
int ask[300001];
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	
	int n,m,q;
	read(n);read(m);read(q);
	int x,y,z;
	b s;
	for(int i=1;i<=m;i++){
		read(x);
		read(y);
		read(z);
		bia[i].x=x;
		bia[i].y=y;
		bia[i].valu=z;
	} 
	for(int i=1;i<=q;i++){
		read(x);read(y);
		bj[x].push_back(i);
		bj[y].push_back(i);
	}
	for(int i=1;i<=n;i++){
		bc[i]=i;
	}
	int maxx=-1,nw,nx,ny;
	for(int i=1;i<=m;i++){
		nw=bia[i].valu;
		maxx=max(maxx,nw);
		int nx=get(bia[i].x);
		int ny=get(bia[i].y);
		if(nx==ny){
			continue;
		}
		bc[nx]=ny;
		for(int i=0;i<bj[nx].size();i++){
			bj[ny].push_back(bj[nx][i]);
		}
		for(int i=0;i<bj[ny].size();i++){
			vi[bj[ny][i]]++;
			if(vi[bj[ny][i]]==2){
				if(ans[bj[ny][i]]==0)ans[bj[ny][i]]=maxx;
		}
		
		}
		memset(vi,0,sizeof(vi));
	}
	for(int i=1;i<=q;i++){
	
		 writeln(ans[i]-1);
	}
	return 0;
}


