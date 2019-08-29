#include<bits/stdc++.h>
using namespace std;
const int N=600010;
int head[N],Next[N],ver[N],edge[N],w[N],spread[N];
int tot=0;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		add(a,b,1);
		add(b,a,1);
	}
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==0){
			int x=read();
			for(int i=head[x];i;i=Next[i]){
				if(spread[ver[i]]){
					for(int j=head[ver[i]];j;j=Next[j]){
						w[ver[j]]+=spread[ver[i]];
					}
					spread[ver[i]]=0;
				}
			}
			printf("%d\n",w[x]);
		}
		else {
			int x=read(),weight=read();
			spread[x]+=weight;
			w[x]+=weight;
		}
	}
	return 0;
}
