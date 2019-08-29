#include<bits/stdc++.h>
using namespace std;
const int MaxN=300010;
const int MaxM=600010;
struct edge {
	int v;
	int nxt;
}e[MaxM];
int n,m,q,x,y,type,head[MaxN],tot,f[MaxN],tag,color[MaxN],cnt;
int degree[MaxN],tag_[MaxN],center[MaxN];
bool special=1,linkto1[MaxN],vis[MaxN];
inline int read(){
	int w=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(x=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
void addedge(int x,int y) {
	e[++tot]=(edge){y, head[x]};
	head[x]=tot;
}
void dfs(int x) {
	vis[x]=1;
	color[x]=cnt;
	for (int i=head[x];i>=1;i=e[i].nxt) {
		int y=e[i].v;
		if (!vis[y]){
			dfs(y);
		}
	}
}
int main(){
	freopen("sibyl.in", "r", stdin);
	freopen("sibyl.out", "w", stdout);
	n=read();m=read();q=read();
	memset(f,0,sizeof(f));
	for(int i=1;i<=m;++i) {
		x=read();y=read();
		addedge(x,y);
		addedge(y,x);
		if (x==1||y==1){
			linkto1[x+y-1]=1;
		}
		++degree[x];
		++degree[y];
		if(x!=1&&degree[x]>10||y!=1&&degree[y]>10){
			special=0;
		}
	}
	if(n<=3000&&m<=3000&&q<=3000) {
		for(int i=1;i<=q;++i) {
			type=read();
			if(type==0){
				x=read();
				printf("%d\n",f[x]);
			}
			else{
				x=read();y=read();
				f[x]+=y;
				for(int i=head[x];i>=1;i=e[i].nxt) {
					f[e[i].v]+=y;
				}
			}
		}
	}
	else
	if (special){
		for (int i=1;i<=q;++i) {
			type=read();
			if(type==0) {
				x=read();
				if(linkto1[x]){
					printf("%d\n",f[x]+tag);
				}
				else{
					printf("%d\n",f[x]);
				}
			}
			else {
				x=read();y=read();
				f[x]+=y;
				if (x==1){
					tag+=y;
					continue;
				}
				for(int i=head[x];i>=1;i=e[i].nxt){
					f[e[i].v]+=y;
 				}
			}
		}
	}
	else{
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				++cnt;
				dfs(i);
			}
		}
		for(int i=1;i<=n;++i){
			if (degree[i]>=2){
				center[color[i]]=i;
			}
		}
		for(int i=1;i<=q;++i){
			type=read();
			if(type==0){
				x=read();
				if(x!=center[color[x]]){
					printf("%d\n",f[x]+tag_[color[x]]);
				}
				else{
					printf("%d\n",f[x]);
				}
			}
			else{
				x=read();y=read();
				f[x]+=y;
				if(x==center[color[x]]){
					tag_[color[x]]+=y;
					continue;
				}
				for(int i=head[x];i>=1;i=e[i].nxt){
					f[e[i].v]+=y;
				}
			}
		}
	}
	return 0;
}
