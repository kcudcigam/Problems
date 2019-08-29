#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
const int N=300011;
const int Ma=100000011;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,m,Q,x,y,z,tot,hed[N],to[N],nxt[N*2],edg[N],f[N],d[N],dd[N],t[N];
bool us[N];
priority_queue<pair<int,int> > q;
void build(int x,int y,int z){
	to[++tot]=y;
	edg[tot]=z;
	nxt[tot]=hed[x];
	hed[x]=tot;
}
void dj(int st){
	d[st]=0;
	q.push(make_pair(0,st));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(f[x]) continue;
		f[x]=st;
		for(int i=hed[x];i;i=nxt[i]){
			int y=to[i],z=max(d[x],edg[i]);
			if(z<d[y]){
				d[y]=z;
				q.push(make_pair(-d[y],y));
				t[y]=(d[x]<edg[i])?i:t[x];
			}
		}
	}
}
int so(int x,int y){
	for(int i=1;i<=n;i++) dd[i]=Ma,us[i]=0;
	dd[x]=0;q.push(make_pair(0,x));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(us[x]) continue;
		us[x]=1;
		for(int i=hed[x];i;i=nxt[i]){
			int y=to[i],z=max(dd[x],edg[i]);
			if(z<dd[y]){
				dd[y]=z;
				q.push(make_pair(-dd[y],y));
			}
		}
	}
	return dd[y];
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);read(m);read(Q);
	for(int i=1;i<=m;i++){
		read(x);read(y);read(z);
		build(x,y,z);
		build(y,x,z);
	}
	for(int i=1;i<=n;i++) d[i]=Ma;
	for(int i=n;i>=1;i--){
		if(!f[i]) dj(i);
	}
	for(int i=1;i<=Q;i++){
		read(x);read(y);
		if(f[x]!=f[y]) printf("-1\n");
		else{
			if(t[x]!=t[y]) printf("%d\n",max(d[x],d[y]));
			else printf("%d\n",so(x,y));
		}
	}
	return 0;
}

