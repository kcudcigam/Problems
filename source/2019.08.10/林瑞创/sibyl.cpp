#include<bits/stdc++.h>
using namespace std;
int n,m,q,sum[300010];
int head[300010],ver[300010],Next[300010],tot=1;

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout); 
    n=read();m=read();q=read();
    for(int i=1;i<=m;i++){
    	int a=read(),b=read();
    	add(a,b);  add(b,a);
	}
	while(q--){
		int type=read();
		if(type){
			int x=read(),b=read();sum[x]+=b;
			for(int i=head[x];i;i=Next[i])
			  sum[ver[i]]+=b;
		}else printf("%d\n",sum[read()]);
	}
	return 0;
}


