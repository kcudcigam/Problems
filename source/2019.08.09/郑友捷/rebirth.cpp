#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
struct sb{
	int to;
	int nxt;
	long long dis;
}s[1000010];
int head[200010],pos[200010],tot=1,now;
long long dis[200010];

bool inv[200010];
priority_queue<pair<long long,int> > q;
inline void add(int x,int y,long long z){
	s[++tot].dis=z;
	s[tot].nxt=head[x];
	s[tot].to=y;
	head[x]=tot;
}
inline void dijkstra(){
	for(register int i=1;i<=n;i++){
		dis[i]=99999999999999;
	}
	memset(inv,false,sizeof inv);
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(inv[x]) continue;
		inv[x]=true;
		for(register int i=head[x];i;i=s[i].nxt){
			int y=s[i].to;
			if(dis[y]>dis[x]+s[i].dis){
				pos[y]=i;
				dis[y]=dis[x]+s[i].dis;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
inline void dijkstra1(){
	for(register int i=1;i<=n;i++){
		dis[i]=99999999999999;
	}
	memset(inv,false,sizeof inv);
	q.push(make_pair(0,1));
	dis[1]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(inv[x]) continue;
		inv[x]=true;
		for(register int i=head[x];i;i=s[i].nxt){
			if(i==now||i==(now^1)) continue;
			int y=s[i].to;
			if(dis[y]>dis[x]+s[i].dis){
				dis[y]=dis[x]+s[i].dis;
				q.push(make_pair(-dis[y],y));
			}
		}
	}
}
int num;
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	scanf("%d",&num);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++){
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		if(x==y) continue;
		add(x,y,z);
		add(y,x,z);
	}
	dijkstra();
	if(num<=10){
		printf("0 ");
		for(register int i=2;i<=n;i++){
			now=pos[i];
			dijkstra1();
			printf("%lld ",(dis[i]==99999999999999)?-1:dis[i]);
		}
		return 0;
	}
} 
