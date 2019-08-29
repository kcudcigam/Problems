#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q,v[300010],Max[300010],Min[300010],fa[300010];	
int head[300010],ver[600020],Next[600020],edge[600020],tot=1;
bool sign[300010];  int xx[300010];

inline int read(){
	int f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+(ch-'0'),ch=getchar();
	return f*num;
}

void add(int x,int y,int z){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;edge[tot]=z;
}

int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

//void dfs(int x,int end){
//	if(x==end)return;
//	v[x]=1;   
//	for(int i=head[x];i;i=Next[i])
//	  if(!v[ver[i]]){
//	  	Max[ver[i]]=max(Max[x],edge[i]);
//	  	dfs(ver[i],end);
//	  	Min[ver[i]]=min(Max[ver[i]],Min[ver[i]])
//	  }
//	v[x]=0;
//}

void dfs(int x,int end){
	if(x==end){
		Min[x]=min(Min[x],Max[x]); return;
	}
	v[x]=1;
	for(int i=head[x];i;i=Next[i])
	 if(!v[ver[i]]){
	 	Max[ver[i]]=max(Max[x],edge[i]);
		dfs(ver[i],end);
	 }
	v[x]=0;
}

int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    
    for(int i=1;i<=m;i++){
    	int a=read(),b=read(),c=read();
    	if(a==b||xx[a]==b)continue;   xx[a]=b;
    	add(a,b,c);  add(b,a,c);  fa[find(a)]=find(b);   
	}
    
//	for(int i=1;i<=n;i++){
//		if(!sign[find(i)]){
//			int x=find(i);  sign[x]=1;
//			for(int i=head[x];i;i=Next[i]){
//				Max[ver[i]]=max(Max[x],edge[i]);
//				dfs(ver[i],x);
//	        }
//		}
//	}
	
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		if(find(x)!=find(y)){puts("-1");continue;}
//		else printf("%d\n",min(Min[x],Min[y]));
        memset(v,0,sizeof(v));
        memset(Max,-1,sizeof(Max));
        memset(Min,0x3f,sizeof(Min));
        dfs(x,y);
        printf("%d\n",Min[y]);
	}
	return 0;
}


