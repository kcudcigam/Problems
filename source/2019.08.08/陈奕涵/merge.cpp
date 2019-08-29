#include<bits/stdc++.h>
using namespace std;
//fast io
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for(;c< '0' || c >'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0' && c<='9';c=getchar())x=x*10+c-'0';
	x*=f;
}
//数据
const int maxn=500010;
int n,m,ans[maxn];
vector<int>e[maxn];
//bfs
int vis[maxn];
queue<int>q;
void bfs(int x,int val){
	memset(vis,0,sizeof(int)*(n+1));
	q.push(x),vis[x]=1,ans[x]+=val;
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=0;i<e[now].size();++i){
			x=e[now][i];
			if(!vis[x])q.push(x),vis[x]=1,ans[x]+=val;
		}
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n),read(m);
	while(m--){
		int opt,x,y;
		read(opt),read(x),read(y);
		if(opt==1){//合并 
			e[x].push_back(y);
			e[y].push_back(x);
		}
		else bfs(x,y);//捏橙子
	}
	for(int i=1;i<n;++i)printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}

