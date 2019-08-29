#include<bits/stdc++.h>
using namespace std;
const int N=300010,M=600010;
int head[N],ver[M],edge[M],Next[M],fa[N];
int n,m,Q,tot,Mx,L,R,S,T,Ans;
queue<int> q;
bool f[N];
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
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool judge(int len){
	memset(f,0,sizeof(f));
	while(!q.empty())q.pop();
	f[S]=1;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x],y;i;i=Next[i]){
			y=ver[i];
			if(edge[i]>len)continue;
			if(f[y])continue;
			if(y==T)return 1;
			f[y]=1;q.push(y);
		}
	}
	return 0;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);	
	n=read();m=read();Q=read();tot=1;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++){
		x=read();y=read();z=read();
		add(x,y,z);add(y,x,z);
		Mx=max(Mx,z);
		int xx=find(x),yy=find(y);
		if(xx!=yy)fa[yy]=xx;
	}
	while(Q--){
	    S=read();T=read();
	    if(find(S)!=find(T)){printf("-1\n");continue;} 
    	L=0;R=Mx;Ans=-1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(judge(mid)){Ans=mid;R=mid-1;}
			else L=mid+1;
		}
		printf("%d\n",Ans);
	}
	return 0;
}
