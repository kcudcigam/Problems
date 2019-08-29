#include <bits/stdc++.h>
using namespace std;
template<class T> inline void read(T& x){
	x=0;T f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')f*=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x*=f;
}
const int N=3010;
int head[N],cnt=0;
struct edge{
	int to,nxt;
}e[N<<1];
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
}
void addedge(int x,int y){
	add(x,y);
	add(y,x);
}
int d[N],inq[N];
void spfa(int s){
	queue<int> q;
	q.push(s);
	memset(inq,0,sizeof(inq));
	memset(d,0x3f,sizeof(d));
	d[s]=0;inq[s]=1;
	while (q.size()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for (int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if (d[v]>d[x]+1){
				d[v]=d[x]+1;
				if (!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}
vector<int> V;
int vis[N];
void getNode(int s){
	queue<int> q;
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	V.clear();
	while (q.size()){
		int x=q.front();
		q.pop();
		V.push_back(x);
		for (int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if (!vis[v]){
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n;read(n);
	for (int i=1;i<=n-1;i++){
		int x,y;read(x),read(y);
		addedge(x,y);
		getNode(x);
		int ans=0;
		for (int u,v,j=0;j<V.size();j++){
			spfa(u=V[j]);
			for (int k=0;k<V.size();k++){
				v=V[k];
				ans=max(ans,d[v]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5 
3 5
3 4
1 2
1 3
*/
