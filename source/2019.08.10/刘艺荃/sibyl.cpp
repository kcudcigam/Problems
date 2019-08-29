#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
void write(int x){
	if(x<0){putchar('-');write(-x);}
	if(x>9){write(x/10);}
	putchar(x%10+'0');
}
int n,m,Q,tot;
int ver[600010],nxt[600010],head[600010],a[600010];
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=m;i++){
		int x,y;read(x);read(y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=Q;i++){
		int opt;read(opt);
		if(opt==1){
			int x,y;read(x);read(y);
			a[x]+=y;
		}else if(opt==0){
			int x;int res=0;read(x);
			res+=a[x];
			for(int j=head[x];j;j=nxt[j]){
				int v=ver[j];
				if(a[v])res+=a[v];
			}
			write(res);putchar('\n');
		}
	}
	return 0;
}
/*
4 4 9
1 2
1 3
1 4
2 3
1 1 1
1 2 3
0 4
0 2
1 1 3
1 3 3
0 3
1 4 2
0 1
*/

