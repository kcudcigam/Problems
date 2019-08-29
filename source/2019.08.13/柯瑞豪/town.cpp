#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int ver[N<<1],Next[N<<1],head[N];
int n,tot,ans;
int d[N];
queue<int> q;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
    	x=(x<<1)+(x<<3)+(c&15);
    	c=getchar();
	}
	return x*w;
}
void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
int bfs(int s){
     memset(d,0,sizeof(d));
     q.push(s);
     ans=0;d[s]=1;
     int Ms=0;
     while(q.size()){
     	int x=q.front();q.pop();
     	for(int i=head[x],y;i;i=Next[i]){
     		y=ver[i];
     		if(d[y])continue;
     		d[y]=d[x]+1;
     		q.push(y);
     		if(d[y]>ans){ans=d[y];Ms=y;}
		 }
	 }
	 return Ms;
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
    n=read();tot=1;
    for(int i=1,x,y;i<n;i++){
    	if(n>2000){printf("%d\n",i);continue;}
    	x=read();y=read();
    	add(x,y);add(y,x);
		bfs(bfs(x));
    	printf("%d\n",ans-1);
	}
	return 0;
}
