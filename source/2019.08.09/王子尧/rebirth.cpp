#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);
} 
int n,m;
struct wzy{
	int nxt,vertice,w;
}edge[1000010];
int head[200010];int len=1;
inline void add_edge(int x,int y,int z){
	edge[++len].nxt=head[x];edge[len].vertice=y;
	head[x]=len;edge[len].w=z;return;
}
long long ans[200010];

priority_queue<pair<long long,int> >v;
bool in[200010];long long dis[200010];long long t[200010];
int wa=0;
inline void SPFA(){
	rep(i,1,n)dis[i]=1e16;
	v.push(make_pair(0,1));in[1]=1;dis[1]=0;
	while(!v.empty()){
		int x=v.top().second;in[x]=0;v.pop();
		for(int i=head[x];i;i=edge[i].nxt){
			int nop=edge[i].vertice;
			if(i==wa||i==(wa^1))continue;
			if(dis[x]+edge[i].w<dis[nop]){
				dis[nop]=dis[x]+edge[i].w;
				if(!in[nop]){in[nop]=1;v.push(make_pair(-dis[nop],nop));}
			}
		}
	}
	return;
}

int main(){
	freopen("rebirth.in","r",stdin);
	freopen("rebirth.out","w",stdout);
	
	int num;read(num);
	read(n);read(m);
	rep(i,1,m){
		int x,y,l;read(x);read(y);read(l);
		if(x!=y){add_edge(x,y,l);add_edge(y,x,l);}
	} 
	SPFA();
	rep(i,1,n)t[i]=dis[i];
	
	ans[1]=0;
	rep(i,2,n){
		int t1=0;int t2=0;int bj=0;
		for(int j=head[i];j;j=edge[j].nxt){
			int nop=edge[j].vertice;
			if(t[nop]+edge[j].w==t[i]){bj=j;}
			if(!t1){t1=nop;}
			else if(t1&&t1!=nop){t2=nop;}
		}
		if(!t2){ans[i]=-1;continue;}
		wa=bj;
		SPFA();ans[i]=((dis[i]==1e16)?-1:dis[i]);
	}
	rep(i,1,n){write(ans[i]);putchar((i==n)?'\n':' ');}
	return 0;
} 
