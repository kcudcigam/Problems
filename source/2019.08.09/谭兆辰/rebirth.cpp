#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
#define N 200200
int n,m;
struct node{
	int nxt,to,age;
}s[3*N];
int tot=1,head[N];
inline void edge(int x,int y,int z){
	s[++tot].to=y,s[tot].nxt=head[x],head[x]=tot,s[tot].age=z;
	return ;
}
int num,tmp1,tmp2;
bool vis[20020];
#include <queue>
#define ll long long
#define pii pair<ll,int> 
#define mp  make_pair
priority_queue<pii> q;
int went[20020];
ll dist[20020];
inline void dijkstra(int st){
	for(int i=1;i<=n;i++) dist[i]=1e17;
	q.push(mp(0,st));
	dist[st]=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=s[i].nxt){
			int y=s[i].to;
			if(dist[x]+s[i].age<dist[y]&&i!=tmp1&&i!=tmp2){
				dist[y]=dist[x]+1ll*s[i].age;
//				cout<<x<<" "<<y<<" "<<dist[x]<<" "<<" "<<s[i].age<<"\n";
				went[y]=i;
				q.push(mp(-dist[y],y));
			}
		}
	}
	return ;
}
int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	read(num);
	read(n),read(m);
	while(m--){
		int x,y,len;
		read(x),read(y),read(len);
		if(x!=y) edge(x,y,len),edge(y,x,len); 
	}
	tmp1=tmp2=-1;
	dijkstra(1);
	for(int i=1;i<=n;i++){
		if(i==1){
			cout<<0<<" ";
			continue;
		}
		tmp1=went[i],tmp2=went[i]^1;
		dijkstra(1);
		if(dist[i]==1e17) cout<<-1<<" ";
		else cout<<dist[i]<<" ";
	}
	return 0;
}
