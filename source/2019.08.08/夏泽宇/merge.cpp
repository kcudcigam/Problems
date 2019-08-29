#include<bits/stdc++.h>
using namespace std;
int a[500010],fa[500010];
vector<int>g[500010];
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int Find(int x){
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		g[i].push_back(i);
	}
	for(int i=1;i<=q;i++){
		int op=read(),x=read(),y=read();
		if(op==1){
			if(Find(x)==Find(y))continue;
			int fax=Find(x),fay=Find(y);
			for(int i=0;i<g[fa[x]].size();i++)g[fay].push_back(g[fax][i]);
			g[fax].clear();
			fax=fay;
		}
		if(op==2){
			for(int i=0;i<g[x].size();i++)a[g[x][i]]+=y;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	puts("");
	return 0;
}


