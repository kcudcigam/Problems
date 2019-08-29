#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
#define N 300300
int n,m,q;
struct node{
	int nxt,to,age;
}s[N*2];
int head[N],tot=0;
inline void edge(int x,int y){
	s[++tot].to=y,s[tot].nxt=head[x],head[x]=tot,s[tot].age=0;
	return ;
}
int d[N];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x),read(y);
		edge(x,y),edge(y,x);
	}
	while(q--){
		int opt;
		read(opt);
		if(opt==0){
			int x;
			read(x);
			int ans=d[x];
			for(int i=head[x];i;i=s[i].nxt){
				int y=s[i].to;
				ans+=d[y];
			}
			printf("%d\n",ans);
		}
		if(opt==1){
			int x,y;
			read(x),read(y);
			d[x]+=y;	
		}
	}
	return 0;
}
