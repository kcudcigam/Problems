#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,Q;
bool vis[maxn];
struct node{
	int fa,num;
	vector<int>son;
}fa[maxn];
int find(int a){
	if(a==fa[a].fa)
		return a;
	int k=fa[a].fa;
	fa[a].fa=find(fa[a].fa);
	if(k!=fa[a].fa)
		fa[fa[a].fa].son.push_back(a);
	return fa[a].fa;
}
void Union(int a){
	vis[a]=0;
	int i,v;
	for(i=0;i<fa[a].son.size();i++){
		v=fa[a].son[i];
		if(v==a)
			continue;
		if(vis[v])
			Union(v);
		fa[fa[a].fa].son.push_back(v);
	}
}
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);
	read(Q);
	int i,op,x,y,v,j;
	for(i=1;i<=n;i++){
		fa[i].fa=i;
		fa[i].son.push_back(i);
	}
	for(i=1;i<=Q;i++){
		read(op);
		read(x);
		read(y);
		if(op==1){
			x=find(x);
			y=find(y);
			if(x==y)
				continue;
			fa[x].fa=y;
			fa[y].son.push_back(x);
			vis[x]=1;
		}
		else{
			x=find(x);
			for(j=0;j<fa[x].son.size();j++){
				v=fa[x].son[j];
				if(vis[v])
					Union(v);
				fa[v].num+=y;
			}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",fa[i].num);
	return 0;
}
