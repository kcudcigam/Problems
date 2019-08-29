#include<bits/stdc++.h>
#define ll long long
#define lmax 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=300010;
ll head[N],edge[N],ver[N],Next[N];
ll d[N];
map<int,ll>M[N];
int tot=0;
struct Info{
	ll dis,id;
};
struct cmp{
	bool operator()(Info a,Info b){
		if(a.dis>b.dis)return 1;
		else return 0;
	}
};
priority_queue<Info,vector<Info>,cmp>q;
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
void dij(int x){
	memset(d,0x3f,sizeof(d));
	q.push((Info){0,x});
	while(q.size()){
		Info t=q.top();
		q.pop();
		if(d[t.id]<=t.dis)continue;
		d[t.id]=t.dis;
		for(int i=head[t.id];i;i=Next[i]){//t是当前点 
			if(d[ver[i]]==lmax)q.push((Info){max(d[t.id],edge[i]),ver[i]}); 
		}
	}
}
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		if(M[x].count(y))printf("%lld",M[x][y]);
		else if(M[y].count(x))printf("%lld,",M[y][x]);
		else {
			dij(x);
			if(d[y]==lmax)printf("%d\n",-1);
			else printf("%d\n",d[y]);
			for(int i=1;i<=n;i++)M[x].insert(make_pair(x,d[i]));
		}
	}
	return 0;
}


