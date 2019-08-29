#include<bits/stdc++.h>
using namespace std;
int ver[300010],head[300010],next[300010],tot=0,edge[300010];
void add(int x,int y){
	ver[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
}
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n=read(),m=read(),Q=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		add(x,y);
		add(y,x);
	}
	memset(edge,0,sizeof(edge));
	while(Q--){
		int type=read();
		if(!type)cout<<edge[read()]<<endl;
		else{
			int loca=read(),val=read();
			for(int i=head[loca];i;i=next[i])edge[ver[i]]+=val;			
		}
	}	
	return 0;
}
