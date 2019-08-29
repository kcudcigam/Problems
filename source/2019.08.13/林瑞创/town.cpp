#include<bits/stdc++.h>
using namespace std;
int n,m,d[300010],dist[300010],ans,fa[300010];  bool v[300010];
int head[300010],Next[600010],ver[600010],edge[600010],tot=1;

inline int read(){
	int f=1,num=0;  char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

void add(int x,int y,int z){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;edge[tot]=z;
}

int find(int x){return x==fa[x] ? x : fa[x]=find(fa[x]);}

void dfs(int x){
	v[x]=1;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(v[y])continue;
		dfs(y);
		ans=max(ans,d[x]+d[y]+edge[i]);
		d[x]=max(d[x],d[y]+edge[i]);
	}
}

int main(){
    freopen("town.in","r",stdin);
    freopen("town.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++){
    	int a=read(),b=read();
    	add(a,b,1);add(b,a,1); 
    	int x=find(a),y=find(b);
    	fa[x]=y;  
    	memset(v,0,sizeof(v));
    	memset(d,0,sizeof(d));
		ans=0;   dfs(y);
        printf("%d\n",ans);
	}
	return 0;
}


